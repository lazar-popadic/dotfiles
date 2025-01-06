//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/						/*Update Interval*/	/*Update Signal*/
//	{" ", 		"free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	1,		0},
//	{"",		"setxkbmap -v | awk -F + '/symbols/ {print $2}'",		1,		20},
	{"",		"mpc_status_cycle_read.sh",					0,		13},
	{"",		"mpc_status_time.sh",						1,		0},
	{"  ",		"volume.sh",							0,		10},
	{"  ",		"check_brightness.sh",						0,		12},
	{"  ",		"check_battery.sh",						1,		0},
	{"  ",		"echo_kbd.sh",							1,		11},
	{"  ",		"time.sh",							1,		0},
	{"  ",		"date.sh",							1,		0},
	{" ",		"",								0,		0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "  ";
static unsigned int delimLen = 2;
