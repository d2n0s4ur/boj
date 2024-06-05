#include <stdio.h>

using namespace std;

int N;
int a[101];
int b[101];
int ans;

int main(void)
{
  int i;
  scanf("%d", &N);
  for(i = 0; i < N; i++) scanf("%d", &a[i]);
  for(i = 0; i < N; i++) scanf("%d", &b[i]);
  for(i = 0; i < N; i++) {
    if (a[i] > b[i]) ans += 3;
    else if (a[i] == b[i]) ans += 1;
  }
  printf("%d\n", ans);
  return (0);
}
