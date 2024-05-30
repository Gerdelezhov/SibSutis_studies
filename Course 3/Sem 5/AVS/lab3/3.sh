#!/bin/bash

sudo docker build -t nginx .
sudo docker run -d -p 8080:80 --name nginx-container nginx
sudo apt-get install apache2-utils 
sudo ab -n 100000 -c 1000 http://localhost:8080/