/* Title: Project 1
   Author: Jackson Geis
   Date: 9.14.18
   Purpose: Produce characters specified by an input of decimal and hexadecimal numbers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 1024

void main(int argc, char **argv[]){

  if (argc > 1){                          //Check if there's an appropriate amount of inputs
    printf("Only one argument accepted");
    return;
  }
  
  char *input, *parsed;
  input = (char *) malloc(MAX);
  char c;
  int x = 0, y = 0;
  int long num;
  while((c = fgetc(stdin)) != EOF) {   //Read the user's input and add it to the input string
    input[x] = c;
    x++;
  }

  x=0;
  c = input[x];
  parsed = (char *) malloc(strlen(input) + 1);
   while(c != '\000'){     //Parse the user's input
    c = input[x];
    if (c == ' ' || c == '\n' || c == '\t') {  //Clear whitespace
       x++;
     }
    else if (c == '/') {  //Check for comments
       do {x++;
       c = input[x];
       if (c == EOF) {   //Exit if the EOF is reached before the comment is finished
	 printf("Expected end of comment.");
	 return;
       }
       }while (c != '/');
       x++;
     }
     else if(c == EOF)
       break;
     else {             //Add the character to the parsed array
    parsed[y] = c;
    y++;
    x++;
    c = input[x];
  } 
  }
   int length = strlen(parsed);
   for(int i = 0; i <= length; i++){    //Begin converting the parsed array
     if (i % 2 == 0){
       if(parsed[i] == '0' && (parsed[i+1] == 'x' || parsed[i+1] == 'X')){ //Check for a hex digit
	 i = i + 2;
	 char *hexToInt = malloc(1);
	 hexToInt[0] = parsed[i];
	 hexToInt[1] = parsed[i+1];
	 num = strtol(hexToInt,0,16);  //Convert hex to int, then int to char to get ASCII code
	 char finalChar = (char) num;
	 printf("%c", finalChar);
       }
	 else {
	   char *decimal = malloc(1);
	   decimal[0] = parsed[i];
	   decimal[1] = parsed[i+1];
	   int convert = atoi(decimal);  //Convert the string array into an integer to conver it to the ASCII code
	   char finalInt = (char) convert;
	   printf("%c",finalInt);
	 }
	   
   }
   }
   /*
  int length = strlen(parsed);
  printf("\n");
  for (int i = 0; i < length; i++) {
 printf("%c",parsed[i]);
 printf("%i",num);
  }
   */
  
}
