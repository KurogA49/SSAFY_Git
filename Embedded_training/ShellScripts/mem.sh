#! /bin/bash

mf=$(cat /proc/meminfo | grep MemFree)
mt=$(cat /proc/meminfo | grep MemTotal)

echo "meminfo1: $mf"
echo "meminfo2: $mt"
