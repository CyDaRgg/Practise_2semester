#define _CRT_SECURE_NO_WARNINGS

#include "Hash.h"
#include"getControlSum.h"
#include"receivingExistAsciiCode.h"
#include <stdlib.h>
#include <string.h>
char * Hash(char * userLogin, char * userPassword, int lengthOfHash)
{
	char codeSymbol[2];
	codeSymbol[1] = '\0';

	char*userLoginAndPassword;
	userLoginAndPassword = (char*)calloc(strlen(userLogin) + strlen(userPassword) + 1, sizeof(char));
	strcat(userLoginAndPassword, userLogin);
	strcat(userLoginAndPassword, userPassword);

	char* hash;
	hash = (char*)calloc(1, sizeof(char));

	int minLen = 2;//Минимальная длина строки хеша, кратная двум
	int realMinLen = 0;//Длина строки, ближайшая к нужной длине хеша

	int originalSault = getControlSum(userLoginAndPassword);
	int originalLenghtStr = strlen(userLoginAndPassword);

	while (minLen <= lengthOfHash) realMinLen = (minLen *= 2);
	while (minLen < originalLenghtStr) minLen *= 2;

	minLen *= 2; //Делаем длину строки хеша, как минимум, в 2 раза длинней оригинальной строки 

	int addCount = minLen - originalLenghtStr;
	for (int i = 0; i < addCount; i++)
	{
		codeSymbol[0] = receivingExistAsciiCode(userLoginAndPassword[i] + userLoginAndPassword[i + 1]);
		userLoginAndPassword = (char*)realloc(userLoginAndPassword, strlen(userLoginAndPassword) + 2);
		strcat(userLoginAndPassword, codeSymbol);
	}
	int maxSault = getControlSum(userLoginAndPassword);
	int maxLenghStr = strlen(userLoginAndPassword);
	while (strlen(userLoginAndPassword) != realMinLen)
	{
		for (int i = 0, center = strlen(userLoginAndPassword) / 2; i < center; i++)
		{
			codeSymbol[0] = receivingExistAsciiCode(userLoginAndPassword[center - i] + userLoginAndPassword[center + i]);
			hash = (char*)realloc(hash, strlen(hash) + 2);
			strcat(hash, codeSymbol);
		}
		strcpy(userLoginAndPassword, hash);
		hash = (char*)realloc(hash, 1);
		hash[0] = '\0';
	}
	int correction = realMinLen - lengthOfHash;
	for (int i = 0, countCompress = realMinLen / correction; strlen(hash) < (lengthOfHash - 4); i++)
	{
		if (i%countCompress == 0)
		{
			codeSymbol[0] = receivingExistAsciiCode(userLoginAndPassword[i] + userLoginAndPassword[++i]);
			hash = (char*)realloc(hash, strlen(hash) + 2);
			strcat(hash, codeSymbol);
		}
		else
		{
			codeSymbol[0] = userLoginAndPassword[i];
			hash = (char*)realloc(hash, strlen(hash) + 2);
			strcat(hash, codeSymbol);
		}

	}
	codeSymbol[0] = receivingExistAsciiCode(originalSault);
	hash = (char*)realloc(hash, strlen(hash) + 2);
	strcat(hash, codeSymbol);

	codeSymbol[0] = receivingExistAsciiCode(originalLenghtStr);
	hash = (char*)realloc(hash, strlen(hash) + 2);
	strcat(hash, codeSymbol);

	codeSymbol[0] = receivingExistAsciiCode(maxSault);
	hash = (char*)realloc(hash, strlen(hash) + 2);
	strcat(hash, codeSymbol);

	codeSymbol[0] = receivingExistAsciiCode(maxLenghStr);
	hash = (char*)realloc(hash, strlen(hash) + 2);
	strcat(hash, codeSymbol);
	return hash;
}
