#!bin/bash

#SYSTEM ARCHITECTURE

sarch=$(uname -srvo)

#PHYSICAL CPU

PCPU=$(lscpu | grep "CPU(s):" | awk '{ print $2 }')

#Virtual CPU
#nproc
mCPU=$(lscpu | grep "(s) per" | awk '{ total=$NF; getline; total*=$NF; print total }')
vCPU=$((PCPU * mCPU))
#Memory Use in MB and %

MemUse=$(free -m | grep "Mem:" | awk '{ printf ("%d/%dMB (%.2f%%)", $3, $2, ($2/$3)) }')

#DISK Use

sumperc=$(df -h | grep -v "Filesystem" | awk '{ total+=$(NF-1) } END { print total }')
sumused=$(df --block-size=G | grep -v "Filesystem" | awk '{ total+=$(NF-3) } END { print total }')
sumsize=$(df --block-size=G | grep -v "Filesystem" | awk '{ total+=$(NF-4) } END { print total }')

#CPU load

lcpu=$(top -bn 1 | grep "load" | awk '{ printf "%.1f%%", $(NF-2)} ')

#System last boot

sysboot=$(who -b | awk '{ printf "%s %s", $3, $4 }')

#LVM usage

lvm=$(lsblk | grep lvm | head -n 1 | awk '{ if (wc -l gt 0) { print "Yes" } else { print "No" } }')

#TCP Connections

TCP=$(ss -t | grep -c ESTAB)

#IP address

IP=$(hostname -I)
IPlink=$(ip a | grep "link/ether" | awk '{ printf"(%s)",$2 }')

#Users logged

users=$(who | wc -l)

#Sudo usage

sudos=$(sudo journalctl _COMM=sudo | grep -c "COMMAND=")

#SCRIPT

        wall "
        #Architecture: $sarch
        #CPU: $PCPU
        #vCPU: $mCPU 
        #Memory Usage: $MemUse 
        #Disk Usage: $sumused/$sumsize GB ($sumperc%) 
        #CPU load: $lcpu
        #Last boot: $sysboot
        #LVM use: $lvm
        #Connections TCP: $TCP ESTABLISHED
        #User log: $users
        #Network: IP $IP $IPlink
        #Sudo: $sudos cmd "
