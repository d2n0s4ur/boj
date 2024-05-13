#include<stdio.h>
#define R 0
#define G 1
#define B 2

using namespace std;

int DP[1001][4];
int cost[1001][4];
int N;
int ans = -1;

int min(int a, int b)
{
  if (a < b) return a;
  return b;
}

int main(void)
{
  int i;

  scanf("%d", &N);
  for(i = 0; i < N; i++) scanf("%d %d %d", &cost[i][R], &cost[i][G], &cost[i][B]);
  DP[0][R] = cost[0][R];
  DP[0][G] = cost[0][G];
  DP[0][B] = cost[0][B];

  for(i = 1; i < N; i++) {
    DP[i][R] = min(DP[i-1][G], DP[i-1][B]) + cost[i][R];
    DP[i][G] = min(DP[i-1][R], DP[i-1][B]) + cost[i][G];
    DP[i][B] = min(DP[i-1][R], DP[i-1][G]) + cost[i][B];
  }
  ans = DP[N - 1][0];
  for(i = 1; i < 3; i++){
    if (DP[N - 1][i] < ans) ans = DP[N - 1][i];
  }
  printf("%d\n", ans);
  return (0);
}