#!/usr/bin/env bash

DATE=$(date +'%m/%d/%Y')

git add .

git commit -m "feat: add notes for $DATE"

git push origin main
