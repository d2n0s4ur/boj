#include <stdio.h>
#include <stdlib.h>

using namespace std;

int N;
int item[100001][2];
int ans;

int comp(const void* a, const void* b) {
  const int *rowa = (const int*)a;
  const int *rowb = (const int*)b;

  if (rowa[1] < rowb[1]) return -1;
  if (rowa[1] > rowb[1]) return 1;
  if (rowa[0] < rowb[0]) return -1;
  return 1;
}

int main(void)
{
  int i;
  int last_idx = 0;
  scanf("%d", &N);

  for (i = 0; i< N; i++) {
    scanf("%d %d", &item[i][0] , &item[i][1]);
  }

  // sort with qsort
  qsort(item, N, sizeof(item[0]), comp);

  ans++;
  for (i = 1; i<N; i++) {
    // check possible
    if (item[last_idx][1] <= item[i][0]) {
      ans++;
      last_idx = i;
    }
  }
  printf("%d\n", ans);

  return (0);
}
