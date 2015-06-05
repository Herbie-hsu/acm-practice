#include "stdio.h"
#include "string.h"

int main()
{
	int len;
	char *ctr;
	char ptr[100];
	len=snprintf(ptr,len,"aaa");
	snprintf(ptr+len,100-len,"bbb");
	printf("%s\n",ptr);
	return 0;
}
