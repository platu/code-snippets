#!/bin/bash

rsync -avh --numeric-ids --delete --exclude-from=sync-exclude.txt ~/code-snippets/ ~/Dropbox/PROG-IUT/code-snippets/
