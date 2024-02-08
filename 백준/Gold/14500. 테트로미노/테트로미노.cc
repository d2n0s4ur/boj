#include <stdio.h>

int N, M;
int p[501][501];
int visit[501][501];
int ans;

void dfs(int x, int y, int d, int val)
{
  if (d == 4)
  {
    ans = ans > val ? ans : val;
    return;
  }
  if (x - 1 >= 0 && !visit[x - 1][y])
  {
    visit[x - 1][y] = 1;
    dfs(x - 1, y, d + 1, val + p[x - 1][y]);
    visit[x - 1][y] = 0;
  }
  if (x + 1 < N && !visit[x + 1][y])
  {
    visit[x + 1][y] = 1;
    dfs(x + 1, y, d + 1, val + p[x + 1][y]);
    visit[x + 1][y] = 0;
  }
  if (y - 1 >= 0 && !visit[x][y - 1])
  {
    visit[x][y - 1] = 1;
    dfs(x, y - 1, d + 1, val + p[x][y - 1]);
    visit[x][y - 1] = 0;
  }
  if (y + 1 < M && !visit[x][y + 1])
  {
    visit[x][y + 1] = 1;
    dfs(x, y + 1, d + 1, val + p[x][y + 1]);
    visit[x][y + 1] = 0;
  }
}

int check_O_shape(int x, int y)
{
  int k = 0;
  int w = p[x - 1][y] + p[x + 1][y] + p[x][y - 1] + p[x][y + 1] + p[x][y];
  // ㅗ
  if (y - 1 >= 0 && y + 1 < M && x - 1 >= 0)
    k = k > w - p[x + 1][y] ? k : w - p[x + 1][y];
  // ㅓ
  if (y - 1 >= 0 && x - 1 >= 0 && x + 1 < N)
    k = k > w - p[x][y + 1] ? k : w - p[x][y + 1];
  // ㅜ
  if (y - 1 >= 0 && y + 1 < M && x + 1 < N)
    k = k > w - p[x - 1][y] ? k : w - p[x - 1][y];
  // ㅏ
  if (x - 1 >= 0 && x + 1 < N && y + 1 < M)
    k = k > w - p[x][y - 1] ? k : w - p[x][y - 1];
  return k;
}

int main()
{
  int i, j;
  scanf("%d %d", &N, &M);

  for (i = 0; i < N; i++)
  {
    for (j = 0; j < M; j++)
      scanf("%d", &p[i][j]);
  }
  for (i = 0; i < N; i++)
  {
    for (j = 0; j < M; j++)
    {
      dfs(i, j, 0, 0);
      // check ㅗ shape
      int tmp = check_O_shape(i, j);
      ans = ans > tmp ? ans : tmp;
    }
  }
  printf("%d\n", ans);
  return (0);
}