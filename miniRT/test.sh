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

cat rt_sample/test1.rt
./miniRT rt_sample/test1.rt

cat rt_sample/test2.rt
./miniRT rt_sample/test2.rt

cat rt_sample/test3.rt
./miniRT rt_sample/test3.rt

./miniRT rt_sample/test2.rt --save

cat rt_sample/test4.rt
./miniRT rt_sample/test4.rt

cat rt_sample/test5.rt
./miniRT rt_sample/test5.rt

cat rt_sample/test6.rt
./miniRT rt_sample/test6.rt

cat rt_sample/test7.rt
./miniRT rt_sample/test7.rt

cat rt_sample/test8.rt
./miniRT rt_sample/test8.rt

cat rt_sample/test9.rt
./miniRT rt_sample/test9.rt

cat rt_sample/test10.rt
./miniRT rt_sample/test10.rt

cat rt_sample/multi_lite.rt
./miniRT rt_sample/multi_lite.rt

cat rt_sample/test11.rt
./miniRT rt_sample/test11.rt

cat rt_sample/test12.rt
./miniRT rt_sample/test12.rt

cat rt_sample/test13.rt
./miniRT rt_sample/test13.rt

cat rt_sample/test14.rt
./miniRT rt_sample/test14.rt

