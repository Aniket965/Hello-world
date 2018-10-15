#!/bin/sh

# To clean the docker images with repository NONE, created when you create a new image from a previous repository

isDifferentAdress=true
if [ -z "$1" ]; then
        isDifferentAdress=false
fi

if $isDifferentAdress ;then

docker_images_to_del=$(docker -H $1 images |grep none|sed 's/\(\s\+\)/ /g'|cut -f3 -d" ")
else


docker_images_to_del=$(docker images |grep none|sed 's/\(\s\+\)/ /g'|cut -f3 -d" ")
fi
docker rmi $docker_images_to_del
~

