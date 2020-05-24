FROM ubuntu:latest
MAINTAINER Randald_Villegas randald1991@gmail.com
COPY Proyect1 /opt/apps/
RUN apt-get update
CMD ["/opt/Proyect1/main"]
