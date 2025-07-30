+++
title = "raid"
+++

# RAID

RAID (Redundant Array of Independent Disks) is a configuration method for storage devices to provide
data reliability with the cost of storing redundant information.

## RAID Levels

### RAID 0

RAID 0 uses striping with no mirroring.

### RAID 1

RAID 1 uses mirroring with no striping. A variation RAID1+0 uses mirroring with striping.

### RAID 5

RAID 5 uses block-interleaved distributed parity bits. In this configuration, blocks are striped
with one block used as the parity block.

### RAID 6

RAID 6 uses the P+Q redundancy scheme, where error-correcting codes are used in place of parity bits.

## Management Operations

For disks, writing a bit may succeed but reading the bit may fail. With RAID configurations, this failure
lead to failed recovery of lost blocks. To prevent this, disk scrubbing can run in the background, where
all disk blocks are read and checked for errors.

Using RAID, it is possible to swap out an existing device into another one without having the system notice
anything. This process is called hot swapping.
