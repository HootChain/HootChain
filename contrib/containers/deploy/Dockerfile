FROM phusion/baseimage:focal-1.0.0
LABEL maintainer="Hootchain Developers <dev@hoot.org>"
LABEL description="Dockerised HootchainCore, built from Travis"

ARG USER_ID
ARG GROUP_ID

ENV HOME /home/hoot

# add user with specified (or default) user/group ids
ENV USER_ID ${USER_ID:-1000}
ENV GROUP_ID ${GROUP_ID:-1000}
RUN groupadd -g ${GROUP_ID} hoot && \
    useradd -u ${USER_ID} -g hoot -s /bin/bash -m -d /home/hoot hoot && \
    mkdir /home/hoot/.hootcore && \
    chown ${USER_ID}:${GROUP_ID} -R /home/hoot

COPY bin/* /usr/local/bin/

RUN chmod a+x /usr/local/bin/*

USER hoot

VOLUME ["/home/hoot"]

EXPOSE 9968 9969 19968 19969

WORKDIR /home/hoot
