FROM debian:bullseye-slim

RUN apt-get --allow-releaseinfo-change update
RUN apt-get update && apt-get upgrade -y

# to run the c program
RUN apt-get install -y \
    build-essential \
    cmake \
    ninja-build \
    clang \
    valgrind 

# to make it smoother in github actions
RUN apt-get install -y \
    git \
    jq

RUN apt-get clean

RUN useradd -ms /bin/bash runner
USER runner
WORKDIR /home/runner
ENTRYPOINT ["bash"]
