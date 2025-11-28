<!-- Merge Request Template for Language Updates to Multiple Chips -->

## MR Description <!-- Mandatory -->
_Please provide a detailed description of the language updates being made across multiple chips. Highlight the scope of the changes and ideally, list the specific sections and chips that are affected. For example:_
- This MR is to wide update the word "pad" to "pin".
- Affected sections:
    - Section System Reset
    - Section Strapping Pins
- The following chips are affected:
    - ESP32
    - ESP32-S2

## Checklist <!-- Optional -->
- [ ] **MR Description:** clearly and accurately summarizes the purpose of the MR.
- [ ] **MR Title:** follows the conventions documented in GitLab Wiki -> Conventions -> MR Title Conventions.
- [ ] **MR Status:** is set to 'Draft' if it is a work in progress or to 'Ready' when the MR is complete and ready for review.
- [ ] **Release Notes:** follow the conventions documented in GitLab Wiki -> Conventions -> Release Notes Conventions.
- [ ] **Related Links:** Include Jira tasks, related MRs, or external links pertinent to the changes.
- [ ] **Commit Log:** is clean, concise, and structured for ease of understanding. For how to write commit message, see GitLab Wiki -> Conventions -> Commit Message Conventions.
- [ ] **Reviewers:** for the MR are assigned. For more information about reviewers, see GitLab Wiki -> Workflow: Language Update for Multiple Chips.
- [ ] **Full Pipeline:** has been run to make sure the other documents for other chips are not affected.

## Related <!-- Optional -->
- Add any DOC Jira tickets here with the format: Closes DOC-XXXX
- Mention any other related MRs or relevant links

## Release notes <!-- Mandatory -->
- Follow the conventions documented in GitLab Wiki -> Conventions -> Release Note Conventions. Example:
  - [ESP32/ESP32-S2] Reworded power management section
- Or put "no release notes" here without bullet "-"

<!-- Quick Actions (Do not touch the following lines below. They are default settings.)-->
/label ~"multiple-language-update"
/review @documentation/codeowners/esp-hardware-design-guidelines
