yum install wget openssl-devel  python-sphinx gcc make python-devel openssl-devel kernel-devel graphviz kernel-debug-devel autoconf automake rpm-build redhat-rpm-config libtool python-twisted-core python-zope-interface PyQt4 desktop-file-utils libcap-ng-devel groff checkpolicy selinux-policy-devel -y
useradd ovs
su - ovs
mkdir -p ~/rpmbuild/SOURCES
wget http://openvswitch.org/releases/openvswitch-2.9.2.tar.gz
cp openvswitch-2.9.2.tar.gz ~/rpmbuild/SOURCES/
tar xfz openvswitch-2.9.2.tar.gz
rpmbuild -bb --nocheck openvswitch-2.9.2/rhel/openvswitch-fedora.spec
exit
rpm -i /home/ovs/rpmbuild/RPMS/x86_64/openvswitch-2.9.2-1.el7.x86_64.rpm 
