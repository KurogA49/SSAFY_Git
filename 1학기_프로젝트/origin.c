#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fullwrite();
void fullread();
void getRead(char *lineNumber);
void setNand(char *lineNumber, char *input);

int cmp(char left[], char right[])
{
	return strcmp(left, right) == 0;
}

void fullwrite()
{
	FILE *tmp = fopen("nand.txt", "w");
	for (int i = 0; i < 100; i++)
	{
		fprintf(tmp, "0xABCDFFFF\n");
	}
	fclose(tmp);
}

void fullread()
{
	for (int i = 0; i < 100; i++)
	{
		char lineNumber[3];
		snprintf(lineNumber, sizeof(lineNumber), "%d", i);
		getRead(lineNumber);
	}
}

void getRead(char *lineNumber)
{
	FILE *fp = fopen("nand.txt", "r");
	FILE *result = fopen("result.txt", "w");

	char buf[12];
	for (int i = 0; i <= 99; i++)
	{
		memset(buf, 0, sizeof(buf));
		fgets(buf, 12, fp);
		if (i == atoi(lineNumber))
		{
			fprintf(result, "%s", buf);
			break;
		}
	}
	fclose(fp);
	fclose(result);
}

void setNand(char *lineNumber, char *input)
{
	FILE *fp = fopen("nand.txt", "r");
	FILE *tmp = fopen("temp.txt", "w");
	char bf[12];
	int cnt = 0;

	while (1)
	{
		fgets(bf, 12, fp);
		if (feof(fp))
			break;
		if (cnt == atoi(lineNumber))
			fprintf(tmp, "%s\n", input);
		else
			fprintf(tmp, "%s", bf);
		cnt++;
	}

	fclose(fp);
	fclose(tmp);

	remove("nand.txt");
	rename("temp.txt", "nand.txt");
}

int main(int argc, char* argv[])
{
	// 디버그를 위한 argv 설정
	// argv[1] = "W";
	// argv[2] = "20";
	// argv[3] = "0xABCD1234";

	// 커맨드 변수
	char* mode = argv[1];

	if (cmp(mode, "W"))
		setNand(argv[2], argv[3]);

	if (cmp(mode, "R"))
		read(argv[2]);

	if (cmp(mode, "fullwrite"))
		fullwrite();

	if (cmp(mode, "fullread"))
		fullread();

	if (cmp(mode, "testapp1"))
	{
		fullwrite();
		fullread();
	}

	if (cmp(mode, "testapp2"))
	{
		for (int i = 0; i < 30; i++)
		{
			FILE* tmp = fopen("nand.txt", "r+t");
			for (int j = 0; j < 6; j++)
			{
				fseek(tmp, j, SEEK_SET);
				char* str = "0xAAAABBBB\n";
				fwrite(str, sizeof(char), strlen(str), tmp);
			}
			fclose(tmp);
		}

		FILE* tmp = fopen("nand.txt", "r+t");
		for (int i = 0; i < 6; i++)
		{
			fseek(tmp, i, SEEK_SET);
			char* str = "0x12345678\n";
			fwrite(str, sizeof(char), strlen(str), tmp);
		}
		fclose(tmp);

		for (int i = 0; i < 6; i++)
		{
			char lineNumber[3];
			snprintf(lineNumber, sizeof(lineNumber), "%d", i);
			getRead(lineNumber);
		}
	}

	return 0;
}