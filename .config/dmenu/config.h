/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
static const unsigned int alpha = 0xcc;     /* Amount of opacity. 0xff is opaque             */
static const unsigned int invisible = 0x00;
static const unsigned int opaque = 0xff;
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"BitstromWera Nerd Font:size=12"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
char black[8] = "#000000";
char white[8] = "#ffffff";
char grudzien[8] = "#2e6983";
char c_sands[8] = "#9a9d94";
char dopesmoker_blue[8] = "#00324d";
static const char *colors[SchemeLast][2] = {
	/*		    	fg			bg    */
	[SchemeNorm] = { 	white,			dopesmoker_blue },
	[SchemeSel]  = { 	dopesmoker_blue, 	white },
	[SchemeOut]  = { 	dopesmoker_blue, 	white },
};

static const unsigned int alphas[SchemeLast][2] = {
	[SchemeNorm] = { opaque, alpha },
	[SchemeSel] = { alpha, opaque },
	[SchemeOut] = { alpha, opaque },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 5;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/* Size of the window border */
static unsigned int border_width = 1;
