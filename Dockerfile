FROM ubuntu:latest

# Install dependencies
RUN apt-get update && apt-get install -y \
    bison \
    build-essential \
    flex \
    gawk \
    git \
    gperf \
    help2man \
    libncurses5-dev \
    libtool-bin \
    texinfo \
    unzip \
    vim \
    wget 

# Create a non-root user
RUN useradd -ms /bin/bash ctnguser
WORKDIR /home/ctnguser

# Switch to the non-root user
USER ctnguser

# Download and extract Crosstool-NG
RUN git clone https://github.com/crosstool-ng/crosstool-ng.git && \
    cd crosstool-ng && \
    git checkout crosstool-ng-1.24.0 && \
    ./bootstrap && \
    ./configure --prefix=/home/ctnguser/ct-ng && \
    make && \
    make install

# Add Crosstool-NG binaries to PATH
ENV PATH="/home/ctnguser/ct-ng/bin:${PATH}"

# Create a directory for the toolchain
WORKDIR /home/ctnguser

# Copy the configuration file
COPY defconfig defconfig

RUN ct-ng defconfig defconfig

# Build the toolchain
# RUN ct-ng build

# build the project
# COPY . /pistats

# ENV CC=arm-linux-gnueabihf-gcc
# ENV CXX=arm-linux-gnueabihf-g++

# RUN mkdir -p /pistats/build
# WORKDIR /pistats/build
# RUN cmake .. && make
