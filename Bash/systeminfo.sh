#!/bin/bash
echo "IP Adresses:"
ip addr | grep inet
#alt
#ip addr | awk '{match($0,/[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+/); ip = substr($0,RSTART,RLENGTH); print ip}'

echo "__________________________________________________________________"

echo "CPU Info:"
cat /proc/cpuinfo | grep "model name"
cat /proc/cpuinfo | grep "cores"

echo "__________________________________________________________________"

echo "Memory Info:"
awk 'NR>=0&&NR<=3' "/proc/meminfo"

echo "__________________________________________________________________"

echo "Linux Version Info:"
cat /proc/version

echo "__________________________________________________________________"

echo "Kernel Information:"
cat /proc/sys/kernel/version

echo "__________________________________________________________________"

echo "File System Information:"
sudo fdisk -l
