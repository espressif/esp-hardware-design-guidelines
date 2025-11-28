<!-- Merge Request Template for New Hardware Design Guidelines -->

## MR Description <!-- Mandatory -->
Provide background information for this new chip. For example:
This MR is to provide hardware design guidelines for ESP32-P4:
- Chip Status:
    - This chip is in sample phase, or
    - This chip is in mass production.
- Document Status:
    - This is a totally new hardware design guidelines, or
    - This hardware design guidelines is based on ESP32-C6.
- ECO Status:
    - No ECO, or
    - This hardware design guidelines is based on ECO1.

## Checklist <!-- Optional -->
- [ ] **MR Description:** provides key information for reviewers and approvers to do their review.
- [ ] **MR Title:** follows the conventions documented in GitLab Wiki -> Conventions -> MR Title Conventions.
- [ ] **MR Status:** Change this MR to 'Draft' if not ready for review or 'Ready' if it is complete and awaiting approval.
- [ ] **Release Notes:** follow the conventions documented in GitLab Wiki -> Conventions -> Release Notes Conventions.
- [ ] **Reviewers:** for the MR are assigned. For more information about reviewers, see GitLab Wiki -> Workflow: Language Update for Multiple Chips.
- [ ] **Related Links:** Include Jira tasks, related MRs, or external links pertinent to the changes.
- [ ] **Commit Log:** is clean, concise, and structured for ease of understanding. For how to write commit message, see GitLab Wiki -> Conventions -> Commit Message Conventions.
- [ ] **Full Pipeline:** has been run to make sure the other documents for other chips are not affected.

## Related <!-- Optional -->
- Add any DOC Jira tickets here with the format: Closes DOC-XXXX
- Mention any other related MRs or relevant links

## Release notes <!-- Mandatory -->
- Follow the conventions documented in GitLab Wiki -> Conventions -> Release Note Conventions. Example:
    - [ESP32-P4] Released the initial version of ESP32-P4 Hardware Design Guidelines

<!-- Quick Actions (Do not touch the following lines below. They are default settings.)-->
/label ~"new-hdg"
/review @documentation/codeowners/hw @documentation/codeowners/esp-hardware-design-guidelines
