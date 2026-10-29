CC       = gcc
CFLAGS   = -std=c11 -Wall -Wextra -Isrc
SRC      = $(wildcard src/*.c)
OBJ      = $(SRC:.c=.o)
TARGET   = game.exe

# 测试：除 main.c 外的源码 = 可被测试的游戏逻辑
LIB_SRC  = $(filter-out src/main.c, $(SRC))
LIB_OBJ  = $(LIB_SRC:.c=.o)
TEST_SRC = $(wildcard tests/*.c)
TEST_BIN = test_runner.exe

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_BIN): $(TEST_SRC) $(LIB_OBJ)
	$(CC) $(CFLAGS) $(TEST_SRC) $(LIB_OBJ) -o $@

test:
ifeq ($(strip $(TEST_SRC)),)
	@echo "没有测试文件，请先在 tests/ 下建 *.c"
	@exit 1
else
	@$(MAKE) $(TEST_BIN)
	./$(TEST_BIN)
endif

clean:
	rm -f $(OBJ) $(TEST_BIN)
