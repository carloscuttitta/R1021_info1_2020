#include <stdio.h>

int main(int argc, char **argv, char **arge){
  int i = 0;

  puts("\narge ---");
  while(arge[i]){
    printf("[%d] => %s\n", i, arge[i]);
    i++;
  }

  return 0;
}


