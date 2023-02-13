PASSWORD CHANGE
	passwd keitakah
		Born2Beroot
	su -
	passwd root
		Born2Beroot

SUDO
	apt install sudo
	adduser keitakah sudo	//add keitakah sudo group
	getent group sudo //get entry of sudo group
		sudo::keitakah
	//keitakah can use sudo
	reboot
	sudo visudo
		Defaults	passwd_tries=3
		Defaults	badpass_message="Wrong! Try again."
		Defaults	logfile="/var/log/sudo/sudo.log"
		Defaults	log_input,log_output
		Defaults	iolog_dir="/var/log/sudo"
		Defaults	requiretty
		Defaults	...+:/snap/bin

SSH
	sudo apt update
	sudo apt install openssh-server
	systemctl status ssh
	sudo nano /etc/ssh/sshd_config
		Port 4242
		PermitRootLogin no
	hostname -I
		10.0.2.15
	whoami
		keitakah
	ssh -p 4242 keitakah@10.0.2.15

UFW
	sudo update
	sudo apt install ufw 
	sudo ufw enable
	sudo ufw default DENY
	sudo ufw allow 4242
	sudo systemctl start ufw
	sudo systemctl status ufw

USER/GROUP
	sudo nano /etc/hostname
	cat /etc/group | grep sudo
	cat /etc/group | grep keitakah42
	sudo groupadd keitakah42
	adduser keitakah keitakah42
	cat /etc/group | grep keitakah42

PASSWORD
	sudo nano /etc/login.defs
		PASS_MAX_DAYS	30
		PASS_MIN_DAYS	2
		PASS_WARN_AGE	7
	sudo apt update
	sudo apt install libpam-pwquality
	sudo nano /etc/pam.d/common-password
		#here are the per-package modules (the "Primary" block)
		password requisite pam_pwquality.so
			retry=3 minlen=10 ucredit=-1 lcredit=-1 dcredit=-1
			maxrepeat=3 reject_username difok=7 enforce_for_root
