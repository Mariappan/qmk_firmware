
# Blackpill handwired

Keyboards using a BlackPill controller (generic Chinese STM32F103C8T6) and based on the [KC64 of Xydane](https://github.com/Xydane/qmk_firmware).

Keyboard Maintainer: [Mariappan Ramasamy](https://github.com/mariappan)
Hardware Supported: Blackpill STM32F103C8T6
Hardware Availability: Everywhere

Make example for Atreus50 (after setting up your build environment):

    make handwired/blackpill/atreus50:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

Read everything before using it.

## Introduction

First of all thanks to [Xydane](https://github.com/Xydane) at [GeekHack](https://geekhack.org/) for his advice and his repository, without it you couldn't be reading this.

## Adding layouts and revisions

If you want to create new layouts just add them to the keymaps folder. If you prefer to develop a more complex revision just copy the atreus50 folder, rename it and create a new keymap in /keymap.c (I tried to divide the project even more but it didn't worked).

It also uses:
PC13: Caps Lock led.
