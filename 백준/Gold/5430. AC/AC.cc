#include <stdio.h>
#include <queue> // queue
#include <stdlib.h> // malloc
#include <string.h> // memset

using namespace std;

int T;
int n;

void  f()
{
  deque <int> Q;
  int dir = 1;
  int i;
  char *cmd;
  char tmp;
  char *arr;

  cmd = (char *)malloc(sizeof(char) * 100001);
  arr = (char *)malloc(sizeof(char) * 400004);
  if(!cmd || !arr) return;
  memset(cmd, 0, sizeof(char) * 100001);
  memset(arr, 0, sizeof(char) * 400004);

  scanf("%s", cmd);
  scanf("%d", &n);
  scanf("%s", arr);

  i = 1;
  while(n--)
  {
    int r = 0;
    while(!(arr[i] == ',' || arr[i] == ']')) {
      r = r * 10 + (arr[i] - '0');
      i++;
    }
    Q.push_back(r);
    i++;
  }
  free(arr);
  i = 0;
  while (cmd[i])
  {
    if (cmd[i] == 'R') dir *= -1;
    else {
      if (Q.empty()) {
        printf("error\n");
        free(cmd);
        return ;
      }
      if (dir == 1) Q.pop_front();
      else Q.pop_back();
    }
    i++;
  }
  free(cmd);
  printf("[");
  while(dir == 1 && !Q.empty()) 
  {
    int t = Q.front();
    if (Q.size() == 1) printf("%d", t);
    else printf("%d,", t);
    Q.pop_front();
  }
  while(dir == -1 && !Q.empty()) 
  {
    int t = Q.back();
    if (Q.size() == 1) printf("%d", t);
    else printf("%d,", t);
    Q.pop_back();
  }
  printf("]\n");
}

int main(void)
{
  scanf("%d", &T);
  for (int i = 0; i < T; i++) f();
  return (0);
}