#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void clean (char *var)
{
   int i =0;
   while(var[i] != '\0'){
       var[i++] = '\0';
}
}
int main(int argc, char *argv[])
{
  
  char filename[100];
  char filename2[100];
  FILE *fp;
  //Enter name of file
  printf ("enter name of file \n");
  scanf("%s", filename);
  strcpy(filename2, filename);
  //copy content of filename to filename2 for latter use
  fp = fopen(strcat(filename,".txt"),"r");
  // file does not exists so create new with .txt extension
  if (fp == NULL) {
    printf("file Created with name:%s",filename);
    fp = fopen(filename,"w");
    fclose (fp);
    exit(0);
   }
  clean(filename);  //clean content of filename
  strcpy(filename, filename2);  //copy filename with contents of filename2
  if(fp !=NULL)
   {
    //create buffers for temp use
     char temp [100];
     char buffer[100];
     int i =0;
    //loop untill ith file with same name do not exits with _i.txt extension
     while(1)
       {
         
         strcat(temp,"_");
         sprintf(buffer,"%d",++i); //convert int i to string then stores it into buffer and increment it
         strcat(temp,buffer);
         strcat(filename,temp);
         fp = fopen(strcat(filename,".txt"),"r");
         if(fp == NULL)   // when file does not exist ; exit while loop and create file
            break;
         clean(filename);
         clean(temp);
         clean(buffer);
         strcpy(filename, filename2);
           
        }
      fp = fopen(filename,"w");
      printf("file Created with name:%s",filename);
      fclose (fp);
      exit(0);   //exit with status 0; means done successfullly
    }
   //if control reach here ; means something went wrong
  fprintf(stderr, "something went wrong");
  exit(1);
}
