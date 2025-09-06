#!/bin/sh

#!/bin/bash

# Check if PipeWire is running using pgrep
if pgrep -x "pipewire" ; then
    echo "PipeWire is running. Killing everything..."
    pkill pipewire
    pkill wireplumber
    pkill pipewirepulse
    pkill mpd
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
echo "Starting Music player daemon..."
mpd &
