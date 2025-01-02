#!/bin/bash

PARTITION="/dev/nvme0n1p5"
MOUNT_POINT="/home/lazar/Storage"

# Ensure the mount point exists
mkdir -p "$MOUNT_POINT"

# Check and repair the NTFS partition if needed
ntfsfix "$PARTITION"

# Mount the partition
mount -t ntfs-3g "$PARTITION" "$MOUNT_POINT"

# Exit the script (the service will stop after running this)
echo "Exiting"
exit 0
