#include <stdio.h>
#include <vector>
#define MOD 1000000007

using namespace std;

long long int n;
typedef vector<vector<long long>> matrix;

matrix mul(matrix &A, matrix &B)
{
  matrix C = {{0, 0}, {0, 0}};

  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++) {
      for(int k = 0; k < 2; k++) {
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
      }
    }
  }

  return C;
}

int main(void)
{
  matrix mat = {{1, 1}, {1, 0}};
  matrix ans = {{1, 0}, {0, 1}};
  scanf("%lld", &n);
  n--;
  while(n)
  {
    if (n % 2) ans = mul(ans, mat);
    mat = mul(mat, mat);
    n /= 2;
  }
  printf("%lld\n",ans.at(0).at(0));
  return (0);
}