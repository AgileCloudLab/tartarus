#!/bin/bash

# Install clang
wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -
sudo apt-add-repository "deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-6.0 main"
sudo apt-get update
sudo apt-get install -y clang-6.0
# see more at: http://apt.llvm.org/
# Also at: https://blog.kowalczyk.info/article/k/how-to-install-latest-clang-6.0-on-ubuntu-16.04-xenial-wsl.html

# Install lint tools
sudo apt-get install -y cppcheck
sudo apt-get install -y clang-tidy
sudo apt-get install -y clang-format

# Dependencies for Google Test library
sudo apt-get install -y autotools
sudo apt-get install -y libtool

sudo apt-get install -y doxygen
sudo pip install pylint

# Install shellcheck
sudo apt-get install -y xz-utils
cd /tmp || exit 1
wget "https://storage.googleapis.com/shellcheck/shellcheck-stable.linux.x86_64.tar.xz"
tar --xz -xvf shellcheck-stable.linux.x86_64.tar.xz
sudo cp shellcheck-stable/shellcheck /usr/bin/
