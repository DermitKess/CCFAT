
# CCFAT - Clipboard Copy for Files as Text

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

A simple utility to copy file contents to clipboard in Linux (supports both X11 and Wayland).

## Features

- Copies file contents directly to clipboard
- Automatically detects X11 or Wayland environment
- Lightweight (single C++ file)
- No GUI dependencies

## Installation

1. Clone the repository:
```shell
git clone https://github.com/DermitKess/ccfat.git
cd ccfat
```
2. Install dependencies:
```shell
sudo pacman -S xclip wl-clipboard gcc  # Arch Linux
sudo apt install xclip wl-clipboard g++ # Debian/Ubuntu
```
3. Compile and install:
```shell
make
sudo make install
```
(or manually via g++ -o ccfat ccfat.cpp + copy to /usr/local/bin)
