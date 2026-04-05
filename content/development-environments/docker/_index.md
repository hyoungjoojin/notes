+++
title = "docker"
+++

# Docker

## Docker Linux

### Guides

- How to change the default data storage location for Docker on Linux.
  1. Create or edit the file `/etc/docker/daemon.json` and add the following
     content. The value for `data-root` should be the path to the new location
     where you want Docker to store its data.

     ```json
     {
       "data-root": "/mnt/docker"
     }
     ```

  2. Migrate existing Docker data to the new location.

     ```bash
     sudo systemctl stop docker
     sudo rsync -aP /var/lib/docker /mnt/docker
     ```
