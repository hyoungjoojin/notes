+++
title = "cli"
+++

# Docker CLI Cheatsheet

## Managing Images

```bash
docker pull IMAGE_NAME

docker run \
  [-d] \
  [--memory="256m" --cpus=".5"] \
  [-p LOCAL_PORT:IMAGE_PORT] \
  [-v NAMED_VOLUME:CONTAINER_PATH] \
  IMAGE_NAME
```

## Managing Containers

```bash

```

## Managing Volumes

```bash
docker create volume VOLUME_NAME
docker volume ls
docker volume inspect VOLUME_NAME
docker volume rm VOLUME_NAME
docker volume prune # Remove all unused volumes
```

## Docker Compose

```bash
docker compose build
docker compose start
docker compose stop

docker compose \
  [-p PROJECT_NAME] \
  up -d

docker compose ls
docker compose ps
docker compose rm
docker compose down
docker compose logs
docker compose exec CONTAINER_NAME bash
```
