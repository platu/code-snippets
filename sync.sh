#!/bin/bash

rsync -avh --numeric-ids --delete --exclude .git --exclude .gitignore --exclude *.o ~/code-snippets/ ~/Dropbox/PROG-IUT/code-snippets/
