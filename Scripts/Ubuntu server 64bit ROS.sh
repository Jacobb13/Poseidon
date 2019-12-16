#!/bin/bash

#update the apps
echo --------------------
echo Updating Deb.
echo --------------------
sudo apt update >> log.txt

#upgrade the apps
echo --------------------
echo Updating Apps.
echo --------------------
sudo apt upgrade -y >> log.txt

# Install utilities with the YES answer to apt prompt
echo --------------------
echo Installing Utilities.
echo --------------------
sudo apt install gcc python3-dev python3-pip python3-setuptools git curl -y >> log.txt

# Install RPi.GPIO
pip3 install RPi.GPIO >> log.txt
# Now ROS Installation
echo --------------------
echo Installing ROS.
echo --------------------
# Setup sources.list
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list' >> log.txt
# Setup keys
sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654 >> log.txt
curl -sSL 'http://keyserver.ubuntu.com/pks/lookup?op=get&search=0xC1CF6E31E6BADE8868B172B4F42ED6FBAB17C654' | sudo apt-key add - >> log.txt

# Actual Installation
sudo apt-get update >> log.txt

#sudo apt install ros-kinetic-ros-base g++ -y >> log.txt
sudo apt install ros-melodic-ros-base g++ -y >> log.txt

# Initialize rosdep
echo --------------------
echo Initialize ROSdep
echo --------------------
sudo rosdep init >> log.txt
echo --------------------
echo Updating ROSdep
echo --------------------
rosdep update >> log.txt

clear
#instaling system installation script here
echo --------------------
echo End of script
echo --------------------
