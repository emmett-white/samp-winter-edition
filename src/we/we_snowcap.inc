#if defined _we_snowcap_included
    #endinput
#endif

#define _we_snowcap_included
#pragma library we_snowcap

/**
  * Variables
 */
const WINTER_SNOW_CAP_INDEX = 3;
static bool: __g_snowCapStatus[MAX_PLAYERS];

/**
  * Functions
 */
stock Winter_GetSnowCapStatus(const playerid) return __g_snowCapStatus[playerid];
stock Winter_SetSnowCapStatus(const playerid, bool: status = true)
{
    if (!status)
    {
        RemovePlayerAttachedObject(playerid, WINTER_SNOW_CAP_INDEX);
        __g_snowCapStatus[playerid] = false;
        return 1;
    }

    // Attach winter cap to head
    SetPlayerAttachedObject(playerid, WINTER_SNOW_CAP_INDEX, 19065, 2, 0.120000, 0.040000, -0.003500, 0, 100, 100, 1.4, 1.4, 1.4);
    __g_snowCapStatus[playerid] = true;

    return 1;
}