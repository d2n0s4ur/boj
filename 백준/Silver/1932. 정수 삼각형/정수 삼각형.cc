#include<stdio.h>

using namespace std;

int dp[501][501];
int t[501][501];
int n;

int max(int a, int b)
{
  if(a>b) return a;
  return b;
}

int main(void)
{
  int i, j;
  scanf("%d", &n);

  for(i = 0; i < n; i++) {
    for(j = 0; j < i + 1; j++) scanf("%d", &t[i][j]);
  }

  for(i=0; i < n; i++) dp[n - 1][i] = t[n - 1][i];
  // DP
  for(i = n - 2; i >= 0; i--) {
    for(j = 0; j < i + 1; j++) {
      dp[i][j] = t[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
    }
  }
  printf("%d\n", dp[0][0]);
  return(0);
}