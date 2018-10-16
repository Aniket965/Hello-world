#!/bin/bash

echo 'Script for permanent mounting (fstab) a network share.'
sleep 1
read -p 'Address of the server:' -r server
read -p 'Mountpoint on the server:' -r mount
read -p 'Local location where to mount the share:' local
read -p 'User for authentication:' -r user
read -p 'Password for that user:' -r password
echo 'Information gathered. Starting mount sequence.'
sleep 1
echo 'Installation of cifs-utils Samba Client'
sleep 1
sudo apt-get -y install cifs-utils
sleep 1
echo "Creating the local mount point on: $local"
sleep 1
mkdir -r $local
sleep 1
echo "Connecting to $server"
sleep 1
echo 'Enter the password for the user'
sleep 1
sudo mount -t cifs //$server/$mount $local -o user=$user
sleep 1
echo 'Connection established'
echo 'Writing mount to /etc/fstab'
sleep 1
sudo echo "//$server/$mount $local cifs username=$user,password=$password 0 0" >> /etc/fstab
sleep 1
echo 'Mount sequence finished'
exit 0
