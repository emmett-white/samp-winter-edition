# samp-winter-edition

[![sampctl](https://img.shields.io/badge/sampctl-samp--winter--edition-2f2f2f.svg?style=for-the-badge)](https://github.com/emmett-white/samp-winter-edition)

## Installation

Simply install to your project:

```bash
sampctl package install emmett-white/samp-winter-edition
```

Include in your code and begin using the library:

```c
#include <winteredition>
```

## Usage

### Functions
- Snowflakes
```c
stock Winter_SetSnowflakeStatus(const playerid, bool: status = true)
stock Winter_GetSnowflakeStatus(const playerid) return __g_snowFallingStatus[playerid];

// Example
CMD:snowflakes(playerid, const string: params[])
{
    Winter_SetSnowflakeStatus(playerid, (Winter_GetSnowflakeStatus(playerid) ? (false) : (true)));

    return 1;
}
```

- Snow objects (LOS SANTOS :c)
```c
stock Winter_ShowSnowObjects(const playerid, bool: status = true)
stock Winter_GetSnowObjStatus(const playerid) return __g_snowObjStatus[playerid];

// Example
CMD:snowobjects(playerid, const string: params[])
{
    Winter_ShowSnowObjects(playerid, (Winter_GetSnowObjStatus(playerid) ? (false) : (true)));

    return 1;
}
```

- Winter cap
```c
stock Winter_SetSnowCapStatus(const playerid, bool: status = true)
stock Winter_GetSnowCapStatus(const playerid) return __g_snowCapStatus[playerid];

// Example
CMD:cap(playerid, const string: params[])
{
    Winter_SetSnowCapStatus(playerid, (Winter_GetSnowCapStatus(playerid) ? (false) : (true)));

    return 1;
}
```

- Cold breath
```c
stock Winter_SetColdBreathStatus(const playerid, bool: status = true)
stock Winter_GetColdBreathStatus(const playerid) return __g_coldBreathStatus[playerid];

// Example
CMD:coldbreath(playerid, const string: params[])
{
    Winter_SetColdBreathStatus(playerid, (Winter_GetColdBreathStatus(playerid) ? (false) : (true)));

    return 1;
}
```

## Testing

To test, simply run the package:

```bash
sampctl package run
```
