#include<string.h>
#include<stdio.h>

int main()
{
	char *test_str="i am very happy,since tommoror is weekend ya";
	char *next=NULL;
	//running = strdup(test_str);
	do{
		strtok_r(test_str,",",&next);
		fprintf(stderr,"%s\n",test_str);
		//test_str=next;
	}while(test_str !=NULL);
	return 0;
}
