#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    char arr[100];
    char newarr[100];
    char tokenizer; 
    // memset intialize the arr to null values
    memset(arr,0,100);
    memset(newarr,0,100);
    printf("Enter the string.\n");  
    // reads the string of maximum 100 characters
    fgets(arr,100,stdin);
 
    printf("Enter the tokenizer.\n"); 
    // reads a character
    scanf("%c",&tokenizer);
    char tokenizer1;
    if( tokenizer >= 'a' && tokenizer <='z')
    {  tokenizer1 = tokenizer - 32; }
    if( tokenizer >= 'A' && tokenizer <='Z')
    { tokenizer1 = tokenizer + 32; }

    int length;
    length = strlen(arr);
    int i = 0;
    int k = 0;
    while(i < length)
    {
      
        if (arr[i] != tokenizer && arr[i] != tokenizer1)
        {
            newarr[k] = arr[i];
            i++;
            k++;
        }
       else
       {
       
             while(arr[i] == tokenizer || arr[i] == tokenizer1)
             { 
                i++;               // didn't add tokenizer in newarr
             }
             if (i != (length-1))
             {   
                 newarr[k] = '\n';  // goes to new line, if new token
                 k++;                // encounter after tokenizer
             }
                 
       }
    }
    printf("%s",newarr); // prints the string after tokenization


     // for implementation of array in ascending order on the basis of first     
     // letter/ of each line
     char Fletter[100]; // it stores first letter of each line
     memset(Fletter,0,100);
     length = length -1;
     int j = 0;
     int m = 0;
     while(j < length)
        {
          if((newarr[j] >= 'A' && newarr[j] <= 'Z') || (newarr[j] >= 'a' && newarr[j] <= 'z' ) || (newarr[j] >= '0' && newarr[j] <= '9'))
             { Fletter[m] = newarr[j];
              m++;
            while( newarr[j] != '\n')
             {j++;} 
           
              }
         
              j++;
        }

    

     
return 0;
}
