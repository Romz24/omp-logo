new Text:Logo[4];

public OnGameModeInit() {
	Logo[0] = TextDrawCreate(550.0, 45.0, "Open.~r~MP"); // Open.MP
	TextDrawLetterSize(Logo[0], 0.4, 1.6);
	TextDrawAlignment(Logo[0], 1);
	TextDrawColor(Logo[0], -1);
	TextDrawSetOutline(Logo[0], 1);
	TextDrawFont(Logo[0], 1);
	TextDrawSetProportional(Logo[0], 1);

	Logo[1] = TextDrawCreate(554.0, 28.0, "SERVER"); // Server name
	TextDrawLetterSize(Logo[1], 0.4, 1.6);
	TextDrawAlignment(Logo[1], 1);
	TextDrawColor(Logo[1], 1454620415);
	TextDrawSetOutline(Logo[1], 1);
	TextDrawFont(Logo[1], 1);
	TextDrawSetProportional(Logo[1], 1);

	Logo[2] = TextDrawCreate(547.0, 43.0, "LD_SPAC:white"); // Black line
	TextDrawTextSize(Logo[2], 60.0, 3.0);
	TextDrawColor(Logo[2], 255);
	TextDrawFont(Logo[2], 4);

	Logo[3] = TextDrawCreate(548.0, 44.0, "LD_SPAC:white"); // White line
	TextDrawTextSize(Logo[3], 58.0, 1.0);
	TextDrawColor(Logo[3], -1);
	TextDrawFont(Logo[3], 4);

	#if defined logo_OnGameModeInit
		return logo_OnGameModeInit();
	#else
		return 1;
	#endif
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit logo_OnGameModeInit
#if defined logo_OnGameModeInit
	forward logo_OnGameModeInit();
#endif

public OnPlayerConnect(playerid) {
	for(new i = 0; i < sizeof(Logo); i++) {
		TextDrawShowForPlayer(playerid, Logo[i]);
	}

	#if defined logo_OnPlayerConnect
		return logo_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect logo_OnPlayerConnect
#if defined logo_OnPlayerConnect
	forward logo_OnPlayerConnect(playerid);
#endif
