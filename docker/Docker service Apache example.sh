#This is an example of httpd apache service creation script in swarm mode.
docker service create --name httpdcluster--hostname httpdnode--replicas 3 --publish 80:80 httpd



