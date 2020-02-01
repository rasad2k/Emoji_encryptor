#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{

	char * dict[][2] = { 
		{"a",":D"},
		{"b",":P"},
		{"c",":("}, 
		{"d",":)"},
		{"e",":|]"},
		{"f",":3"},
		{"g",":v"},
		{"h",">:O"},
		{"i","o.O"},
		{"j","-_-"},
		{"k","^_^"},
		{"l","<3"},
		{"m",":-*"},
		{"n","O:)"},
		{"o","3:)"},
		{"p",":'("},
		{"q",":/"},
		{"r",">:("},
		{"s","8-|"},
		{"t","8-)"},
		{"u",";-)"},
		{"v",":-O"},
		{"w",":-D"},
		{"x",":-P"},
		{"y",":-("},
		{"z",":-)"}
	};

	for (int i = 0; i < 26; i++)
	{
		printf("[%2d]: %s -> %3s\n", i, dict[i][0], dict[i][1]);
	}

	char * table[27][27];
	table[0][0] = "0";
	for (int i = 0; i < 26; i++)
	{
		table[i+1][0] = dict[i][1];
		table[0][i+1] = dict[i][1];
	}	

	printf("\n");
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			table[i+1][(j+26-i+1)%26+1] = dict[(j+17)%26][1];
		}
	}

	// for (int i = 0; i < 27; i++)
	// {
	// 	printf("[%2d]:", i);
	// 	for (int j = 0; j < 27; j++)
	// 	{
	// 		printf(" %3s ", table[i][j]);
	// 	}
	// 	printf("\n");
	// }


	char key[50], text[1000];
	printf("Please enter the key and the text: ");
	scanf("%s %[^\n]s", key, text);
	char * encrypt = (char *)malloc(4000);
	char * tmp = (char *)malloc(10);
	int keyIndex, textIndex;
	for (int i = 0; i < strlen(text); i++)
	{
		if (text[i] == ' ')
		{
			strcat(encrypt, "   ");
			continue;
		}
		keyIndex = key[i%(strlen(key))] - 96;
		textIndex = text[i%26] - 96;
		if (text[i] < 'a')
			textIndex = text[i%26] - 64;

		if (key[i%strlen(key)] < 'a')
			keyIndex = key[i%strlen(key)] - 64;
		tmp = table[keyIndex][textIndex];
		strcat(encrypt, tmp);
		strcat(encrypt, " ");
	}
	printf("Encrypted text for '%s' is %s\n", text, encrypt);
	

	return 0;
}