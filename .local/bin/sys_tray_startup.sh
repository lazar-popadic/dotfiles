#!/bin/bash

setxkbmap -layout "us,rs,rs" -variant "basic,basic,latin" -option grp:alt_shift_toggle &
ferdium &
nm-applet &
copyq &
dwmblocks &
