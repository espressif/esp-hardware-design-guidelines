# The content below is copied from the esp-dl repo and modified acc to the esp-hdg repo

from esp_docs.conf_docs import *  # noqa: F403,F401

languages = ['en', 'zh_CN']
idf_targets = ['esp32', 'esp32s2', 'esp32s3', 'esp32c3', 'esp32c6', 'esp32h2', 'esp32c2', 'esp32c5', 'esp32p4', 'esp32c61']
extensions += ['sphinx_copybutton',
               'linuxdoc.rstFlatTable',
               # Note: order is important here, events must
               # be registered by one extension before they can be
               # connected to another extension
               'linuxdoc.rstFlatTable',
               'esp_docs.esp_extensions.dummy_build_system',
               ]

GENERAL_DOCS = ['schematic-checklist.rst',
                'pcb-layout-design.rst',
                'download-guidelines.rst']

ESP32P4_DOCS = ['schematic-checklist-esp32p4.rst',
                'pcb-layout-design-esp32p4.rst',
                'hardware-development-esp32p4.rst']

conditional_include_dict = {'esp32':GENERAL_DOCS,
                            'esp32s2':GENERAL_DOCS,
                            'esp32s3':GENERAL_DOCS,
                            'esp32c3':GENERAL_DOCS,
                            'esp32c6':GENERAL_DOCS,
                            'esp32h2':GENERAL_DOCS,
                            'esp32c2':GENERAL_DOCS,
                            'esp32c5':GENERAL_DOCS,
                            'esp32c61':GENERAL_DOCS,
                            'esp32p4':ESP32P4_DOCS
                            }

# link roles config
github_repo = 'espressif/esp-hardware-design-guidelines'

# context used by sphinx_idf_theme
html_context['github_user'] = 'espressif'
html_context['github_repo'] = 'esp-hardware-design-guidelines'

html_static_path = ['../_static']
html_css_files = ['js/chatbot_widget.css']

# Extra options required by sphinx_idf_theme
project_slug = 'esp-hardware-design-guidelines'

# Contains info used for constructing target and version selector
# Can also be hosted externally, see esp-idf for example
versions_url = './_static/docs_version.js'

# Final PDF filename will contains target and version
pdf_file_prefix = u'esp-hardware-design-guidelines'

# disable the check for link anchors
linkcheck_anchors = False

linkcheck_exclude_documents = ['index',  # several false positives due to the way we link to different sections
                               ]

# Measurement ID for Google Analytics
google_analytics_id = 'G-RP8SCKE54N'
