#!/bin/bash
echo Put your docker directory: 
read folder
cd $folder
sudo docker-compose exec workspace bash
