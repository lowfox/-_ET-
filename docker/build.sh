#!/bin/bash

# ==============================================================================
# コンテナ内で実行するシェルスクリプト
# ホストマシンで実行するようではないので注意！
# ==============================================================================

# clang-format
#./cfw.py

# ホストのlibrary/workspaceをコンテナ内に移動
rm -rf /hrp2/sdk/common/library/RyujiEv3
rm -rf /hrp2/sdk/workspace/RO2020EV3
#cp -r /myhost/library/RyujiEv3 /hrp2/sdk/common/library
#cp -r /myhost/workspace/RO2020EV3 /hrp2/sdk/workspace

echo this is build.sh
echo $(ls /)
#echo $(ls /myhost)
# アプリケーションのビルド
#cd /hrp2/sdk/workspace
#make app=RO2020EV3

# コンテナ内のビルド成果物を共有ボリュームに移動
#mv /hrp2/sdk/workspace/app /myhost/$RELEASE_DIR_NAME/$APP_NAME
