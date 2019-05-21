#!/bin/bash
# This script installs docker onto a CentOS 7 Linux machine.
# This script also sets the current user to have admin rights to run docker.
# After this completes, log off, and then back on.
# NOTE: To execute this, you must be root, or use sudo.

echo "***** Installing Docker*****"
sudo yum install -y yum-utils device-mapper-persistent-data lvm2
sudo yum-config-manager --add-repo https://download.docker.com/linux/centos/docker-ce.repo
sudo yum install -y docker-ce
echo "***** Starting Docker*****"
sudo systemctl start docker
sleep 2
echo "***** Enabling Docker at boot*****"
sudo systemctl enable docker
sleep 2
echo "***** Granting $USER sudo rights for Docker *****"
sudo usermod -aG docker $USER
echo "***** Docker installed, reboot now! *****"
