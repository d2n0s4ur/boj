#include <stdio.h>
#include <queue>
using namespace std;

int N, K;
int b[100001];
queue <int> Q;
int ans;

int main(void)
{
  scanf("%d %d", &N, &K);
  b[N] = 0;
  Q.push(N);

  while (1)
  {
    // pop
    int x = Q.front();
    Q.pop();

    if (x == K) break;
    if (x < 0 || x > 100000) continue;

    // search
    if (!b[x - 1] && x - 1 >= 0) {
      b[x - 1] = b[x] + 1;
      Q.push(x - 1);
    }
    if (!b[x + 1] && x + 1 <= 100000) {
      b[x + 1] = b[x] + 1;
      Q.push(x + 1);
    }
    if (x * 2 <= 100000 && !b[2 * x]) {
      b[2 * x] = b[x] + 1;
      Q.push(2 * x);
    }
  }
  printf("%d\n", b[K]);

  return (0);
}