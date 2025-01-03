#!/usr/bin/sh
percentage=$(cat /sys/class/power_supply/BAT0/capacity)
status=$(cat /sys/class/power_supply/BAT0/status)
if [ "$status" = "Charging" ]; then
	battery_icon='󰂄'
elif [ "$percentage" -gt 95 ]; then	
 battery_icon='󰁹'
elif [ "$percentage" -gt 91 ]; then	
 battery_icon='󰂂'
elif [ "$percentage" -gt 81 ]; then	
 battery_icon='󰂁'
elif [ "$percentage" -gt 71 ]; then	
 battery_icon='󰂀'
elif [ "$percentage" -gt 61 ]; then	
 battery_icon='󰁿'
elif [ "$percentage" -gt 51 ]; then	
 battery_icon='󰁾'
elif [ "$percentage" -gt 41 ]; then	
 battery_icon='󰁽'
elif [ "$percentage" -gt 31 ]; then	
 battery_icon='󰁼'
elif [ "$percentage" -gt 21 ]; then	
 battery_icon='󰁻'
elif [ "$percentage" -gt 11 ]; then	
 battery_icon='󰁻'
elif [ "$percentage" -gt 5 ]; then	
 battery_icon='󰁺'
else
 battery_icon='󰂃'
fi

printf "%s %s" "$battery_icon" "$percentage"
