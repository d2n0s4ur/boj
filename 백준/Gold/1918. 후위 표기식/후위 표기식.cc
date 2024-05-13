#include <stdio.h>

using namespace std;

char ans[101];
char stack[101];
int ans_len, stack_len;

int get_priority(char c)
{
  if (c == '+' || c == '-') return 1;
  if (c == '*' || c == '/') return 2;
  if (c == '(') return 0;
}


int main(void)
{
  char c;

  while(1)
  {
    scanf("%c",&c);

    if (c == 0 || c == '\n') break;
    if (c >= 'A' && c <= 'Z') {
      ans[ans_len++] = c;
      continue;
    }
    if (c == '(') {
      stack[stack_len++] = '(';
      continue;
    }
    if (c == ')') // pop all operation until meet (
    {
      while (stack[stack_len - 1] != '(') {
        ans[ans_len++] = stack[stack_len - 1];
        stack_len--;
      }
      stack_len--;
      continue;
    }
    while (stack_len >= 1 && get_priority(stack[stack_len - 1]) >= get_priority(c)) {
      if (stack[stack_len - 1] == '(' ) continue;
      ans[ans_len++] = stack[stack_len - 1];
      stack_len--;
    }
    // push c to stack
    stack[stack_len++] = c;
  }
  // make stack empty
  while (stack_len >= 1) {
    ans[ans_len++] = stack[stack_len - 1];
    stack_len--;
  }
  printf("%s\n", ans);

  return (0);
}