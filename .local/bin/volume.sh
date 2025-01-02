#!/usr/bin/bash

volume=$(pamixer --get-volume)
is_muted=$(pamixer --get-volume-human)

#if (( $is_muted == muted )); then

if [ "$is_muted" == "muted" ]; then
	icon="󰝟"
else
if (( $volume > 59 )); then
    icon="󰕾"
elif (( $volume > 19 )); then
    icon="󰖀"
else (( $volume > 0 ));
    icon="󰕿"
fi
fi

printf "%s %s" "$icon" "$(pamixer --get-volume-human)"

