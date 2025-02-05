#include<stdio.h>

using namespace std;

int n, m;
int map[101][101];
int visit[101][101];
int ans = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

#define STACK_SIZE 10000

typedef struct {
    int x[STACK_SIZE];
    int y[STACK_SIZE];
    int top;
} Stack;

// Check cheese is outbound
void dfs(int x, int y)
{
    if (x < 0 || x >= n) return;
    if (y < 0 || y >= m) return;
    if (map[x][y] == 1) return;
    if (visit[x][y]) return;

    map[x][y] = 0;
    visit[x][y] = 1;
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}

int isMelt(int x, int y)
{
    int count = 0;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 0 || xx >= n) continue;
        if (yy < 0 || yy >= m) continue;
        count += map[xx][yy] == 0;
    }

    return count >= 2 ? 1 : 0;
}

int main(void)
{
    Stack s;
    int i, j, k;

    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++) {
        int t;
        for (j=0; j<m; j++) {
            scanf("%d", &t);
            if (t == 1) map[i][j] = 1;
            else map[i][j] = -1;
        }
    }

    map[0][0] = 0;
    dfs(0, 0);

    while(1) {
        // check melted cheese
        int flag = 0;
        for(i = 0; i<n; i++) {
            for(j = 0; j < m; j++) {
                if (map[i][j] == 1) {// cheese
                    flag = 1;
                    if (isMelt(i, j)) {
                        s.x[s.top] = i;
                        s.y[s.top++] = j;
                    }
                }
            }
        }

        while(s.top) {
            map[s.x[s.top - 1]][s.y[s.top - 1]] = 0;
            s.top--;
        }

        // clear visit
        for(i=0; i<n; i++) for(j=0; j<m; j++) visit[i][j]=0;
        dfs(0, 0);

        // printf("\n");
        // for(i=0; i<n; i++) {
        //     for (j=0; j<m; j++) printf("%d ", map[i][j]);
        //     printf("\n");
        // }
        // printf("\n");

        if(!flag) break;
        ans++;
    }
    printf("%d\n", ans);

    return (0);
}