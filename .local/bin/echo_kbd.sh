#!/bin/bash

# Get current keyboard layout
layout=$(xkblayout-state print "%s(%e)")

# Depending on the keyboard layout, run one of three commands
case $layout in
	"us(basic)")
        	echo "󰥻 eng"
        ;;
	"rs(basic)")
		echo "󰥻 срб"
        ;;
    	"rs(latin)")
        	echo "󰥻 srb"
        ;;
esac
