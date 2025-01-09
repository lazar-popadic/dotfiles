//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/						/*Update Interval*/	/*Update Signal*/
//	{" ", 		"free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	1,		0},
	{"",		"mpc_show.sh",							0,		13},
	{"",		"mpc_time.sh",							1,		9},
	{"  ",		"volume.sh",							0,		10},
	{"  ",		"check_brightness.sh",						0,		12},
	{"  ",		"check_battery.sh",						1,		9},
	{"  ",		"echo_kbd.sh",							0,		11},
	{"  ",		"time.sh",							1,		9},
	{"  ",		"date.sh",							1,		9},
	{" ",		"",								0,		9},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " ";
static unsigned int delimLen = 1;
