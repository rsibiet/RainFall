#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void  usage(char *name) {
  printf("Usage : %s [get|address]\n\n", name);
  printf("Example :\n");
  printf("\t %s get : Return a special string\n", name);
  printf("\t %s 0xbffff628 : Return the offset\n", name);
}

int   main(int argc, char **argv) {

  char  *string = "Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag";
  char  search[5];
  char  *found;
  int   i = 0;
  int   u = 8;
  int   offset;

  if (argc != 2) {
    usage(argv[0]);
  } else {
    if (strcmp(argv[1], "get") == 0)
      printf("%s\n", string);
    else if (strncmp(argv[1], "0x", 2) == 0 && strlen(argv[1]) == 10) {
      while (i < 4) {
        search[i] = strtol(argv[1] + u, NULL, 16);
        argv[1][u]  = '\0';
        u -= 2;
        i++;
      }
      search[i] = '\0';
      found = strstr(string, search);
      if (found != NULL && strlen(search) == 4) {
        offset = found - string;
        printf("Offset = %d\n", offset);
      } else
        printf("Not found, eip is not overwrite or only partially\n");
    }
    else {
      printf("'%s' : this is not recognized\n", argv[1]);
      usage(argv[0]);
    }
  }
  return 0;
}
