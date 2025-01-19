#!/bin/sh

lxqt-policykit-agent &
nitrogen --restore &
picom -b &
audio_startup.sh &
sys_tray_startup.sh &
eval "$(ssh-agent -s)" &
gammastep -l 45.2:19.7 -t 5700:3600 -g 0.8 -m randr -v &
xrandr --output HDMI-A-0 --mode 1920x1080 -r 100 &
laptop_mon_startup.sh &
dunst &
setxkbmap -layout "us,rs,rs" -variant ",basic,latin" -option "grp:alt_shift_toggle"
