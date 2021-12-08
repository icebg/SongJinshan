#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	FILE *fpSrc,*fpDes;
	int ch;

	if( argc != 3 )
	{
		printf("Usage : cp source destination\n");
		exit(-1);
	}
	if ( (fpSrc= fopen(argv[1], "r")) == NULL) {
		perror("Open file source\n");
		exit(1);
	}
	if ( (fpDes= fopen(argv[2], "w")) == NULL) {
		perror("Open file destination\n");
		exit(2);
	}
	while ( (ch = fgetc(fpSrc)) != EOF)
		fputc(ch, fpDes);
	fclose(fpSrc);
	fclose(fpDes);
	return 0;
}
