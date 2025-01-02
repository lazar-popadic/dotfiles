#!/bin/bash

# Path to the brightness file
BRIGHTNESS_FILE="/sys/class/backlight/amdgpu_bl0/brightness"

# Get the current brightness
current_brightness=$(cat "$BRIGHTNESS_FILE")

if [ "$current_brightness" -eq 255 ]; then
    current_brightness=256
fi

# Decrement by 16
new_brightness=$((current_brightness - 16))

# Saturate at 0
if [ "$new_brightness" -lt 0 ]; then
    new_brightness=0
fi

# Set the new brightness
echo "$new_brightness" > "$BRIGHTNESS_FILE"
