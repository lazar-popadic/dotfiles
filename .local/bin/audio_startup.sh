#!/bin/sh

#!/bin/bash

# Check if PipeWire is running using pgrep
if pgrep -x "pipewire" ; then
    echo "PipeWire is running. Killing it..."
    pkill pipewire
    pkill wireplumber
    pkill pipewirepulse
fi
sleep 1
dbus-run-session pipewire &
echo "Starting PipeWire..."
sleep 1
echo "Starting Wireplumber..."
wireplumber &
sleep 1
echo "Starting PipeWire-pulse..."
pipewire-pulse &
sleep 1
pkill -RTMIN+10 dwmblocks
