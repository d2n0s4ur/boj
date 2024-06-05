#include <stdio.h>

using namespace std;

unsigned long long a, b, c, n;
int ans[11];

int main(void)
{
  scanf("%llu %llu %llu", &a, &b, &c);
  n = a * b * c;
  while(1) {
    if (n == 0) break;
    ans[n % 10]++;
    n /= 10;
  }
  for(int i =0; i < 10; i++) printf("%d\n", ans[i]);
  return (0);
}
