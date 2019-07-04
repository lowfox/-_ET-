"""カレントディレクトリから再帰的に検索してcpp/hにclang-formatをする。"""

import glob
from datetime import datetime, timedelta, timezone
import os
import subprocess

BASE_DIRS = ["/hrp2/sdk/common/library", "/hrp2/sdk/workspace"]

# TODO: ミドルウェアのビルドが失敗する原因を突き止めて有効にする
# print('**** clang-format ****')
# for bd in BASE_DIRS:
#     cpp_list = glob.glob(bd+'/**/*.cpp', recursive=True)
#     header_list = glob.glob(bd+'/**/*.h', recursive=True)
#     cmd = "clang-format -style=file -i {}"

#     for cpp in cpp_list:
#         print(cmd.format(cpp))
#         subprocess.call(cmd.format(cpp), shell=True)

#     for header in header_list:
#         print(cmd.format(header))
#         subprocess.call(cmd.format(header), shell=True)


print('**** EV3 build ****')
ENV = "EV3_APP_NAME"
name = "app"
if ENV in os.environ:
    name = os.environ[ENV]


now = datetime.now(timezone(timedelta(hours=+9), 'JST'))
name += now.strftime('%m%d%H%M%S')
os.chdir("/hrp2/sdk/workspace")
subprocess.call("make app=RO2020EV3", shell=True)
if not os.path.exists("/gateway/production"):
    os.mkdir("/gateway/production")
subprocess.call("mv /hrp2/sdk/workspace/app /gateway/production/" + name, shell=True)