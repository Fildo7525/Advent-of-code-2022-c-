#!/bin/bash
cd build/
make -j16
if [ $? -eq 0 ];then
	clear
	./day8
fi

