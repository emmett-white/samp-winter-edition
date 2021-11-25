#if defined _we_snowfalling_included
    #endinput
#endif

#define _we_snowfalling_included
#pragma library we_snowfalling

/**
  * Variables
 */
static
    __g_snowObject[MAX_PLAYERS],
    __g_snowFallingTimer[MAX_PLAYERS],

    bool: __g_snowObjectCreated[MAX_PLAYERS],
    bool: __g_snowFallingStatus[MAX_PLAYERS];

/**
  * Callbacks
 */
forward __Winter_SnowFallingTimer(const playerid);
public __Winter_SnowFallingTimer(const playerid)
{
    if (Winter_GetSnowflakeStatus(playerid))
    {
 		if (!GetPlayerInterior(playerid) && !GetPlayerVirtualWorld(playerid))
        {
			static x, y, z;
	       	GetPlayerCameraPos(playerid, Float: x, Float: y, Float:z);
            
	       	MovePlayerObject(playerid, __g_snowObject[playerid],
                Float: x, Float: y, (Float:z - 2.5), Float: 4000.0
            );
  	 	}
	}

    return 1;
}

/**
  * Functions
 */
stock Winter_GetSnowflakeStatus(const playerid) return __g_snowFallingStatus[playerid];
stock Winter_SetSnowflakeStatus(const playerid, bool: status = true)
{
    if (!status)
    {
        if (!__g_snowObjectCreated[playerid])
        {
            return 0;
        }

        __g_snowFallingStatus[playerid] = false;
        DestroyPlayerObject(playerid, __g_snowObject[playerid]);
        KillTimer(__g_snowFallingTimer[playerid]);
        return 1;
    }

    if (__g_snowObjectCreated[playerid])
    {
        return 0;
    }

    static x, y, z;
    GetPlayerCameraPos(playerid, Float: x, Float: z, Float: z);

    __g_snowObject[playerid] = CreatePlayerObject(playerid, 18864,
        (Float: x + random(25)), (Float: y + random(25)), (Float: z - 5), 0.0, 0.0, 0.0, 300.0
    );

    __g_snowFallingTimer[playerid] = SetTimerEx("__Winter_SnowFallingTimer", 500, 1, "d", playerid);
    __g_snowFallingStatus[playerid] = true;

    return 1;
}