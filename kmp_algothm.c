#include <stdio.h>
char p[] = "abcddddddddabcddd7777";
#define CHILDREN_LEN	sizeof(p) / sizeof(*p)	
int m = CHILDREN_LEN;
int b[CHILDREN_LEN + 1] = {0};
void kmpGetNext(void)
{
	int i=0, j=-1;
	b[i]=j;
	while (i<m)
	{
		while (j>=0 && p[i]!=p[j]) j=b[j];
	printf("i:%d\tj:%d\t", i, j);
		i++; j++;
		b[i]=j;
	printf("b[%d]:%d\n", i, b[i]);
	}
	printf("m:%d\n", m);
	return;
}
char t[] = "adjkafjdabcdddksadsaabcddddddddabcddd77777cccfdsafdsafdjsakfdsaabcdddfdsafdsajfkdsajlfkdsa";
#define MOTHER_LEN	sizeof(t) / sizeof(*t)
int n = MOTHER_LEN;
void kmpSearch(void)
{
	int i=0, j=0;
	while (i<n)
	{
		while (j>=0 && t[i]!=p[j]) j=b[j];
		i++; j++;
		printf("i:%d\tj:%d\n", i, j);
		if (j==m)
		{
			printf("\nposition:%d\n", i - j);
			j=b[j];
		}
	}
	printf("n:%d\n", n);
	return;
}

int main(int argc, char *argv[])
{
	kmpGetNext();
	kmpSearch();
	return 0;
}
