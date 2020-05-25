FROM ubuntu:latest
MAINTAINER Randald_Villegas randald1991@gmail.com
COPY src /opt/src/
RUN apt-get update && apt-get upgrade -y && apt install build-essential -y
RUN cd /opt/src && g++ -o main main.c

