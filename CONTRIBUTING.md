# Contributing Guide ([中文](CONTRIBUTING_CN.md))

Thank you for your interest in contributing to the **ESP Hardware Design Guidelines** project!

We welcome community contributions—including bug fixes, documentation improvements, and feature suggestions. This document outlines the recommended process to help you contribute effectively.

> **Note:** This GitHub repository is a public mirror of Espressif's internal Git repository.
> Your Pull Request (PR) will be synchronized with our internal system for review, testing, and final approval before being merged publicly.


---

## Table of Contents

- [Before Contributing](#before-contributing)
- [Legal Requirements](#legal-requirements)
- [Contribution Scope](#contribution-scope)

- [Formatting Requirements](#formatting-requirements)

- [Getting Started](#getting-started)
  - [Branch Naming Conventions](#branch-naming-conventions)
  - [Commit Message Conventions](#commit-message-conventions)

- [Review Process](#review-process)
- [Issue Reporting](#issue-reporting)


---

## Before Contributing

Before submitting a PR, please ensure that:

- Your contribution is your own original work, or properly credited and licensed under terms compatible with this project (i.e., [Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)](https://creativecommons.org/licenses/by-sa/4.0/legalcode.en)).
- Do not submit any confidential, proprietary, or otherwise restricted content.
- Your content is clearly written in English or Chinese, with correct grammar and spelling.
- Your changes are logically grouped—avoid mixing unrelated fixes or updates in a single PR.
- You have reviewed existing [GitHub Issues](../../issues) and PRs to avoid duplication.

Not sure about something? Submit your PR anyway—we're happy to provide feedback.


## Legal Requirements

Before we can accept your contribution, you must sign the [Espressif Contributor Agreement](http://docs.espressif.com/projects/esp-idf/en/stable/contribute/contributor-agreement.html).
You will be prompted automatically when opening your first PR.


## Contribution Scope

```text
esp-hardware-design-guidelines/
├── docs/                  # Main documentation source files (.rst)
├── CONTRIBUTING.md        # Contribution guide (English)
├── CONTRIBUTING_CN.md     # Contribution guide (Chinese)
├── README.md              # Project overview and documentation links (English)
├── README_CN.md           # Project overview and documentation links (Chinese)
├── vale.ini               # Vale style checker configuration
```

This repository only accepts documentation-related contributions only. Specifically:

- Files under the `docs/` directory
- Root-level documentation files such as `README.md`, `README_CN.md`, `CONTRIBUTING.md`, and `CONTRIBUTING_CN.md`


---

## Formatting Requirements

1. **File Format**

   - All content under `docs/` must be written in reStructuredText (`.rst`) format.
   - Refer to the [reStructuredText Basic Syntax](https://docs.espressif.com/projects/esp-docs/en/latest/writing-documentation/basic-syntax.html) for key syntax rules.

2. **Building Documentation**

   - This project is built using [ESP-Docs](https://docs.espressif.com/projects/esp-docs/en/latest/index.html) (Espressif's Sphinx-based system).
   - Follow the instructions in [Building Documentation Locally](https://docs.espressif.com/projects/esp-docs/en/latest/building-documentation/building-documentation-locally.html) to preview your changes.

3. **Style Checking**

   - This project uses [Vale](https://vale.sh/) to ensure consistent writing style and grammar.
   - To run Vale locally:

     1. Install Vale by following the [official installation guide](https://vale.sh/docs/vale-cli/installation/).
     2. From the root directory of the repository (where `.vale.ini` is located), run:

        ```bash
        vale docs/
        ```

     This command checks all `.rst` files under the `docs/` directory according to project style rules.

> Before submitting a PR, it is recommended to verify that your changes pass Vale checks and that the documentation builds successfully.


---

## Getting Started

To contribute:

1. **Fork** the repository
2. **Create a new branch** from `master`
3. **Make your changes** following the conventions below
4. **Submit a PR** with a clear, descriptive title

> Following the branch and commit message conventions below will help speed up the review process.


### Branch Naming Conventions

Use one of the following prefixes to name your branch:

- `feature/` – New feature
- `bugfix/` – Bug fix
- `docs/` – Documentation updates

Use lowercase, present tense, and replace spaces with underscores.

**Examples**

- `feature/add_usb_layout_section`
- `bugfix/fix_dead_links`
- `docs/add_esp32p4_design_guidelines`


### Commit Message Conventions

Follow this structure for all commits:

`<Type>(<Chip>): <Description>`

- **Type**: `feature`, `bugfix`, or `docs`
- **Chip**: Affected SoC (`esp32`, `esp32s3`, etc.). Use:
  -  `/` for multiple chips (`esp32/esp32c3`)
  - `all` for universal changes
- **Description**: Capitalize the first word and use present tense

**Examples**

- `docs(esp32): Update strapping pin timing sequence`
- `bugfix(esp32/esp32c3): Fix broken layout diagram link`
- `feature(all): Add voltage routing recommendations`


---

## Review Process

1. Maintainers will review your PR and may request changes.
2. Once approved, your PR is synchronized with Espressif's internal Git system for automated testing.
3. After passing internal tests, your contribution will be published to the public GitHub repository on the next sync.


---

## Issue Reporting

To report issues or suggest improvements via [GitHub Issues](../../issues):

1. Use a clear and descriptive title
2. Provide reproduction steps or relevant context
3. Tag the affected SoC(s), if applicable


---

Thank you for helping improve the **ESP Hardware Design Guidelines**!
Your contributions support the developer community and help make Espressif's documentation better for everyone.
