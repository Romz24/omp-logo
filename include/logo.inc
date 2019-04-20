#if defined __LOGO_INCLUDED__
	#endinput
#endif
#define __LOGO_INCLUDED__

#include <YSI\y_hooks>

static enum Logo_EData
{
	Float:Logo_EData_PositionX,
	Float:Logo_EData_PositionY,
	Logo_EData_Text[14],
	Float:Logo_EData_TextSizeX,
	Float:Logo_EData_TextSizeY,
	Float:Logo_EData_LetterSizeX,
	Float:Logo_EData_LetterSizeY,
	Logo_EData_Alignment,
	Logo_EData_Color,
	Logo_EData_SetOutline,
	Logo_EData_Font,
	Logo_EData_SetProportional
}

static const Logo_data[][Logo_EData] =
{
	// Logo name
	{
		550.0,				// Position X
		45.0,				// Position Y
		"",					// Text
		1.0,				// Text size X
		1.0,				// Text size Y
		0.4,				// Letter size X
		1.6,				// Letter size Y
		1,					// Alignment,
		0xFFFFFFFF,			// Color
		1,					// Set outline
		1,					// Font
		1,					// Set proportional
	},

	// Server name
	{
		554.0,				// Position X
		28.0,				// Position Y
		"",					// Text
		1.0,				// Text size X
		1.0,				// Text size Y
		0.4,				// Letter size X
		1.6,				// Letter size Y
		1,					// Alignment,
		0x56B3BEFF,			// Color
		1,					// Set outline
		1,					// Font
		1,					// Set proportional
	},

	// Black line
	{
		547.0,				// Position X
		44.0,				// Position Y
		"LD_SPAC:white",	// Text
		60.0,				// Text size X
		3.0,				// Text size Y
		1.0,				// Letter size X
		1.0,				// Letter size Y
		0,					// Alignment,
		0x000000FF,			// Color
		0,					// Set outline
		4,					// Font
		0,					// Set proportional
	},

	// White line
	{
		548.0,				// Position X
		44.0,				// Position Y
		"LD_SPAC:white",	// Text
		58.0,				// Text size X
		1.0,				// Text size Y
		1.0,				// Letter size X
		1.0,				// Letter size Y
		0,					// Alignment,
		0xFFFFFFFF,			// Color
		0,					// Set outline
		4,					// Font
		0,					// Set proportional
	}
};
static const Logo_nameIndex = 0;
static const Logo_serverNameIndex = 1;
static Text:Logo_textDraws[sizeof Logo_data] = { Text:INVALID_TEXT_DRAW, ... };

hook OnPlayerConnect(playerid)
{
	for(new i; i < sizeof Logo_textDraws; i++)
	{
		if (Logo_textDraws[i] != Text:INVALID_TEXT_DRAW)
		{
			TextDrawShowForPlayer(playerid, Logo_textDraws[i]);
		}
	}
	return 1;
}

/// <summary>
/// Show logo with server name
/// </summary>
/// <param name="logoName">Logo name</param>
/// <param name="serverName">Server name</param>
/// <returns>Not "0" if successful, otherwise "0"</returns>
stock Logo_Show(const logoName[], const serverName[])
{
	for(new i; i < sizeof Logo_textDraws; i++)
	{
		if (Logo_textDraws[i] == Text:INVALID_TEXT_DRAW)
		{
			Logo_textDraws[i] = TextDrawCreate(Logo_data[i][Logo_EData_PositionX], Logo_data[i][Logo_EData_PositionY], Logo_data[i][Logo_EData_Text]);
			if (Logo_textDraws[i] == Text:INVALID_TEXT_DRAW)
			{
				Logo_Hide();
				return 0;
			}
			TextDrawLetterSize(Logo_textDraws[i], Logo_data[i][Logo_EData_LetterSizeX], Logo_data[i][Logo_EData_LetterSizeY]);
			TextDrawAlignment(Logo_textDraws[i], Logo_data[i][Logo_EData_Alignment]);
			TextDrawColor(Logo_textDraws[i], Logo_data[i][Logo_EData_Color]);
			TextDrawSetOutline(Logo_textDraws[i], Logo_data[i][Logo_EData_SetOutline]);
			TextDrawFont(Logo_textDraws[i], Logo_data[i][Logo_EData_Font]);
			TextDrawSetProportional(Logo_textDraws[i], Logo_data[i][Logo_EData_SetProportional]);
		}
		if (Logo_nameIndex == i)
		{
			TextDrawSetString(Logo_textDraws[i], logoName);
		}
		else if (Logo_serverNameIndex == i)
		{
			TextDrawSetString(Logo_textDraws[i], serverName);
		}
		TextDrawShowForAll(Logo_textDraws[i]);
	}
	return 1;
}

/// <summary>
/// Hide logo
/// </summary>
stock Logo_Hide()
{
	for(new i; i < sizeof Logo_textDraws; i++)
	{
		if (Logo_textDraws[i] != Text:INVALID_TEXT_DRAW)
		{
			TextDrawDestroy(Logo_textDraws[i]);
			Logo_textDraws[i] = Text:INVALID_TEXT_DRAW;
		}
	}
}
