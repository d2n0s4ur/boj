#include<stdio.h>
#include<queue> // using queue

using namespace std;

int N, M;
int b[102];
int d[102];

queue <pair<int, int>> Q;

void bfs()
{
  Q.push(make_pair(1, 0)); // start point

  while (1)
  {
    if (Q.empty()) break;
    int loc = Q.front().first;
    int cnt = Q.front().second;
    Q.pop(); // flush

    for(int i = 1; i <= 6; i++)
    {
      if (loc + i > 100) break;
      int dst = d[loc + i] ? d[loc + i] : loc + i;

      if (!b[dst]) { // visit
        b[dst] = cnt + 1;
        Q.push(make_pair(dst, cnt + 1));
      }
    }
  }
}

int main(void)
{
  int i, x, y;
  scanf("%d %d", &N, &M);

  for (i = 0; i < N; i++)
  {
    scanf("%d %d", &x, &y);
    d[x] = y;
  }
  for (i = 0; i < M; i++)
  {
    scanf("%d %d", &x, &y);
    d[x] = y;
  }
  bfs();

  printf("%d\n", b[100]);
  return (0);
}