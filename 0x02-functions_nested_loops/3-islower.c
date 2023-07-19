#include "main.h"
/**
*_islower - show 1 if input is in lowercase, other cases, show 0
* @c: ASCII character
* Return: 1 when in lowercase, otheris 0
*/
int _islower(int c)
{
if (c >= 97 && c <= 122)
{
return (1);
}
else
{
return (0);
}
}
