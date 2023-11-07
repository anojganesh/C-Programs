#include <stdio.h>
#include <stdlib.h>

void fileSize (char *fname, int *longestLine, int *numLines ) {
  FILE *fp=fopen(fname,"r");
  char c;
  *numLines=0;
  int maxLineLength=0, curLineLength=0;
  while ((c=fgetc(fp))!=EOF) {
    curLineLength++;
    if (c=='\n') {
      (*numLines)++;
      if (curLineLength > maxLineLength) maxLineLength=curLineLength;
      curLineLength=0;
    }
  }
  *longestLine=maxLineLength;
  fclose(fp);
}

int main (int argc, char *argv[]) {

   int longestLine, numLines, i=0;
   fileSize(argv[1], &longestLine, &numLines);
   char Lines[numLines][longestLine+1];    //create array of appropriate size
   FILE *fp=fopen(argv[1],"r");
   while (fgets(Lines[i++],longestLine+1,fp)!=NULL) ; //read file into Lines
   for (i=numLines-1;i>=0;i--)                        //reverse-print Lines array
      printf("%s",Lines[i]);
   exit (0);
}
