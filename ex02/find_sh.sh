#!/usr/bin/bash
find . -name "*.sh" -type f | xargs basename -s .sh
