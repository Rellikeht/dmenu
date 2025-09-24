/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1; /* -b  option; if 0, dmenu appears at bottom     */

#ifdef __linux__
static const char *fonts[] = {
    //	"xft:MesloLGS NF:size=10"
    //	"monospace:size=10"
    "MesloLGS NF:pixelsize=13:antialias=true:autohint=true"};

#else
static const char *fonts[] = {
    "MesloLGS:pixelsize=13:antialias=true:autohint=true"};
#endif

static const char *prompt =
    NULL; /* -p  option; prompt to the left of input field */
static const char *colors[SchemeLast][2] = {
    /*     fg         bg       */
    [SchemeNorm] = {"#086aab", "#01080b"},
    [SchemeSel] = {"#01080b", "#02aacd"},
    [SchemeOut] = {"#000000", "#00ffff"},
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
