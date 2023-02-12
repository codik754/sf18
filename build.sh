#!/bin/bash

nameDir="dirProg"
if [ -d $nameDir ]; then
   rm -rvf $nameDir
fi

mkdir $nameDir
make
