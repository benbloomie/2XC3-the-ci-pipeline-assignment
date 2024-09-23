#!/bin/bash

git add quiz.c
git commit -m "$1"
git tag "$2"

git push origin main
git push origin "$2"
