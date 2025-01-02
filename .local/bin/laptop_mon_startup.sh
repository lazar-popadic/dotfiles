#!/bin/bash

# Check if HDMI-A-0 is connected
if xrandr | grep "HDMI-A-0 connected"; then
    # Run the script when HDMI-A-0 is connected
    xrandr --output eDP --off
fi
