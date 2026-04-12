+++
title = "docker"
+++

# Docker

## Troubleshooting

### Docker Linux

- How to change the default data storage location for Docker on Linux.
  - This has to be done if the default location is running out of space or if
    the mounted drive is not performing well.
  1. Create or edit the file `/etc/docker/daemon.json` and add the following
     content. The value for `data-root` should be the path to the new location
     where you want Docker to store its data.

     ```json
     {
       "data-root": "$PATH_TO_NEW_LOCATION"
     }
     ```

  2. Migrate existing Docker data to the new location and restart the Docker
     service.

     ```bash
     sudo systemctl stop docker
     sudo rsync -aP /var/lib/docker $PATH_TO_NEW_LOCATION
     sudo systemctl start docker
     ```

  3. Check that the new location is being used by running `docker info`.

  4. When using the `containerd` runtime, the `containerd` data can be moved to
     a new location as well. The location for the `containerd` data should not
     be the same as the Docker data location.

     ```toml
     version = 2
     root = "$PATH_TO_NEW_LOCATION"
     ```
