#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main() {
  FILE *f = fopen("/usr/share/dict/words", "r");
  fseek(f, 0,SEEK_END);
  long len = ftell(f);
  rewind(f);

  char *data = malloc(len);
  int res = fread(data, 1, len, f);
  if(res != len) return -1;

  int i,j,k;
  int x,y;
  int wordNdx;
  int num;
  int success ;
  char *chars = malloc(4);
  for(i=0;i<26;i++) {
    for(j=0;j<26;j++) {
      for(k=0;k<26;k++) {
        char *currentWord = malloc(200);
        char *shortest = NULL;
        wordNdx = 0;
        chars[0] = i + 'a';
        chars[1] = j + 'a';
        chars[2] = k + 'a';
        chars[3] = '\0';
        success = 0;
        fprintf(stderr,"trying %s\n", chars);
        for(x = 0;x<len;x++) {
          //printf("Progress is %d / %ld\n", x, len);
          if(data[x] == '\n' || x == len) {
            currentWord[wordNdx] = '\0';
            wordNdx = 0;
            //printf("Trying %s\n", currentWord);
            num = 0;
            for(y=0;y<strlen(currentWord);y++) {
              if(tolower(currentWord[y]) == chars[num]) {
                num++;
              }
              if(num == 3) {
                if(shortest == NULL || strlen(currentWord) < strlen(shortest)) {
                  shortest = currentWord;
                }
              }
            }
            if(currentWord != shortest) ;//free(currentWord);
          }
          else {
            currentWord[wordNdx] = data[x];
            wordNdx++;
          }
        }
        if(shortest == NULL) printf("NONE for %s\n", chars);
        else {
          printf("%s -> %s\n", chars, shortest);
          free(shortest);
        }
      }
    }
  }
}
