#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void compareFiles(FILE *fp1, FILE *fp2)
{
    char ch1 = getc(fp1);
    char ch2 = getc(fp2);
	int stopper1 = 128; // For next 16 bytes
	int stopper2 = 128; 
	int char_iterator = 0;

    while (ch1 != EOF && ch2 != EOF) 
    {
        if (ch1 == ch2)
        {
            printf("ch1 %c ch2 %c Equal at index %d\n", ch1, ch2, char_iterator);
            char_iterator++;
        }
        else{
            printf("They are not equal here at index %d\n", char_iterator);
            break;
        }

        ch1 = getc(fp1);
        ch2 = getc(fp2);
    }
    
    printf("Printing next %d bits of file 1\n", stopper1);
    
    while (ch1 != EOF && stopper1 > 0)
    {
		ch1 = getc(fp1);
        printf("%c", ch1);
        stopper1--;
	} 

	
	printf("Printing next %d bits of file 2\n", stopper2);
	
    while (ch2 != EOF && stopper2 > 0)
    {
		ch2 = getc(fp2);
        printf("%c", ch2);
        stopper2--;
	} 
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "Usage ./main file1name file2name\n");
		exit(-1);
	}
    
    char filename1[10];
    char filename2[10];
    
    strcpy(filename1, argv[1]);
    strcpy(filename2, argv[2]);
    
    FILE *fp1 = fopen(filename1, "r");
    FILE *fp2 = fopen(filename2, "r");
    
    if (fp1 == NULL || fp2 == NULL)
    {
       printf("Error : Files not open");
       exit(0);
    }

    compareFiles(fp1, fp2);

    fclose(fp1);
    fclose(fp2);
	
	return 0;
}
