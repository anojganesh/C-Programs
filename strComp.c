#include <stdio.h>
#include <stdlib.h>
int mystrcmp (char *S1, char *S2) ;

int main (void) {
  char S1[52], S2[52];
  //allow max 50 to force \n to be read into both strings so that
  //it appears in both (rather than in one and not the other).
  printf("Enter string1 (max: 50 characters): "); fgets(S1,52,stdin);
  printf("Enter string2 (max: 50 characters): "); fgets(S2,52,stdin);
  int c=mystrcmp(S1,S2);
  if (c<0)      printf("S1<S2\n");
  else if (c>0) printf("S1>S2\n");
  else          printf("S1=S2\n");
  exit(1);
}

int mystrcmp(char *S1, char *S2){
        int i = 0;
        char c1 = *S1;
        char c2 = *S2;
        while (c1 != '\0'){
                i++;
                c1 = *(S1+i);
                if (c1 != *(S2+i)){
                        if (c1 < *(S2+i)) return (-1);
                        if (c1 > *(S2+i)) return (1);
                }
        }
        return 0;
}
