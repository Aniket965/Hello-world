#!/bin/bash
services=(one two three)

# When the specified service does not have a init.d script use the following code
# Kill the process 
for i in "${services[@]}"
do
    echo "Killing the process of service: $i"
	pid=$(pidof $i)
	kill $pid
done


# When the specified service has a init.d script use the following code
# Stop the service 
for i in "${services[@]}"
do
    echo "Stopping the service: $i"
	service $i stop
done
