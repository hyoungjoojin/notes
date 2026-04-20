+++
title = "linux"
+++

# Linux

## External Drives

### Commands

- `lsblk`: List block devices and their mount points.
- `mount`: Display currently mounted filesystems.

  ```bash
  mount -a # Mount all filesystems mentioned in /etc/fstab
  ```

## Troubleshooting

- How to change the file system of an external drive.
  1. Unmount the drive using `umount /dev/sda1`.
  2. Format the drive with the desired file system.

     ```bash
     sudo mkfs.ext4 /dev/sda1 # Format with ext4
     ```

  3. Update `/etc/fstab` with the new file system type.
  4. Mount the drive using `mount -a`.

- How to mount an external drive on a fixed mount point.
  1. Identify the drive using `lsblk -f`.
  2. Create a mount point (ex. `/mnt/ssd`).
  3. Open and edit the file `/etc/fstab` and add the entry for the drive.
     - The UUID is the value in the UUID column from the `lsblk -f` output.
     - The filesystem type is the value in the FSTYPE column from the `lsblk -f`
       output.

     ```bash
     UUID=1234-5678 /mnt/ssd ext4 rw,relatime,nofail,noauto 0 2
     ```

  4. Save the file and run `mount -a` to mount the drive.
