#!/bin/bash

wall "	#Architecture: $(uname -a)
	#CPU physical: $(nproc)
	#vCPU: $(cat /proc/cpuinfo | grep processor | wc -l)
	#Memory Usage: $(free -m | awk '$1=="Mem:" {print $3 "/" $2}')MB ($(free | awk '$1=="Mem:" {printf("%.2f"), $3/$2*100}')%)
	#Disk Usage: $(df --total -m | awk '$1=="total" {print $3 "/" $2 "MB" " (" $5 ")"}')
	#CPU load: $(mpstat | tail -1 | awk '{print $4}')%
	#Last boot: $(who -b | awk '{print $3 " " $4}')
	#LVM: $(lsblk | grep lvm | wc -l)
	#Connections TCP: $(ss -s | grep TCP: | awk '{print substr($4, 1, length($4)-1)}') ESTABLISHED
	#User log: $(users | wc -w)
	#Network: $(hostname -I) ($(ip link show | awk '$1=="link/ether" {print $2}')))
	#Sudo: $(grep COMMAND /var/log/sudo/sudo.log | wc -l)"