#!/usr/bin/env python3

"""
clang-formatのラッパー
~~~~~~~~~~~~~~~~~~~~~~~
コンテナ内で実行するシェルスクリプト
ホストマシンで実行するようではないので注意
"""

import glob
import os
import subprocess

lib_cpp_list = glob.glob('/myhost/library/**/*.cpp', recursive=True)
lib_header_list = glob.glob('/myhost/library/**/*.h', recursive=True)
ws_cpp_list = glob.glob('/myhost/workspace/**/*.cpp', recursive=True)
ws_header_list = glob.glob('/myhost/workspcase/library/**/*.h', recursive=True)
cmd = "clang-format -style=file -i {}"

for cpp in lib_cpp_list:
  print(cmd.format(cpp))
  subprocess.call(cmd.format(cpp), shell=True)

for cpp in ws_cpp_list:
  print(cmd.format(cpp))
  subprocess.call(cmd.format(cpp), shell=True)

for header in lib_header_list:
  print(cmd.format(header))
  subprocess.call(cmd.format(header), shell=True)

for header in ws_header_list:
  print(cmd.format(header))
  subprocess.call(cmd.format(header), shell=True)
