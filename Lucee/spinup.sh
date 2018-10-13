#!/bin/bash

while [ ! $# -eq 0 ]
do
  case "$1" in
    --help | -h)
      printf "USAGE: ./spinup.sh [OPTION]... \n"
      printf "Tears down existing HelloWorld infrastructure: Containers, Images \n"
      printf "Then builds HelloWorld back up from scratch. \n\n"
      printf "Optional arguments: \n"
      printf "  -u, --up         Tears down and rebuilds and bind mounts \n"
      printf "                   ./lucee/code/ to /var/www/ to allow for \n"
      printf "                   live code updates.\n"
      printf "  -h, --help        Print documentation to screen and exit. \n"
      printf "  -d, --down    Tears everything down without doing a rebuild.\n"      
      exit 1
      ;;
    --up | -u)
      # ---Spin down old stuff---
      # If lucee container is running, turn it off.
      running_lucee_instance=`docker ps | grep helloworld-lucee | wc -l`
      if [ $running_lucee_instance -gt "0" ]
      then
        echo "Current instance of helloworld-lucee running."
        echo "Spinning down now."
        docker kill helloworld-lucee
        echo "Spinning down complete."
        echo "-----------------------"
      fi

      # If turned off lucee container exists, remove it.
      existing_lucee_container=`docker ps -a| grep helloworld-lucee | grep Exit | wc -l`
      if [ $existing_lucee_container -gt "0" ]
      then
        echo "Container helloworld-lucee image exists."
        echo "Removing container now."
        docker rm helloworld-lucee
        echo "Removing container complete."
        echo "-----------------------"
      fi

      # If image for locallucee exists, remove it.
      existing_locallucee_image=`docker images | grep lucee_lucee-helloworld | wc -l`
      if [ $existing_locallucee_image -gt "0" ]
      then
        echo "Image lucee_lucee-helloworld exists."
        echo "Removing image now."
        docker rmi lucee_lucee-helloworld
        echo "Removing image complete."
        echo "-----------------------"
      fi

      # ---Spin up new stuff---

      # Rebuild images localdb and lucee
      echo "Building image lucee_lucee-helloworld."
      docker-compose build --no-cache
      echo "-----------------------"

      # Spin up helloworld-lucee container
      echo "Spinning up helloworld-lucee container"
      docker run -d -p 127.0.0.1:8888:8888 --restart always --name helloworld-lucee --mount type=bind,source=$(pwd)/lucee/code,target=/var/www lucee_lucee-helloworld:latest
      echo "-----------------------"

      exit 1
      ;;
    --down | -d)
      # ---Spin down old stuff---
      # If lucee container is running, turn it off.
      running_lucee_instance=`docker ps | grep helloworld-lucee | wc -l`
      if [ $running_lucee_instance -gt "0" ]
      then
        echo "Current instance of helloworld-lucee running."
        echo "Spinning down now."
        docker kill helloworld-lucee
        echo "Spinning down complete."
        echo "-----------------------"
      fi

      # If turned off lucee container exists, remove it.
      existing_lucee_container=`docker ps -a| grep helloworld-lucee | grep Exit | wc -l`
      if [ $existing_lucee_container -gt "0" ]
      then
        echo "Container helloworld-lucee image exists."
        echo "Removing container now."
        docker rm helloworld-lucee
        echo "Removing container complete."
        echo "-----------------------"
      fi

      # If image for locallucee exists, remove it.
      existing_locallucee_image=`docker images | grep lucee_lucee-helloworld | wc -l`
      if [ $existing_locallucee_image -gt "0" ]
      then
        echo "Image lucee_lucee-helloworld exists."
        echo "Removing image now."
        docker rmi lucee_lucee-helloworld
        echo "Removing image complete."
        echo "-----------------------"
      fi

      exit 1
      ;;
  esac 
  shift
done

printf "USAGE: ./spinup.sh [OPTION]... \n"
printf "Tears down existing HelloWorld infrastructure: Containers, Images \n"
printf "Then builds HelloWorld back up from scratch. \n\n"
printf "Optional arguments: \n"
printf "  -u, --up         Tears down and rebuilds and bind mounts \n"
printf "                   ./lucee/code/ to /var/www/ to allow for \n"
printf "                   live code updates.\n"
printf "  -h, --help        Print documentation to screen and exit. \n"
printf "  -d, --down    Tears everything down without doing a rebuild.\n"      
exit 1