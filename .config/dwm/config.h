/* See LICENSE file for copyright and license details. */
#include <X11/XF86keysym.h>

/* appearance */
static const unsigned int borderpx = 1; /* border pixel of windows */
static const unsigned int gappx = 2;    /* gaps between windows */
static const unsigned int snap = 16;    /* snap pixel */
static const int showbar = 1;           /* 0 means no bar */
static const int topbar = 1;            /* 0 means bottom bar */
static const int vertpad = 2;           /* vertical padding of bar */
static const int sidepad = 2;           /* horizontal padding of bar */
static const int user_bh
    = 4; /* 2 is the default spacing around the bar's font */
static const unsigned int systraypinning
    = 1; /* 0: sloppy systray follows selected monitor, >0: pin systray to
            monitor X */
static const unsigned int systrayspacing = 4; /* systray spacing */
static const int systraypinningfailfirst
    = 1; /* 1: if pinning fails, display systray on the first monitor, False:
            display systray on the last monitor*/
static const int showsystray = 1; /* 0 means no systray */
static const char *fonts[]
    = { "BitstromWera Nerd Font Propo:style=Oblique:size=9" };
static const char dmenufont[] = "BitstromWera Nerd Font Propo:size=8";
// static const char dmenu_w[]	= "480";
// static const char dmenu_y[]	= "478";
// static const char dmenu_x[]	= "720";
static const char grudzien[] = "#2e6983";
static const char black[] = "#000000";
static const char white[] = "#ffffff";
static const char c_sands[] = "#9a9d94";
static const char adumbration_yellow[] = "#e4a95f";
static const char adumbration_red[] = "#c72028";
static const unsigned int invisible = 0x00;
static const unsigned int alpha = 0xcc;
static const char *colors[][4] = {
  /*               	fg      	bg    		border   */
  [SchemeSel] = { black, white, white, black },
  [SchemeNorm] = { white, black, black, black },
  [SchemeStatus]
  = { white, black, "#000000", black }, // Statusbar right {text,background,not
                                        // used but cannot be empty}
  [SchemeTagsSel] = { black, white, "#000000",
                      black }, // Tagbar left selected {text,background,not
                               // used but cannot be empty}
  [SchemeTagsNorm] = { white, black, "#000000",
                       black }, // Tagbar left unselected {text,background,not
                                // used but cannot be empty}
  [SchemeInfoSel] = { white, black, "#000000",
                      black }, // infobar middle  selected {text,background,not
                               // used but cannot be empty}
  [SchemeInfoNorm]
  = { white, black, "#000000",
      black }, // infobar middle  unselected {text,background,not used but
               // cannot be empty}
};
static const unsigned int alphas[][4] = {
  /*               	fg      	bg       	border     */
  [SchemeSel] = { invisible, OPAQUE, OPAQUE, OPAQUE },
  [SchemeNorm] = { OPAQUE, invisible, OPAQUE, OPAQUE },
  [SchemeStatus] = { OPAQUE, invisible, OPAQUE,
                     OPAQUE }, // Statusbar right {text,background,not used
                               // but cannot be empty}
  [SchemeTagsSel] = { invisible, OPAQUE, OPAQUE,
                      OPAQUE }, // Tagbar left selected {text,background,not
                                // used but cannot be empty}
  [SchemeTagsNorm] = { OPAQUE, invisible, OPAQUE,
                       OPAQUE }, // Tagbar left unselected {text,background,not
                                 // used but cannot be empty}
  [SchemeInfoSel]
  = { OPAQUE, invisible, OPAQUE,
      OPAQUE }, // infobar middle  selected {text,background,not used but
                // cannot be empty}
  [SchemeInfoNorm]
  = { OPAQUE, invisible, OPAQUE,
      OPAQUE }, // infobar middle  unselected {text,background,not used but
                // cannot be empty}
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
  /* xprop(1):
   *	WM_CLASS(STRING) = instance, class
   *	WM_NAME(STRING) = title
   */
  /* class, instance, title, tags mask, isfloating, monitor */
  { "Chromium", NULL, NULL, 1 << 0, 0, -1 },
  { "Firefox", NULL, NULL, 1 << 0, 0, -1 },
  { "Brave", NULL, NULL, 1 << 0, 0, -1 },
  { NULL, NULL, "Grayjay", 1 << 1, 0, -1 },
  { "strawberry", NULL, NULL, 1 << 7, 0, -1 },
  { "qBittorrent", NULL, NULL, 1 << 8, 0, -1 },
  { "STM32CubeIDE", NULL, NULL, 1 << 1, 0, -1 },
  { "Stm32cubeide", NULL, NULL, 1 << 1, 0, -1 },
  { "Qalculate", NULL, NULL, NULL, 1, -1 },
  { "Ferdium", NULL, NULL, 1 << 3, 0, -1 },
  { "file-roller", NULL, NULL, NULL, 1, -1 },
  { "copyq", NULL, NULL, NULL, 1, -1 },
  { "Nitrogen", NULL, NULL, NULL, 1, -1 },
  { "pavucontrol", NULL, NULL, NULL, 1, -1 },
  { "steam", NULL, NULL, 1 << 6, 0, -1 },
  { "org.remmina.Remmina", NULL, NULL, NULL, 1, -1 },
  { NULL, NULL, "Figure 1", NULL, 1, -1 },
  { NULL, NULL, "Figure 2", NULL, 1, -1 },
  { NULL, NULL, "Figure 3", NULL, 1, -1 },
  { NULL, NULL, "Figure 4", NULL, 1, -1 },
};

/* layout(s) */
static const float mfact = 0.72; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints
    = 0; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen
    = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
  /* symbol     arrange function */
  { "T", tile }, /* first entry is default */
  { "F", NULL }, /* no layout function means floating behavior */
  { "M", monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                     \
  { MODKEY, KEY, view, { .ui = 1 << TAG } },                                  \
      { MODKEY | ControlMask, KEY, toggleview, { .ui = 1 << TAG } },          \
      { MODKEY | ShiftMask, KEY, tag, { .ui = 1 << TAG } },                   \
      { MODKEY | ControlMask | ShiftMask,                                     \
        KEY,                                                                  \
        toggletag,                                                            \
        { .ui = 1 << TAG } },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                            \
  {                                                                           \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                      \
  }

/* commands */
static char dmenumon[2]
    = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-c", "-m", dmenumon, NULL };
static const char *termcmd[] = { "st", NULL };

/* commands spawned when clicking statusbar, the mouse button pressed is
 * exported as BUTTON */
static const StatusCmd statuscmds[] = {
  { "gsimplecal", 1 },
  { "toggle_prog_tui ncmpcpp", 2 },
  { "toggle_prog pavucontrol", 3 },
  { "toggle_kbd | bar_reset", 4 },

};
static const char *statuscmd[] = { "/bin/sh", "-c", NULL, NULL };

static const Key keys[] = {
  /* modifier, key, function, argument */
  { MODKEY, XK_p, spawn, { .v = dmenucmd } },
  { MODKEY | ShiftMask, XK_Return, spawn, { .v = termcmd } },
  { MODKEY, XK_b, togglebar, { 0 } },
  { MODKEY, XK_j, focusstack, { .i = +1 } },
  { MODKEY, XK_k, focusstack, { .i = -1 } },
  { MODKEY, XK_i, incnmaster, { .i = +1 } },
  { MODKEY, XK_d, incnmaster, { .i = -1 } },
  { MODKEY, XK_h, setmfact, { .f = -0.04 } },
  { MODKEY, XK_l, setmfact, { .f = +0.04 } },
  { MODKEY, XK_Return, zoom, { 0 } },
  { MODKEY, XK_Tab, view, { 0 } },
  { MODKEY | ShiftMask, XK_q, killclient, { 0 } },
  { MODKEY | ShiftMask, XK_l, spawn, SHCMD ("slock") },
  { MODKEY, XK_space, togglefloating, { 0 } },
  //	sledeca 4 su za multimonitor
  { MODKEY, XK_comma, focusmon, { .i = -1 } },
  { MODKEY, XK_period, focusmon, { .i = +1 } },
  { MODKEY | ShiftMask, XK_comma, tagmon, { .i = -1 } },
  { MODKEY | ShiftMask, XK_period, tagmon, { .i = +1 } },
  { ShiftMask, XK_Alt_L, spawn, SHCMD ("bar_reset") },
  { MODKEY | ShiftMask, XK_s, spawn, SHCMD ("flameshot gui") },
  { MODKEY, XK_minus, spawn, SHCMD ("pamixer -d 4 | bar_reset") },
  { 0, XF86XK_AudioLowerVolume, spawn, SHCMD ("pamixer -d 4 | bar_reset") },
  { MODKEY, XK_equal, spawn, SHCMD ("pamixer -i 4 | bar_reset") },
  { 0, XF86XK_AudioRaiseVolume, spawn, SHCMD ("pamixer -i 4 | bar_reset") },
  { MODKEY, XK_0, spawn, SHCMD ("pamixer -t | bar_reset") },
  { 0, XF86XK_AudioMute, spawn, SHCMD ("pamixer -t | bar_reset") },
  { 0, XF86XK_AudioPlay, spawn, SHCMD ("toggle_music_state") },
  { MODKEY, XK_bracketright, spawn, SHCMD ("toggle_music_state") },
  { 0, XF86XK_MonBrightnessUp, spawn,
    SHCMD ("inc_brightness.sh | bar_reset") },
  { 0, XF86XK_MonBrightnessDown, spawn,
    SHCMD ("dec_brightness.sh | bar_reset") },
  //{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
  //{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
  //{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
  TAGKEYS (XK_1, 0) TAGKEYS (XK_2, 1) TAGKEYS (XK_3, 2) TAGKEYS (XK_4, 3)
      TAGKEYS (XK_5, 4) TAGKEYS (XK_6, 5) TAGKEYS (XK_7, 6) TAGKEYS (XK_8, 7)
          TAGKEYS (XK_9, 8){ MODKEY | ShiftMask, XK_Escape, quit, { 0 } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
  /* click                event mask      button          function argument */
  { ClkClientWin, MODKEY, Button1, movemouse, { 0 } },
  { ClkClientWin, MODKEY, Button2, togglefloating, { 0 } },
  { ClkClientWin, MODKEY, Button3, resizemouse, { 0 } },
  { ClkTagBar, 0, Button1, view, { 0 } },
  { ClkTagBar, 0, Button3, toggleview, { 0 } },
  { ClkStatusText, 0, Button1, spawn, { .v = statuscmd } },
  { ClkStatusText, 0, Button2, spawn, { .v = statuscmd } },
  { ClkStatusText, 0, Button3, spawn, { .v = statuscmd } },
};
