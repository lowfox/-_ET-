#!/bin/bash

EV3_MY_APP_NAME="app"
if [ $# -ne 1 ]; then
    echo "======================================================================"
    echo "| バイナリのプレフィックスをappから変更することもできます"
    echo "| 方法: ./build.sh [バイナリのプレフィックス]"
    echo "| 例: バイナリのプレフィックスをkusoappにする -> ./build.sh kusoapp"
    echo "======================================================================"
else
    EV3_MY_APP_NAME=$1
fi

echo "[*] 生成するバイナリのプレフィックス=$EV3_MY_APP_NAME"

if [ "$(uname)" == 'Darwin' ]; then
  docker build . -t ev3dev:v1
  docker run --rm=true -e EV3_APP_NAME=$EV3_MY_APP_NAME -v $(pwd):/gateway ev3dev:v1
else
  docker build . -t ev3dev:v1
  docker run --rm=true -e EV3_APP_NAME=$EV3_MY_APP_NAME -v /$PWD:/gateway ev3dev:v1
fi
