//
// Created by chris275 on 23/11/20.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv){

    char* option = argv[1];

   if(strcmp(option,"-list")){
       for(int i = 2; i < argc; i++){

       }



   }else if(strcmp(option,"-grayscale")){


   }else if(strcmp(option,"-encodeStegano")){


   }else if(strcmp(option,"-decodeStegano")){


   }else if(strcmp(option,"-encodeText")){


   }else if(strcmp(option,"-decodeText")){


   }else if(strcmp(option,"-stringToImage")){


   }else if(strcmp(option,"-imageToString")){


   }else{
       printf("\nThe option you have entered in not included!\n");
       exit(EXIT_FAILURE);

   }
   for(int i = 1; i < argc; i++){
       printf("%s\n",argv[i]);

   }




}
