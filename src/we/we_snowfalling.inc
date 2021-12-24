#if defined _we_snowfalling_included
    #endinput
#endif

#define _we_snowfalling_included
#pragma library we_snowfalling

/**
  * Variables
 */
static
    snowObject[MAX_PLAYERS],
    snowFallingTimer[MAX_PLAYERS],

    bool: snowFallingStatus[MAX_PLAYERS];

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
            
	       	MovePlayerObject(playerid, snowObject[playerid],
                Float: x, Float: y, (Float:z - 2.5), Float: 4000.0
            );
  	 	}
	}

    return 1;
}

/**
  * Functions
 */
stock Winter_GetSnowflakeStatus(const playerid) return snowFallingStatus[playerid];
stock Winter_SetSnowflakeStatus(const playerid)
{
    new const status = !Winter_GetSnowflakeStatus(playerid);

    if (!status)
    {
        snowFallingStatus[playerid] = false;
        DestroyPlayerObject(playerid, snowObject[playerid]);
        KillTimer(snowFallingTimer[playerid]);
        return 1;
    }

    static x, y, z;
    GetPlayerCameraPos(playerid, Float: x, Float: z, Float: z);

    snowObject[playerid] = CreatePlayerObject(playerid, 18864,
        (Float: x + random(25)), (Float: y + random(25)), (Float: z - 5), 0.0, 0.0, 0.0, 300.0
    );

    snowFallingTimer[playerid] = SetTimerEx("__Winter_SnowFallingTimer", 500, 1, "d", playerid);
    snowFallingStatus[playerid] = true;

    return 1;
}