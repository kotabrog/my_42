#!/bin/sh

cat test.sh

./miniRT 
./miniRT a
./miniRT minirt.h
./miniRT minirt.rt
./miniRT rt_sample/sample1.rt -save
./miniRT rt_sample/sample1.rt --save aa
./miniRT rt_sample/sample1.rt --save
chmod 000 sample1_1.bmp
./miniRT rt_sample/sample1.rt --save
chmod 777 sample1_1.bmp
rm sample1_1.bmp
