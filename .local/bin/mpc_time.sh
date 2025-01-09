#!/bin/bash

time_info=$(mpc status | grep -oP '(\d{1,2}:\d{2})/\d{1,2}:\d{2}' | head -n 1)
formatted_time="[${time_info//\// \/ }]"  # Note the space after the slash
echo "$formatted_time"
