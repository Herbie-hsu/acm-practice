#include<stdio.h>
#include<string.h>

int main()
{
	char str[100];
	char *str1;
	fprintf(stderr,"please enter one string...\n");
	scanf("%[^\n]",str);
	printf("%s\n",str);
	str1=strchr(str,'-');
	printf("%d:%s\n",str1-str,str1);
	return 0;
}
