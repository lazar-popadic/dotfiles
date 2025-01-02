#!/bin/bash

# Path to the brightness file
BRIGHTNESS_FILE="/sys/class/backlight/amdgpu_bl0/brightness"

# Get the current brightness
current_brightness=$(cat "$BRIGHTNESS_FILE")

# Increment by 16
new_brightness=$((current_brightness + 16))

# Saturate at 255 if it exceeds
if [ "$new_brightness" -gt 255 ]; then
    new_brightness=255
fi

# Set the new brightness
echo "$new_brightness" > "$BRIGHTNESS_FILE"
