#include <stdio.h>
#include <queue> // queue
#include <string> // string
#include <cstring> // memset

using namespace std;

int T;
int visited[10001];

void bfs(int A, int B)
{
  int K;
  queue<pair<int, string>> Q;
  memset(visited, 0, sizeof(int) * 10001);

  Q.push(make_pair(A, ""));
  visited[A] = 1;
  while(1)
  {
    int s = Q.front().first;
    string op = Q.front().second;
    Q.pop();

    if (s == B) {
      printf("%s\n", op.c_str());
      return ;
    }

    // D
    K = (s * 2) % 10000;
    if (!visited[K]) {
      Q.push(make_pair(K, op + "D"));
      visited[K] = 1;
    }

    // S
    K = (s - 1) >= 0 ? s - 1 : 9999;
    if (!visited[K]) {
      Q.push(make_pair(K, op + "S"));
      visited[K] = 1;
    }

    // L
    K = (s % 1000) * 10 + s / 1000;
    if (!visited[K]) {
      Q.push(make_pair(K, op + "L"));
      visited[K] = 1;
    }

    // R
    K = s / 10 + (s % 10) * 1000;
    if (!visited[K]) {
      Q.push(make_pair(K, op + "R"));
      visited[K] = 1;
    }
  }

}

int main()
{
  int i, A, B;

  scanf("%d", &T);
  for (i = 0; i < T; i++)
  {
    scanf("%d %d", &A, &B);
    // BFS
    bfs(A, B);
  }

  return (0);
}