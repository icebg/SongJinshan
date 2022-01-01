#########################################################################
# File Name: while.sh
# Author: Yufeng Huang <icebggg@qq.com>
# Created Time: Sat 01 Jan 2022 12:02:46 AM PST
#########################################################################
# !/bin/sh
echo "Please Enter Passsword :"
COUNTER=0
read TRY
while [ "$TRY" != "fuck" ]; do
	COUNTER=$(($COUNTER+1))
	echo "Passsword is wrong!" "You've failed $COUNTER times, only $((5-$COUNTER)) tmies left  to retry!"
	if [ $COUNTER = 5 ]; then
		echo "  break"
		exit 1
	fi
	read TRY
done
