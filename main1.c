#include <stdio.h>
#include <stdarg.h>
 
void test(int num, ...)
{
 
    va_list valist;
 
    va_start(valist, num);

	char *p1 = va_arg(valist, char *);
	char *p2 = va_arg(valist, char *);
	char *p3 = va_arg(valist, char *);

	*p1 = 7;
	*p2 = 8;
	*p3 = 9;

    va_end(valist);
}
 
int driver(int a, char *p1, char *p2, char *p3)
{
	test(a, p1, p2, p3);
	if (a > 0)
		printf("a is greater than 0\n");
	else {
		if (*p1 > 10)
			printf("p1 is greater than 10\n");
		else {
			if (*p2 > 8)
				printf("p2 is greater than 8\n");
			else {
				if (*p3 > 16)
					printf("p3 is greater than 16\n");
				else 
					printf("bug here\n");
			}
		}
	}
	printf("%d\n", *p1);
	printf("%d\n", *p2);
	printf("%d\n", *p3);

	return 0;
}

int main()
{
	char b = 11;
	char c = 12;
	char d = 13;

	driver(11, &b, &c, &d);
}
