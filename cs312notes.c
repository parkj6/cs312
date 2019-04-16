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

























