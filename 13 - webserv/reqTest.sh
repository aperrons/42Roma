#!/bin/bash

echo -n "Insert host: "
read host

echo -n "Insert attempts: "
read attempts

for ((i = 1; i <= attempts; i++))
do
	curl --no-keepalive --output - $host
done
