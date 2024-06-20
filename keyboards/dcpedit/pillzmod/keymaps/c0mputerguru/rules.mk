AUTO_SHIFT_ENABLE = yes
CAPS_WORD_ENABLE = yes

VIA_ENABLE = yes
VIAL_ENABLE = yes
VIAL_INSECURE = yes

# Disable QMK settings in Vial to support retro shift
QMK_SETTINGS = no

SRC += features/layer_lock.c
SRC += features/select_word.c
