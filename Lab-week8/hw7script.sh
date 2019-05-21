#!/bin/bash

echo -e "\e[1;32mGenerating ssh key to current location\e[0m"
ssh-keygen -t rsa 
#disable the line above to stop generating new keys everytime.

echo -e "\e[1;36mNote that this will generate new key everytime unless you comment out the previous command (line:4) in the script" 
sleep 5

echo -e "\e[1;32mCopying the ssh key to Alpine VM's\e[0m"
ssh-copy-id root@192.168.1.21
ssh-copy-id root@192.168.1.22
ssh-copy-id root@192.168.1.23
ssh-copy-id root@192.168.1.24

echo -e "\e[1;32mConfiguring Ansible Playbook\e[0m"
ansible-playbook webserver.yaml -i hosts.ini

echo -e "\e[1;32mDo you even curl bro?\e[0m"
curl 192.168.1.21
sleep 2
curl 192.168.1.22
sleep 2
curl 192.168.1.23
sleep 2
curl 192.168.1.24

