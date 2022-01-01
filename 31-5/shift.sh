#########################################################################
# File Name: shift.sh
# Author: Yufeng Huang <icebggg@qq.com>
# Created Time: Sat 01 Jan 2022 01:00:38 AM PST
#########################################################################
#! /bin/sh
echo "The program $0 is now running"
echo "The first parameter is $1"
echo "The second parameter is $2"
echo "The parameter list is $@"
shift
echo 
echo "The program $0 is now running"
echo "The first parameter is $1"
echo "The second parameter is $2"
echo "The parameter list is $@"

