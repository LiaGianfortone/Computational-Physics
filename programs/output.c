#include <stdio.h>
#include <stdlib.h>
#define CHECK_BYTE '>'
#define STRING ">>"

int main (int argc, char** argv)
{
	FILE *fp = NULL;
	char *fileBuffer = NULL;
	size_t sizeOfFile = 0;
	char c;
	int i;


	if (argc == 1)
	{
		return 0;
	}

	fp = fopen(argv[1], "r+");

	if (fgetc(fp) == CHECK_BYTE)
	{
		return 0;
	}

	fseek(fp, 0, SEEK_SET);
	for(sizeOfFile = 0; (fgetc(fp) != EOF); sizeOfFile++);
	fileBuffer = (char*)malloc(sizeOfFile + 1);
	
	fseek(fp, 0, SEEK_SET);
	for(i = 0; (c = fgetc(fp) != EOF); i++)
	{
		fileBuffer[i] = c;
	}
	fileBuffer[i+1] = '\0';
	fseek(fp, 0, SEEK_SET);
	fprintf(fp, ">>%s", fileBuffer);


	fclose(fp);
	return 0;
}