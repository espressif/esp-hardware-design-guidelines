# 贡献指南 ([English](CONTRIBUTING.md))

感谢您有兴趣为 **ESP 硬件设计规范** 项目做出贡献！

我们欢迎社区各种形式的贡献，包括问题修复、文档完善以及功能建议。本指南旨在帮助您更高效地参与项目。

> **注意：** 此 GitHub 仓库是乐鑫内部 Git 仓库的公共镜像。
> 您提交的 Pull Request (PR) 将同步至我们的内部系统进行审核和测试，并在获得最终批准后合并到公共仓库。


---

## 目录

- [贡献前须知](#贡献前须知)
- [法律要求](#法律要求)
- [贡献范围](#贡献范围)

- [格式规范](#格式规范)

- [快速开始](#快速开始)
  - [分支命名规范](#分支命名规范)
  - [提交信息规范](#提交信息规范)

- [审核流程](#审核流程)
- [报告问题](#报告问题)


---

## 贡献前须知

在提交 PR 之前，请确保：

- 您的贡献内容为原创作品，或已正确标注来源且采用与本项目兼容的授权方式（即 [知识共享署名-相同方式共享 4.0 国际（CC BY-SA 4.0）许可协议](https://creativecommons.org/licenses/by-sa/4.0/legalcode.zh-hans)）。
- 请勿提交任何机密、专有或其他受限制公开的内容。
- 贡献内容采用中文或英文编写，语言表达准确清晰。
- 修改内容逻辑合理，避免在单个 PR 中包含无关变更。
- 已查阅并确认未重复提交相关 [GitHub Issues](../../issues) 和 PR。

如有疑问，也欢迎直接提交 PR，我们将为您提供反馈和建议。


## 法律要求

在我们接受您的贡献之前，需要您签署 [Espressif Contributor Agreement（乐鑫贡献者协议）](http://docs.espressif.com/projects/esp-idf/zh_CN/stable/contribute/contributor-agreement.html)。
首次提交 PR 时，系统会自动提示您完成该协议签署。


## 贡献范围

```text
esp-hardware-design-guidelines/
├── docs/                  # 主文档源文件 (.rst 格式)
├── CONTRIBUTING.md        # 贡献指南（英文）
├── CONTRIBUTING_CN.md     # 贡献指南（中文）
├── README.md              # 项目概述与文档链接（英文）
├── README_CN.md           # 项目概述与文档链接（中文）
├── vale.ini               # Vale 风格检查配置文件
```

本仓库仅接受与文档相关的贡献，具体包括：

- `docs/` 目录下的文档文件
- 仓库根目录下的文档文件，如 `README.md`、`README_CN.md`、`CONTRIBUTING.md` 和 `CONTRIBUTING_CN.md`


---

## 格式规范

1. **文档格式**

- `docs/` 目录下的所有文档均应使用 reStructuredText（`.rst`）格式编写
- 主要语法请参考 [reStructuredText 基础语法](https://docs.espressif.com/projects/esp-docs/en/latest/writing-documentation/basic-syntax.html)

2. **文档构建**

- 本项目采用 [ESP-Docs](https://docs.espressif.com/projects/esp-docs/en/latest/index.html) 构建（乐鑫基于 Sphinx 开发的文档系统）
- 本地预览可参考 [本地构建文档指南](https://docs.espressif.com/projects/esp-docs/en/latest/building-documentation/building-documentation-locally.html)

3. **风格检查**

- 本项目采用 [Vale](https://vale.sh/) 工具进行写作风格和语法检查
- 在本地运行 Vale 的步骤如下：

  1. 按照 [官方安装说明](https://vale.sh/docs/vale-cli/installation/) 安装 Vale
  2. 在仓库根目录（`.vale.ini` 文件所在目录）执行以下命令：

     ```bash
     vale docs/
     ```

  此命令将检查 `docs/` 目录下所有 `.rst` 文件的写作规范。

> 建议在提交 PR 前，确保文档可以正常构建并通过 Vale 风格检查。


---

## 快速开始

参与贡献的流程如下：

1. Fork 本仓库
2. 从 `master` 分支创建一个新的分支
3. 按照下文规范完成修改
4. 提交 PR，并撰写清晰描述的标题

> 遵循以下分支命名和提交信息规范有助于加快审核进程。


### 分支命名规范

请使用以下前缀之一为分支命名：

- `feature/` – 新功能
- `bugfix/` – 问题修复
- `docs/` – 文档更新

分支名应为小写，使用现在时，单词间用下划线连接。

**示例**

- `feature/add_usb_layout_section`
- `bugfix/fix_dead_links`
- `docs/add_esp32p4_design_guidelines`


### 提交信息规范

提交信息格式如下：

`<类型>(<芯片>): <描述>`

- **类型**：`feature`、`bugfix` 或 `docs`
- **芯片**：涉及的芯片系列（如 `esp32`、`esp32s3` 等）。使用：
  - `/` 表示多个芯片分割（如 `esp32/esp32c3`）
  - `all` 表示通用更改
- **描述**：首字母大写，使用现在时态

**示例**

- `docs(esp32): Update strapping pin timing sequence`
- `bugfix(esp32/esp32c3): Fix broken layout diagram link`
- `feature(all): Add voltage routing recommendations`


---

## 审核流程

1. 项目维护者将审核您的 PR， 并可能要求您做进一步的修改。
2. 审核通过后，PR 将同步至乐鑫内部 Git 系统进行测试。
3. 测试通过后，您的贡献将在下一次同步时发布至 GitHub 公共仓库。


---

## 报告问题

若需通过 [GitHub Issues](../../issues) 报告问题或提出建议：

1. 请使用清晰、描述明确的标题
2. 提供复现步骤或相关背景信息
3. 标注受影响的芯片系列（如适用）


---

感谢您愿意为 **ESP 硬件设计规范** 项目做出贡献！
您的贡献将帮助完善乐鑫文档，推动开发者社区的发展。
