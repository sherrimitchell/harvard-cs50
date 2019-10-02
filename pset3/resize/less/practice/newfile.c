#include <stdio.h>

int int main(void)
{
	/* write a program that creates a simple txt file */

	/* create a file pointer to a data type*/
	/* this is a new file we are creating */

	FILE * fp;

	// we have to open a file and choose what mode we
	// want to be in, which in this case is "w" for write
	// fopen returns a FILE pointer data type which is what
	// we need to do actions like write, read, etc.
	// this file doesn't exist yet so this variable is just
	// an empty bucket until we fill it with data using fwrite

	fp = open("mynewfile.txt", "w");

	// we'll have to some data we want in the file within the array

	char data[] = "nice\n";

	// this is an array ['n','i','c','e'];

	// we'll invoke the fwrite function and pass it
	// the data (array), the size of each element,
	// the total number of elements, and the pointer to the file.
	// In our case,
	// we will use sizeof(array) because we are
	// going to write every char within our array (a string)

	fwrite(data, sizeof(data[0]), sizeof(data), fp);

		fclose(fp);

	return 0;
}
