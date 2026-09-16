CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
SEND_STRING_ENABLE = yes

SRC += features/swapper.c

# Optimisations
LTO_ENABLE = yes

# Features intentionally disabled.
TAP_DANCE_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
SPACE_CADET_ENABLE = no
REPEAT_KEY_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
