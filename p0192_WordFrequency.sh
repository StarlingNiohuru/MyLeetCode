#!/usr/bin/env bash
grep -Eo "[a-z]+" words.txt | sort | uniq -c | sort -nr | awk '{print $2,$1}'
