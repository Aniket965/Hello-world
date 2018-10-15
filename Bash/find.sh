#!/bin/bash

# will find files modified within the last 20 days. Useful for housekeeping unwanted logs > certain age.

find . -type f -mtime -20
