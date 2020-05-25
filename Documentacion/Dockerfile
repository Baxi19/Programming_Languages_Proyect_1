FROM ubuntu:latest
MAINTAINER Randald_Villegas randald1991@gmail.com
COPY src /opt/apps/
RUN apt-get update  && apt install build-essential -y && cd opt/apps && g++ -o main main.c
CMD ["/opt/apps/main"]

