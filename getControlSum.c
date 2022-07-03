#define _CRT_SECURE_NO_WARNINGS

#include "getControlSum.h"
#include<string.h>

int getControlSum(char * string)
{
	int count = 0;
	for (int i = 0; i < strlen(string); i++)
		count += (string[i]);
	return count;
}
