#include <stdio.h>

typedef struct loc {
    int x;
    int y;
}   loc;

typedef struct Queue {
    loc data[1000001];
    int front, back;
}   Queue;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ans;
int b[1001][1001];
int n, m;

int isValid(int x, int y)
{
    if (x < 0 || x >= m || y < 0 || y >= n)
        return (0);
    return (1);
}

int main()
{
    Queue q;
    
    q.front = -1;
    q.back = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &b[i][j]);
            if (b[i][j] == 1)
            {
                q.data[++q.back].x = i;
                q.data[q.back].y = j;
            }
        }
    }
    while (q.front < q.back)
    {
        int x = q.data[++q.front].x;
        int y = q.data[q.front].y;

        for (int i = 0; i < 4; i++)
        {
            if (isValid(x + dx[i], y + dy[i]) && !b[x + dx[i]][y + dy[i]])
            {
                b[x + dx[i]][y + dy[i]] = b[x][y] + 1;
                q.data[++q.back].x = x + dx[i];
                q.data[q.back].y = y + dy[i];
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (b[i][j] == 0)
            {
                printf("-1\n");
                return (0);
            }
            if (ans < b[i][j])
                ans = b[i][j];
        }
    }
    printf("%d\n", ans - 1);
    return (0);
}