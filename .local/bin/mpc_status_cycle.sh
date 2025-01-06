#!/bin/bash

# Store the current song info and time info
song_info=$(mpc current -f "%artist% - %album% - %title%        ")

# Set the maximum number of characters to display (e.g., 40)
max_chars=32

# Get the current counter value (this will be used to scroll the song info)
counter_file="/tmp/mpc_counter.txt"

# Initialize the counter if it doesn't exist
if [ ! -f "$counter_file" ]; then
    echo 0 > "$counter_file"
fi

# Read the current counter value
counter=$(cat "$counter_file")

# Calculate the length of the song info
song_length=${#song_info}

# Handle the case where song_length is less than max_chars
if [ "$song_length" -lt "$max_chars" ]; then
    max_chars=$song_length
fi

# Scroll the song info by using the counter to slice the string
scrolling_song_info="${song_info:$counter:$max_chars}"

# If the slice reaches the end, wrap it around by concatenating the start of the string
if [ ${#scrolling_song_info} -lt $max_chars ]; then
    scrolling_song_info="$scrolling_song_info${song_info:0:$((max_chars - ${#scrolling_song_info}))}"
fi

# Display the song info with time info
echo "󰝚 $scrolling_song_info"

# Increment the counter and reset if necessary (looping back to the start after the song length)
counter=$(( (counter + 1) % song_length ))

# Save the updated counter value
echo $counter > "$counter_file"
