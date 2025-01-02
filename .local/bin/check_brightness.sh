#!/usr/bin/sh
brightness=$(cat /sys/class/backlight/amdgpu_bl0/brightness)
section=$(( (brightness * 7) / 255 ))
if [ "$section" -lt 1 ]; then	
 icon='󰃚'
elif [ "$section" -lt 2 ]; then	
 icon='󰃛'
elif [ "$section" -lt 3 ]; then	
 icon='󰃜'
elif [ "$section" -lt 4 ]; then	
 icon='󰃝'
elif [ "$section" -lt 5 ]; then	
 icon='󰃞'
elif [ "$section" -lt 6 ]; then	
 icon='󰃟'
else
 icon='󰃠'
fi

printf "%s %s" "$icon" "$brightness"
