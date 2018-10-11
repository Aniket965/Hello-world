#This is a script for reploy an docker service 
#!/bin/bash
Sudo docker service create --name mycluster --hostname mycluster --replicas 1 --publish 80:80 imagename:latest