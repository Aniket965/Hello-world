#!/bin/sh

# adduser - Adds a new user to the system, including building their
#           home directory, copying in default config data, etc.
#           For a standard Unix/Linux system, not Mac OS X.

pwfile="/etc/passwd"    shadowfile="/etc/shadow"
gfile="/etc/group"
hdir="/home"

if [ "$(whoami)" != "root" ] ; then
  echo "Error: You must be root to run this command." 
  exit 1
fi

echo "Add new user account to $(hostname)"
echo -n "login: "     ; read login

# Adjust '5000' to match the top end of your user account namespace
# because some system accounts have uid's like 65535 and similar.

FLOOR=2000

number=0   #initialize
while [ "$number" -le $FLOOR ]
do
  number=$RANDOM
done
uid=$number
homedir=$hdir/$login

# We are giving each user their own group, so gid=uid
gid=$uid

echo -n "full name: " ; read fullname
echo -n "shell: "     ; read shell

echo "Setting up account $login for $fullname..."

echo ${login}:x:${uid}:${gid}:${fullname}:${homedir}:$shell >> $pwfile
echo ${login}:*:11647:0:99999:7::: >> $shadowfile

echo "${login}:x:${gid}:$login" >> $gfile

mkdir $homedir
cp -R /etc/skel/.[a-zA-Z]* $homedir
chmod 755 $homedir
find $homedir -print | xargs chown ${login}:${login}

# Setting an initial password
passwd $login

exit 0
