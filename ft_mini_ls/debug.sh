#!/usr/bin/env bash

LOG_OUT=stdout.log
LOG_ERR=stderr.log

exec 1> >(tee -a $LOG_OUT)
exec 2> >(tee -a $LOG_ERR)

echo $(date +"%Y-%m-%d %H:%M:%S") 2>&1
echo $(date +"%Y-%m-%d %H:%M:%S") 1>&2

echo "used function"-----------------
nm -u ft_mini_ls

sleep 2
mkdir test
sleep 2
touch temp1
sleep 2
ln -s test link
sleep 2
touch temp2
sleep 2
echo "ls -1tr"------------------------
sleep 2
ls -1tr | cat -e
echo "ft_mini_ls"---------------------
sleep 2
./ft_mini_ls | cat -e
rm -rf test temp1 temp2 link
sleep 1

echo "ls -1tr spead"------------------
mkdir test
touch temp1
ln -s test link
touch temp2
ls -1tr | cat -e
rm -rf test temp1 temp2 link
sleep 1

echo "ft_mini_ls spead"---------------
mkdir test
touch temp1
ln -s test link
touch temp2
./ft_mini_ls | cat -e
rm -rf test temp1 temp2 link
sleep 1

echo "ls -1lr same time"-------------
touch a c b
touch a c b
ls -1tr | cat -e
rm a b c
sleep 1

echo "ft_mini_ls same time"-----------
touch a c b
touch a c b
./ft_mini_ls | cat -e
rm a b c
sleep 1

echo "ls -1lr various variables"------
touch file a.out
mkdir dir
mkfifo fifo
ln -s file link
chmod +x a.out
ls -1tr | cat -e
rm -rf file dir fifo link a.out

echo "ft_mini_ls various variables"------
touch file a.out
mkdir dir
mkfifo fifo
ln -s file link
chmod +x a.out
./ft_mini_ls | cat -e
rm -rf file dir fifo link a.out

echo "multiple arguments"-------------
./ft_mini_ls sample
./ft_mini_ls sample sample

echo "opendir error"------------------
mkdir temp
cp ft_mini_ls temp/
chmod 111 temp
cd temp
./ft_mini_ls
ls -1tr
cd ..

echo "malloc and read error"-----------
chmod 777 temp
cd temp
COUNTER=0
LS_COUNT=1000
MAX_COUNT=10000
while [ ${COUNTER} -lt ${MAX_COUNT} ]
do
	while [ ${COUNTER} -le ${LS_COUNT} ]
	do
		touch temp${COUNTER}
		let COUNTER++
	done
	./ft_mini_ls | wc -l
	sleep 1
	let LS_COUNT=${LS_COUNT}+1000
done
./ft_mini_ls | wc -l
cd ..
rm -r temp
