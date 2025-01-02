#!/bin/bash

# Function to get current keyboard layout
get_keyboard_layout() {
    setxkbmap -v | awk -F '+' '/symbols/ {print $2}'
}

# Get current keyboard layout
layout=$(setxkbmap -v | awk -F '+' '/symbols/ {print $2}')

# Depending on the keyboard layout, run one of three commands
case $layout in
    "us")
	setxkbmap rs
        ;;
    "rs")
	setxkbmap rs -variant latin
        ;;
    "rs(latin)")
	setxkbmap us
        ;;
esac
