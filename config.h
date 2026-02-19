/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
static int fuzzy  = 1;                      /* -F  option; if 0, dmenu doesn't use fuzzy matching */

/* -fn option overrides fonts[0]; default X11 font or font set */
static char font[256] = "MesloLGS:size=12:antialias=true:autohint=true";
static const char *fonts[] = {
    font,
    // All possible combinations just in case
    "MesloLGS:size=12",
    "MesloLGS NF:size=12:antialias=true:autohint=true",
    "MesloLGS NF:size=12",
    "MesloLGS Nerd Font:size=12:antialias=true:autohint=true",
    "MesloLGS Nerd Font:size=12",
    "MesloLG S NF:size=12:antialias=true:autohint=true",
    "MesloLG S NF:size=12",
    "Liberation Mono:size=12:antialias=true:autohint=true",
    "Liberation Mono:size=12",
    "monospace:size=12",
};

static char prompt_buf[256] = {'\0'};
static char *prompt = prompt_buf; /* -p  option; prompt to the left of input field */

static char normfgcolor[] = "#086aab";
static char normbgcolor[] = "#01080b";
static char selfgcolor[]  = "#01080b";
static char selbgcolor[]  = "#02aacd";
static char hlnormfgcolor[]  = "#ffc978";
static char hlnormbgcolor[]  = "#222222";

// TODO more informative color
static char hlselfgcolor[]  = "#df20aa";
static char hlselbgcolor[]  = "#02b0c8";
// static char hlselfgcolor[]  = "#ff2055";
// static char hlselbgcolor[]  = "#0280aa";

static char *colors[SchemeLast][2] = {
	/*     fg         bg       */
	[SchemeNorm] = { normfgcolor, normbgcolor },
	[SchemeSel]  = { selfgcolor,  selbgcolor  },
	[SchemeNormHighlight] = { hlnormfgcolor, hlnormbgcolor },
	[SchemeSelHighlight] = { hlselfgcolor, hlselbgcolor },
	[SchemeOut]  = { "#000000",   "#00ffff" },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
	{ "font",           STRING, font },
	{ "normfgcolor",    STRING, normfgcolor },
	{ "normbgcolor",    STRING, normbgcolor },
	{ "selfgcolor",     STRING, selfgcolor },
	{ "selbgcolor",     STRING, selbgcolor },
	{ "hlnormfgcolor",  STRING, hlnormfgcolor },
	{ "hlnormbgcolor",  STRING, hlnormbgcolor },
	{ "hlselfgcolor",   STRING, hlselfgcolor },
	{ "hlselbgcolor",   STRING, hlselbgcolor },
	{ "prompt",         STRING, prompt_buf },
};
