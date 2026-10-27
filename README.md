# Vsc_F — VS Code 环境配置

这是一个开箱即用的 VS Code 多语言开发环境配置目录，已按本机环境适配：

| 工具 | 路径 |
| --- | --- |
| VS Code | `D:\vscode\Microsoft VS Code\Code.exe` |
| MinGW (gcc / g++ / gdb) | `D:\MinGW\mingw32\bin`（MinGW-W64 i686，32 位，GCC 16.2.0） |
| Node.js | `D:\Node.js` |
| Python | 系统 PATH 中的 `python`（Windows 应用商店别名，建议安装官方版） |

## 目录结构

```
D:\Vsc_F\
├─ .vscode\
│  ├─ settings.json          # 编辑器、终端、C/C++、Python 全局设置
│  ├─ launch.json            # F5 调试配置：C / C++ / Node.js / Python
│  ├─ tasks.json             # 编译、运行、npm 任务（Ctrl+Shift+B）
│  ├─ c_cpp_properties.json  # C/C++ IntelliSense 头文件路径
│  └─ extensions.json        # 推荐安装的扩展
├─ src\
│  ├─ main.cpp               # 示例程序，可直接 F5 调试
│  └─ 2048.c                 # C 语言 2048 游戏（原 2048_commented_fixed.txt）
├─ .editorconfig             # 跨编辑器统一缩进 / 换行风格
├─ .gitignore
├─ Vsc_F.code-workspace      # 工作区文件（双击打开）
└─ README.md
```

## 快速开始

1. 用 VS Code 打开本目录或双击 `Vsc_F.code-workspace`。
2. 首次打开时按提示安装推荐扩展（或 `Ctrl+Shift+P` → `Extensions: Show Recommended Extensions`）。
3. 打开 `src\main.cpp`，按 `F5` 即可编译并进入 gdb 调试。
4. 打开 `src\2048.c` 按 `F5` 可编译并调试 2048 游戏；也可在调试配置下拉框中选择
   `C 调试 (MinGW gdb)` 以 C17 标准编译。
5. 打开其他 C/C++ 文件时同样支持 `F5`，配置使用 `${file}` 动态匹配当前文件。

### 常用快捷键

| 操作 | 快捷键 |
| --- | --- |
| 编译当前文件（默认生成任务） | `Ctrl+Shift+B` |
| 调试当前文件 | `F5` |
| 不调试直接运行 | `Ctrl+F5` |
| 运行任务列表（含“运行当前程序”） | `Ctrl+Shift+P` → `Tasks: Run Task` |
| 打开设置 | `Ctrl+,` |

## 常见问题

### 运行 2048 时没有出现可操作的终端？

`2048.c` 通过 `conio.h` 的 `_getch()` 读取按键，并用 `system("cls")` 清屏，必须运行在真正的控制台窗口中。
VS Code 的“调试控制台”不支持键盘输入，所以 C/C++ 调试配置已设置 `"externalConsole": true`，
按 `F5` 后会弹出独立的控制台窗口。

如果仍然没有窗口：

1. 确认按 `F5` 时选择的是 `C 调试 (MinGW gdb)` 或 `C++ 调试 (MinGW gdb)`。
2. 检查 `launch.json` 中对应配置的 `externalConsole` 是否为 `true`。
3. 也可以先按 `Ctrl+Shift+B` 编译，再在底部终端执行 `.\src\2048.exe` 直接运行（不经过调试器，`_getch` 同样可用）。

## 自定义说明

- **修改 MinGW 路径**：同时修改 `settings.json` 中的 `terminal.integrated.env.windows`、
  `C_Cpp.default.compilerPath`，以及 `tasks.json`、`launch.json`、`c_cpp_properties.json` 中的路径。
- **修改 Node.js 路径**：修改 `settings.json` 中 `terminal.integrated.env.windows` 的 `PATH`。
- **切换 C/C++ 标准**：修改 `settings.json` 的 `C_Cpp.default.cppStandard` 和
  `c_cpp_properties.json` 的 `cppStandard`；编译参数在 `tasks.json` 的 `-std=` 处。
- **Python 调试**：依赖 `ms-python.python` / `ms-python.debugpy` 扩展。当前机器上的
  `python.exe` 来自 Windows 应用商店别名，如需完整功能请安装 python.org 官方版本。
- **设置只对当前项目生效**：本目录的配置放在 `.vscode\` 中，仅在本文件夹（或工作区）打开时生效，
  不会污染 VS Code 全局设置。

## 已验证

- `settings.json`、`launch.json`、`tasks.json`、`c_cpp_properties.json`、`extensions.json`
  均为合法 JSON，可被 VS Code 直接读取。
