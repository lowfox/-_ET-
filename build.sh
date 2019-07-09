#!/bin/bash
if [ $# -ne 2 ]; then
    echo "方法: ./build.sh [ローカルev3リポジトリの絶対パス] [生成するバイナリのプレフィックス]"
    echo "おじさんの例: ./build.sh /Users/cr0w/dev/src/github.com/ro-2020/ev3 kusoapp"
    exit 1
fi

echo "[Ads] GO IS SUPER NICE LANGUAGE..."
echo "[+] ローカルev3リポジトリの絶対パス=$1"
echo "[+] 生成するバイナリのプレフィックス=$2"

docker build . -t ev3dev:v1
docker run -e EV3_APP_NAME=$2 -v $1:/gateway ev3dev:v1
