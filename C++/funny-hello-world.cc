// $ make funny-hello-world

#include <stdio.h>

void rev (char *str) {
  if(*str == '\0') return;
  rev(str + 1);
  putchar(*str);
}

int main (void) {
  const char *string = "Hello";
  while (*string) putchar(*string++);
  rev("\n!dlroW ,");
  return 0;
}
