#include <stdio.h>

using namespace std;

long long int n;
long long int ans;

int main(void)
{
  scanf("%lld", &n);
  ans = n * (n-1) * (n-2) / 6;
  printf("%lld\n3\n", ans);
  return (0);
}
