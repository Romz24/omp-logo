#include <logo>

main()
{
    // ...
}

public OnGameModeInit()
{
    Logo_Show("open.~r~mp", "SERVER");
    return 1;
}

public OnGameModeExit()
{
    Logo_Hide();
    return 1;
}
