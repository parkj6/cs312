#!/bin/bash

if [ -e ~/.ssh/id_rsa.pub ]
then
	echo -e "\e[1;36mSkipping ssh key generation (file exists).\e[0m"
	echo
	echo
	sleep 3
else
	echo -e "\e[1;32mGenerating ssh key...\e[0m"
	ssh-keygen -t rsa 
	$not_my_first_time=1
fi

echo -e "\e[1;32mCopying the ssh key to Alpine VM's\e[0m"
ssh-copy-id root@192.168.1.21
ssh-copy-id root@192.168.1.22
ssh-copy-id root@192.168.1.23
ssh-copy-id root@192.168.1.24

echo -e "\e[1;32mConfiguring Ansible Playbook\e[0m"
ansible-playbook webserver.yaml -i hosts.ini

echo -e "\e[1;32mDO YOU EVEN CURL, BRO?\e[0m"
curl 192.168.1.21
sleep 2
curl 192.168.1.22
sleep 2
curl 192.168.1.23
sleep 2
curl 192.168.1.24

