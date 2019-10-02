#include <stdio.h>

int int main(void)
{
	/* I created a .txt file with a poem called poem.txt */

	// I'm going to grab the file and print the entire
	// poem to the terminal

	// first, we'll take our file pointer and get
	// our file using fopen in one slick line
	// we have to be in read mode ("r")

	FILE *fp = fopen("poem.txt", "r");

	// we can pull in one character at a time using fgetc()
	// and we will know when to stop once eof() is true

	// each time getc() is called the index is automagically incremented
	// which is why it goes to the next character without us being involved

	char c;

	while(1){
		if (feof(fp))
		{
			break;
		}

		c = fgetc(fp);

		printf("%c", c);
	}

	printf("\n");

	fclose(fp);

	return 0;
}