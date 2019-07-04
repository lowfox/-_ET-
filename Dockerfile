FROM ubuntu:18.04

RUN apt-get update && apt-get install -y \
    wget \
    sudo \
    unzip \
    gcc-arm-none-eabi \
    libboost-all-dev \
    clang-format \
    python3 \
&& apt-get clean \
&& rm -rf /var/lib/apt/lists/* \
&& wget http://www.toppers.jp/download.cgi/ev3rt-beta7-2-release.zip \
&& unzip /ev3rt-beta7-2-release.zip \
&& tar Jxfv /ev3rt-beta7-2-release/hrp2.tar.xz

WORKDIR /hrp2/cfg
RUN make \
&& echo 'APPL_DIR += $(foreach dir,$(shell find $(APPLDIR) -type d),$(dir))' >> /hrp2/sdk/common/Makefile.prj.common

COPY docker/home /home
COPY library/RyujiEv3 /hrp2/sdk/common/library/RyujiEv3
COPY workspace/RO2020EV3 /hrp2/sdk/workspace/RO2020EV3

CMD ["python3", "/home/build.py"]