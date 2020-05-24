FROM devhub-docker.cisco.com/iox-docker/ir800/base-rootfs

COPY Proyect1 /opt/apps/
RUN opkg update
CMD ["/opt/Proyect1/main"]
