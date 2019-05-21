CS 312 - System Administration
Benjamin Brewster
Email: brewsteb@oregonstate.edu
Office: KEC 2113
https://oregonstate.instructure.com/courses/1719560
"Carry your monitor around, its your companion cube for the day"

TA:
	Garrett Haley: haleyg@oregonstate.edu
	Erich Kramer: kramerer@oregonstate.edu
	Spencer Moss (Lead TA): mosssp@oregonstate.edu
	Nick Pugliese: pugliesn@oregonstate.edu
	Monday, 2pm: TBA
	Monday, 4pm:
	Wednesday, 10am:
	Friday, 4pm:
	Monday: 10:30 - 11:30am	Ben Brewster (Instructor)	KEC 2113
	Wednesday: 10:30 - 11:30am	Ben Brewster (Instructor)	KEC 2113

Lectures:
	Required to bring laptop

Tests:
	There are no mid-term exams in this course.
	Our Final Exam is an online Quiz here in Canvas. As with all of our assignments, you will not use ANY form of proctor for this test.

/////////////////////////
//  2019-04-01 Wk1 D1  //
/////////////////////////

The Art of IT
	System Administration is an Art.
	All good art is bound by rules.
	Expert Breaks the Rules.
"You'll be agnostic in terms oof OS"

Lab:
	points taken off if you have extra screws left.


History of Wintel

IT:
	You cannot save money on IT
	You cannot save time on IT
	Its incredibly lucrative - for somebody
	We have fun toys.

	

/////////////////////////
//  2019-04-03 Wk1 D2  //
/////////////////////////

PC Hardware Overview
	Enclosure
	Motherboard
		
	CPU
	Random Access Memory
	Power Supply Unit
		Do not skip out on good PSU
	Drives

PC Standards:
	AT comes from the name of IBMs second gen PC. The IBM PC/AT (Advanced Technology)
	ATX = Extended
	BTX = Balanced Technology Extended

Stuff for the class
	HP Z230 Mobo
		8P8C connector
		4x USB 2
		2x USB 3
		Displayport

Busses  (omnibus): connects data from CPU, RAM, I/O
	CPU and RAM are tightly coupled, runs independently
	Old-school parallel busses reached their lmits interms of speed (difficulties of cross talk, timing skew, EMI, and power consumption)
	Serial busses dont have that problem.


PS/2 = Interrupt based (takes no CPU time)
USB  = Polling based (whatever ms it uses)


SDR - single data rate (old standard)
DDR - Double Data Rate 
	transfers data on both the rising and falling edges of the oscillator-generated clock signal.
Power Supply Unit (PSU):
	ATX Specs:
		Voltages: +12V, +5V, +3.3V, low-power -12V (legacy), +5B(sb)
		



/////////////////////////
//  2019-04-08 Wk2 D1  //
/////////////////////////

For the purpose of this class, "Hard drives" are magnetic and "SSD" are all flash memories including USB.

OEM: Original Equipment Manufacturer.

// Drives logistics.
Partition (physical): 
	managed physical entity by the OS. 
File System (format): 
	Naming, addressing, metadata, storage of files/folders within a partition.
	OS cannot read a filesystem unless it has the drivers to do so.

Volume:
	A file storage location inside a file system. 
Mount Point:   
	Particular folder inside the booted OS where the volume files can be found.
Track:
	Ring of files in a disk
Sector:
	Minimum storage unit of a drive
	A single space (4096b - Advanced Format) in a Track.
Cluster (allocation unit):
	smallest amount of space the FS will use to store a file.
Slack space:
	the wasted space of a sector (10b used / 4KB cluster)
Fragmentation:
	files stored in multiple physically non-contiguous space. 
	still logically contiguous.

Disk Formatting:
mkfs -t ext3 -b 1024 -L LABLE /dev/sda1

Block:
	could mean anything depending on context.
	1. Sector on a disk.
	2. 



/////////////////////////
//  2019-04-15 Wk3 D1  //
/////////////////////////

// Important Windows stuff.
crss:				handles shutting down windows
smss:				session manager
winlogin:			handles user session
svchost:			different services
ntvclient:			network-time client
AppData\Roaming:	Profile settings
Windows\System:		16bit Windows
Windows\System32:	64bit Windows
Windows\SysWOW64:	32bit (Windows on Windows)

// Mac OS Stuff
actually based on BSD, not Unix
Core: 			Darwin
GUI:			Aqua
command+R:		something...
Go:				same as "Start" on Windows
dmg:			Disk Image (img/iso)

diskutil logistics 	//lists all partition.



/////////////////////////
//  2019-04-15 Wk3 D2  //
/////////////////////////

// Important GNU/Linux stuff?
vmlinuz:			kernel compressed as gzip -> 
systemd:			First thing linux does and only thing it cares about.
package:			executable compressed into 1 blob. (msi in windows)
pkgmgr:				package manager, also keeps track of version.
/usr				Unix system Resource
					- binaries, docs, libraries, header files, etc.
					- largest share of data on the system.
/usr/bin 			General purpose library.
/usr/local 			Local (user) compiled binaries
/usr/src 			Linux kernel source code.
/bin 				Binary files
/sbin 				System binaries.
/proc 				Virtual filesystem (created for boot/shutdown)
/etc 				Most system config are stored.
/etc/X11			Where graphics settings are kept
/etc/shells			Allowed shells
/etc/os-release		What OS is installed
/etc/fstab			File system mapping table: where, what disks are
/etc/sudoers		Who can use sudo
/etc/hosts			Maps hostnames to IP addresses
/etc/yum.repos.d/	Stores all configured repos for packages
/dev 				Physical drives, peripherals. 

ps -elf | sort -nr -k 	run
sudo yum-config-manager --add-repo [repository]
	sudo yum install epel-release
sudo yum -y install yum-utils 	// to install repoquery.
repoquery --tree-requires cowsay	

lynx		// ASCII web browser.



"don't write your own login system, get one of the open source ones"



/////////////////////////
//  2019-04-22 Wk4 D1  //
/////////////////////////

//Containers
- You dont log into a container. 
- no need for boot or init. 
- does not emulate x86 processor like a vm so it is much faster.
- containers are instances of docker image. 
- cannot be distributed, images can be distributed.

sudo usermod -aG docker $USER //allows docker to be used by user

alpine: minimal OS to run docker on. 

docker images // to see what's installed
docker run $IMAGENAME $COMMANDS		//run commands directly.
docker run alpine cat /etc/os-release

docker ps -a // See all running/stopped containers.

// Run nginx webserver as a daemon, forward the port 80 to be displayed by 8080.
docker run --name web -d -p -8080:80 nginx:alpine  
docker stop web 	// kill it. 
docker restart web 		// same command as above, except save time.
docker stats 			// stats on the container like top command

docker container rm $CONTAINER_NAME // remove old container
docker image rm alpine:3.5			// remove the container itself.

// list of exited container, -Quiet (only display ID), -Filtered
docker ps -q -f status=exited 		
docker container rm $(docker ps -q -f status= exited) //get rid of all 
docker run --rm hello-world // kills the container after,.

docker run -it alpine sh // run sh inside alpine in interactive mode.
CTRL + P, CTRL + Q to get out
docker attach $CONTAINER_NAME // reattaches back to container.




/////////////////////////
//  2019-04-24 Wk4 D2  //
/////////////////////////


Docker does not use glib-c
it also uses busybox as opposed to full set of utils.

apk -U add build-base gcc abuild binutils binutils-doc gcc-doc //install couple basics

curl -L // followthrough the redirect 

docker start -i webtest // continue where we left off.

dockerfiles -> setup script used to build a specific image.

Swarm manager is a server that manages the swarm.




/////////////////////////
//  2019-05-01 Wk5 D2  //
/////////////////////////

Firewall originally started from engines in the car.
"Nobody is allowed, everyone is an enemy."

Firewall 
1. Rules
	permission to drive on the bridge
	incoming traffic addressed to registered/unused port is blocked.
	anti-lockout rule: allow port 80 in case the router breaks.
2. Network Address Translation (NAT)
	building the bridge
	allows port-forwarding for incoming connections.
	allows WAN to make first connection with LAN.
	Routers are normally built into the hardware, rather than software
	NAT is is enabled on internal routers but not needed.

10.0.x.x is internal, always dropped on the internet. 

wirespeed: is the device able to transmit data as it is receiving it? if so, no overhead.
"throw money at the problem is always the solution in IT"

NAT example:
1. host sends the header
	S: 10.0.0.1:3345	//random port
	D: 128.119.40.186:80
2. NAT router changes datagram source addr and updates table
	S: 138.76.29.7:5001 //5001 maps original Source
	D: 128.119.40.186:80
3. Reply arrives to NAT
	S: 128.119.40.186:80
	D: 138.76.29.7:5001
4. NAT changes the destination address back to orignal computer
	S: 128.119.40.186:80
	D: 10.0.0.1:3345	// yay mail.

before: static addresss will be useless outside the network. 
now: we use static address via mac address. 

NAT breaks VPN

Power and Ethernet crosses alternating currents.
WAP should be placed in center of the room 
Dont let metal block the way of WAP
Separate the channels from overlapping
5Ghz is weaker than 2.4GHz in range.




/////////////////////////
//  2019-05-08 Wk6 D2  //
/////////////////////////

// Windows Active Directory (AD)
"Domain is like joining a country, except you can never ever leave... it's like North Korea. You'll get killed if you try to."


.com could point to a port 987 will be a share server. 
WiNS - Windows Naming Service (DNS but for local network)

You can pick a specific windows servers if you want. 
	just edit the DHCP or disable it. 
	Place a windows server contientiously. because it will take over everything.

PCs in certain domain will be subjected to Group Policies defined on that domain.
You will have to reinstall windows if you lost access to the domain.

// Certificate Authority (AD CS)
Group Policies controls who gets which certificates.

//Federation Services (AD FS)
Login services, authorization services
AKA OAuth
You use FS to login and gives you a token for site you are going for.

//Rights Management Services (AD RMS)
Built-in system for encrypting files and sets user permission.

Windows VM is good for gaming server, but not actually on the machine because needs graphic cards.

Server Manager, DHCP (can configure like regedit)




/////////////////////////
//  2019-05-13 Wk7 D1  //
/////////////////////////

week 9 lab = computer lab tour.

Objective for DevOps: not to get paged at 3 in the morning and get yelled at "you better fix this or you're fired"

SRE = Another word for DevOps (Site Reliability Engineering)

Telemetry: signal of health. (Heartbeat of your system)

SysAdmin questions:
	- How do you micro-manage these, and do you even want to?
	- If something is wrong with the particular machine, do you even care?
	- If you want to push an update, how do you do that to all of them?
	- And can you really type a few hundred commands thousands of times?
		- Active Directory
		- Chef and Puppet
		- get another job

// Configuration Management (CM)
Nowadays, just reinstalling the system is much faster than trying to find the drivers crashing. 


For example, we really want to just do this (Nightly example):
1. Spin up a Linux computer
2. Install the dependencies for the catsGifsNow service software
3. Download the catGifsNow Git repository''s source code
4. Build catGifsNow
5. Start the catGifsNow service
6. Add this instance of catGifsNow to our load balancer

CM / CM-like programs:
	- Chef
	- Puppet
	- Continuum and other Managed Provider Middleware
	- Ansible

Jenkins - automation server 

Chef, Puppet:
- Install a Daemon onto target system:
	- tracks the host state (packages, files, network connections, etc.)
	- Receives updates from the controller
	- Polls for updates every #min or #hour
	- They operate on "pull" model
		- installed agent checks for updates
		- performs those updates


Chef uses Ruby
Puppet uses Puppet config language.


Ansible (from Enders game)
	- operates on "push" model (less efficient).
		1. Controller has to evaluate the script given to it, 
		2. decide on the modules needed
		3. upload those modules
		4. run the commands
		5. then remove the modules.
	- could be set to "pull" model.
	- Do not need to maintain an agent install.
	- This is the mechanism, straight from the documentation:
"Ansible works by connecting to your nodes and pushing out small programs, called "Ansible modules" to them. These programs are written to be resource models of the desired state of the system. Ansible then executes these modules (over SSH by default), and removes them when finished."
	- You could tell ansible to target a state and install a MySQL and it will install it faster and efficiently than a human would.
	- Not a shell script, not a service or daemon. 
	- also does not monitor states. 

Goal of Automation:
	Remove human error
	Do things faster
	Reproducucibility: "No matter what, these exact things definitely work"
	Auto-remediation: "Did this daemon die? Here's how to restart it. Send me a text if that doesn't work, call me if doesn't work 3 times in a row"

// DevOps review
Dev Ops needs to worry about SLI, SLO, SLA:
	- Service Level Indicator: A quantitative measurement of a particular facet of a service: uptime, number hosts contacted, patches installed per hour, etc.
	- Service Level Objectives: A target value or range of values for an SLI
	- Service Level Agreement: The contractual agreement that specifies what SLOs we''re attempting to meet, and what happens when we meet, exceed, or fail to meet them.
	









/////////////////////////
//  2019-05-15 Wk7 D3 //
/////////////////////////
ssh-keygen -t rsa // to generate ssh key

ssh-copy-id -i ~/.ssh/id_rsa root@192.168.1.20 // copy the adds the key you just created to .ssh folder. 

Ansible playbooks are yaml files that contains instructions to be performed on set of machines



/////////////////////////
//  2019-05-20 Wk8 D1 //
/////////////////////////
nmap has better traceroute than acctual traceroute utility.
nmap -v -sS -sV -T4

zenmap: gui for nmap

salts are public information, if you have a dictionary, you can salt it differently with other dictionary words. 
$6$ // type of salt it was used.

head -n 1 /etc/shadow | cut -f 2 -d":" > pass
// first line of password, chop it to 2nd delimiter ":" and save to file "pass"

hashcat --help | grep "1800" // hash type specific to kali.














