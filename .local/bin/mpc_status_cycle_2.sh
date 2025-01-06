#!/bin/bash

# Store the current song info and time info
song_info=$(mpc current -f "%artist% - %album% - %title%            ")

# Set the maximum number of characters to display (e.g., 32)
max_chars=36

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

# Start the scrolling loop
while true; do
    # Scroll the song info by using the counter to slice the string
    scrolling_song_info="${song_info:$counter:$max_chars}"

    # If the slice reaches the end, wrap it around by concatenating the start of the string
    if [ ${#scrolling_song_info} -lt $max_chars ]; then
        scrolling_song_info="$scrolling_song_info${song_info:0:$((max_chars - ${#scrolling_song_info}))}"
    fi

    # Save the output for dwmblocks
    echo "󰝚 $scrolling_song_info" > /tmp/mpc_status_output

    # Send a signal to dwmblocks to refresh the status
    pkill -RTMIN+13 dwmblocks

    # Increment the counter and reset if necessary (looping back to the start after the song length)
    counter=$(( (counter + 1) % song_length ))

    # Save the updated counter value
    echo $counter > "$counter_file"

    # Sleep for a short period to control the scrolling speed
    sleep 0.25  # Adjust the sleep time for faster/slower scrolling
done
