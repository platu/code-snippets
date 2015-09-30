#!/bin/bash

find [0-9]*_* -type f -iname "*.cc" -exec vim -c hardcopy -c quit {} \;
