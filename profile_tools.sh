#!/bin/sh

echo '>clang'
clang --version 
echo

#TODO change for nix
echo '>libc'
/lib/x86_64-linux-gnu/libc.so.6
echo

echo '>ldd'
ldd --version
echo

echo '>norminette'
norminette --version
echo
