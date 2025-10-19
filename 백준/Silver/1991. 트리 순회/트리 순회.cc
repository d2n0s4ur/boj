#include <stdio.h>

int tree[27][2];
int N;

void print_n(int x)
{
    printf("%c", x + 'A');
}

void f(int x, int order)
{
    if (x == -1)
        return;
    int left = tree[x][0];
    int right = tree[x][1];

    if (left == -1 && right == -1)
    {
        print_n(x);
        return;
    }

    switch (order)
    {
    case 0:
        print_n(x);
        f(left, order);
        f(right, order);
        break;
    case 1:
        f(left, order);
        print_n(x);
        f(right, order);
        break;
    case 2:
        f(left, order);
        f(right, order);
        print_n(x);
        break;
    }
}

int main()
{
    int i;
    char c1, c2, c3;

    scanf("%d\n", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%c %c %c\n", &c1, &c2, &c3);
        tree[c1 - 'A'][0] = (c2 == '.' ? -1 : c2 - 'A');
        tree[c1 - 'A'][1] = (c3 == '.' ? -1 : c3 - 'A');
    }
    f(0, 0);
    printf("\n");
    f(0, 1);
    printf("\n");
    f(0, 2);
    printf("\n");
    return 0;
}