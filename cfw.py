#!/usr/bin/env python3


"""
clang-formatのラッパー。
カレントディレクトリから再帰的に検索してcpp/hにclang-formatをする。
これを使うにはclang-formatと3.5以上のPythonのランタイムが必要。

~ Koki Matsumura
"""

import glob
import os
import subprocess

cpp_list = glob.glob('./**/*.cpp', recursive=True)
header_list = glob.glob('./**/*.h', recursive=True)
cmd = "clang-format -style=file -i {}"

for cpp in cpp_list:
	print(cmd.format(cpp))
	subprocess.call(cmd.format(cpp), shell=True)

for header in header_list:
	print(cmd.format(header))
	subprocess.call(cmd.format(header), shell=True)
