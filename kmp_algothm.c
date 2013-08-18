#include <stdio.h>
char p[] = "abcddddddddabcddd7777";
#define CHILDREN_LEN	(sizeof(p) / sizeof(*p) - 1)
int m = CHILDREN_LEN;
int b[CHILDREN_LEN + 1] = {0};
void kmpGetNext(void)
{
	int i = 0, j = -1;
	b[i] = j;
	while (i < m)
	{
		while (j >= 0 && p[i] != p[j])
			j = b[j];
#if 0
	printf("i:%d\tj:%d\t", i, j);
#endif
		i++;
		j++;
		b[i] = j;
#if 0
	printf("b[%d]:%d\n", i, b[i]);
#endif
	}
#if 0
	printf("m:%d\n", m);
#endif
	return;
}
char t[] = "adjkafjdabcdddksadsaabcddddddddabcddd77777cccfdsafdsafdjsakfdsaabcdddfdsafdsajfkdsajlfkdsa";
#define MOTHER_LEN	(sizeof(t) / sizeof(*t) - 1)
int n = MOTHER_LEN;
void kmpSearch(void)
{
	int i = 0, j = 0;
	while (i < n)
	{
		while (j >= 0 && t[i] !=p [j])
			j =b [j];
		i++;
		j++;
#if 0
		printf("i:%d\tj:%d\n", i, j);
#endif
		if (j == m)
		{
#if 0
			printf("position:%d\n", i - j);
			printf("t:%s\n", &t[i - j]);
#endif
			j = b[j];
		}
	}
#if 0
	printf("n:%d\n", n);
#endif
	return;
}
char t2[] = "1adjkafjdabcdddksadsaabcddddddddabcddd77777cccfdsafdsafdjsakfdsaabcdddfdsafdsajfkdsajlfkds";
void kmpSearch2(void)
{
	int i = 0, j = 0;
	while (i < n)
	{
		while (j >= 0 && t2[i] !=p [j])
			j = b[j];
		i++;
		j++;
#if 0
		printf("i:%d\tj:%d\n", i, j);
#endif
		if (j == m)
		{
#if 0
			printf("position:%d\n", i - j);
#endif
			j = b[j];
		}
	}
#if 0
	printf("n:%d\n", n);
#endif
	return;
}

int main(int argc, char *argv[])
{
	kmpGetNext();
	kmpSearch();
	kmpSearch2();
	return 0;
}
