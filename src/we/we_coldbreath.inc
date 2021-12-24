#if defined _we_coldbreath_included
    #endinput
#endif

#define _we_coldbreath_included
#pragma library we_coldbreath

/**
  * Variables
 */
const WINTER_COLD_BREATH_OBJ_INDEX = 9;

static
    coldBreathTimer[MAX_PLAYERS],
    bool: coldBreathStatus[MAX_PLAYERS];

/**
  * Callbacks
 */
forward __Winter_ColdBreathTimer(const playerid);
public __Winter_ColdBreathTimer(const playerid)
{
    if (Winter_GetColdBreathStatus(playerid) && !GetPlayerInterior(playerid) && !GetPlayerVirtualWorld(playerid))
    {
        RemovePlayerAttachedObject(playerid, WINTER_COLD_BREATH_OBJ_INDEX);
        SetPlayerAttachedObject(playerid, WINTER_COLD_BREATH_OBJ_INDEX, 18696, 2, 0.0, 0.1, -0.2, -25.5000, 0.0, 0.0, 0.10, 0.3, 0.15);
    }

    return 1;
}

/**
  * Functions
 */
stock Winter_GetColdBreathStatus(const playerid) return coldBreathStatus[playerid];
stock Winter_SetColdBreathStatus(const playerid)
{
    new status = !Winter_GetColdBreathStatus(playerid);
   
    if (!status)
    {
        RemovePlayerAttachedObject(playerid, WINTER_COLD_BREATH_OBJ_INDEX);
        coldBreathStatus[playerid] = false;

        KillTimer(coldBreathTimer[playerid]);
        return 1;
    }

    coldBreathStatus[playerid] = true;
    coldBreathTimer[playerid] = SetTimerEx("__Winter_ColdBreathTimer", 2500, 1, "d", playerid);

    return 1;
}