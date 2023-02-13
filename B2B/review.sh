##sinple setup
systemctl status ufw
systemctl status ssh
uname -v

##user/pasword policy
users
cat /etc/group | grep sudo | grep keitakah42
#create a new user & setup password
sudo useradd your_login
sudo passwd your_login
#explain how to set up the rules
nano /etc/login.defs
nano /etc/pam.d/common-password
sudo groupadd evaluating
adduser your_login evaluating
cat /etc/group | grep evaluating

##hostname and partitions
cat /etc/hostname
sudo nano /etc/hostname
	your_login

sudo nano /etc/hosts
	127.0.1.1 your_login

lsblk

##sudo
dpkg -l | grep sudo
sudo adduser your_login sudo
su -
cd /var/log/sudo
cat sudo.log
sudo status ufw
cat sudo.log

##ufw
dpkg -l | grep ufw
sudo systemctl status ufw
sudo ufw status
sudo ufw allow 8080
sudo ufw status
sudo ufw delete 8080
sudo ufw status

##ssh
dpkg -l | grep ssh
sudo systemctl status ssh
ssh keitakah@10.0.2.15
ssh -p 41 keitakah@10.0.2.15
ssh root@10.0.2.15
ssh -p 42 your_login@10.0.2.15

##bash
nano /bin/monitoring.sh
crontab -u root -e

###explain
#Project overview
#	How a virtual machine works
#	Their choice of operating system
#	The basic differences between CentOS and Debian
#	The purpose of virtual machines
#	Difference between aptitude and apt
#	What APPArmor is
#
#Simple setup
#User/Password
#	The advantages and disadvantages of this password policy
		adv
			avoid easy password
			avoid bad access for at least 30 days
		dis
			reqest password update every month > hard to create, remember
			a lot update for users who do not login usually
#Hostname and partitions
#	What is LVM
#	How LVM works
#Sudo
#	The value and operation of sudo
#UFW
#	What is UFW
		tool to select access whether it can connect or not
#	The value
		control access
#SSH
#	What is SSH
		the way to connect with server.
		configuring ssh-server, we can connect on the defined ssh route.
#	The value
		remote works

#Bash
#	How their script works by showing you the code
#	What "cron" is
		excute the file on the date, hours, minutes defined