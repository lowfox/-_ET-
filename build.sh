#!/bin/bash
if [ $# -ne 2 ]; then
    echo "usage: ./build.sh [local ev3 repo abs path] [EV3_APP_NAME]"
    echo "og3's example: ./build.sh /Users/cr0w/dev/src/github.com/ro-2020/ev3 kusoapp"
    exit 1
fi

echo "[Ads] GO IS SUPER NICE LANGUAGE..."
echo "[+] your-ev3-repository-abs-path=$1"
echo "[+] EV3_APP_NAME=$2"

docker build . -t ev3dev:v1
docker run -e EV3_APP_NAME=$2 -v $1:/gateway -it ev3dev:v1
