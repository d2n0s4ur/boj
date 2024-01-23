#include <stdio.h>

int ans;
char input[51];
char *pinput = input;

int parse_int(char *s)
{
	int ret = 0;
	while (*s >= '0' && *s <= '9')
	{
		ret = ret * 10 + (*s - '0');
		s++;
	}

	return ret;
}

int main(void)
{
	int flag = 1;
	scanf("%s", input);
	while (*pinput)
	{
		int tmp = parse_int(pinput);
		while (*pinput >= '0' && *pinput <= '9')
			pinput++;
		if (flag == 0) ans -= tmp;
		else ans += tmp;
		if (*pinput == '-') flag = 0;
		pinput++;
	}
	printf("%d\n", ans);
	return (0);
}