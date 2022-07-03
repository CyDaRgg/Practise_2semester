#include"receivingExistAsciiCode.h"
char receivingExistAsciiCode(int x)
{
	x += 122;
	while (!(((x >= 48) && (x <= 57)) || ((x >= 65) && (x <= 90)) || ((x >= 97) && (x <= 122))))
		x -= 46;
	return x;
}