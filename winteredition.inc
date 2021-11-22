#if defined _winteredition_included
    #endinput
#endif

#define _winteredition_included
#pragma library winteredition

#if !defined _streamer_included
    #error Please include <streamer>.
#endif

#include "./src/we/we_snowobjects.inc"
#include "./src/we/we_snowfalling.inc"
#include "./src/we/we_snowcap.inc"
#include "./src/we/we_coldbreath.inc"