#!/bin/bash
song_info=$(mpc current -f "%artist% - %album% - %title% - ")
time_info=$(mpc status | grep -oP '(\d{1,2}:\d{2})/\d{1,2}:\d{2}' | head -n 1)
echo "󰝚 $song_info$time_info"
