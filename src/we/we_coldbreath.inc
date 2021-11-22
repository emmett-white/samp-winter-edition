#if defined _we_coldbreath_included
    #endinput
#endif

#define _we_coldbreath_included
#pragma library we_coldbreath

/**
  * Variables
 */
const WINTER_COLD_BREATH_OBJ_INDEX = 4;

static
    __g_coldBreathTimer[MAX_PLAYERS],
    bool: __g_coldBreathStatus[MAX_PLAYERS];

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
stock Winter_GetColdBreathStatus(const playerid) return __g_coldBreathStatus[playerid];
stock Winter_SetColdBreathStatus(const playerid, bool: status = true)
{
    if (!status)
    {
        RemovePlayerAttachedObject(playerid, 4);
        __g_coldBreathStatus[playerid] = false;

        KillTimer(__g_coldBreathTimer[playerid]);
        return 1;
    }

    __g_coldBreathStatus[playerid] = true;
    __g_coldBreathTimer[playerid] = SetTimerEx("__Winter_ColdBreathTimer", 2500, 1, "d", playerid);

    return 1;
}