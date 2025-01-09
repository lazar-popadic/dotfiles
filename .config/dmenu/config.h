/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
static int centered = 0;                    /* -c option; centers dmenu on screen */
static int min_width = 480;                    /* minimum width when centered */
static const float menu_height_ratio = 2.0f;  /* This is the ratio used in the original calculation */
static const unsigned int alpha = 0xb8;     /* Amount of opacity. 0xff is opaque             */
static const unsigned int invisible = 0x00;
static const unsigned int opaque = 0xff;
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"BitstromWera Nerd Font:size=8"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
char black[8] = "#000000";
char white[8] = "#ffffff";
char grudzien[8] = "#2e6983";
char c_sands[8] = "#9a9d94";
char dopesmoker_blue[8]		= "#00324d";
char converging_grey[8]		= "#242424";
char adumbration_yellow[8]	= "#e4a95f";
char adumbration_red[8]       	= "#c72028";
static const char *colors[SchemeLast][2] = {
	/*		    	fg			bg    */
	[SchemeNorm] = { 	white,			black },
	[SchemeSel]  = { 	black, 	white },
	[SchemeOut]  = { 	black, 	white },
};

static const unsigned int alphas[SchemeLast][2] = {
	[SchemeNorm] = { opaque, alpha },
	[SchemeSel] = { alpha, opaque },
	[SchemeOut] = { alpha, opaque },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 12;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/* Size of the window border */
static unsigned int border_width = 1;
