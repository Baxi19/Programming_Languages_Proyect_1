FROM devhub-docker.cisco.com/iox-docker/ir800/base-rootfs

COPY apps /opt/apps/
RUN opkg update
CMD ["/opt/apps/main"]
#FROM ubuntu

#MAINTAINER randald <randald1991@gmail.com>

#RUN apt-get update

#CMD["ECHO", "Hello World..! from docker image.."]