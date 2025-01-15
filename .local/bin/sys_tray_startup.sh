#!/bin/bash

setxkbmap -layout "us,rs,rs" -variant "basic,basic,latin" -option grp:alt_shift_toggle &
ferdium &
nm-applet &
copyq &
#dwmblocks &
if pgrep -x "bar_loop" ; then
    echo "bar_loop is running. Killing it..."
    pkill bar_loop
fi
bar_loop &
