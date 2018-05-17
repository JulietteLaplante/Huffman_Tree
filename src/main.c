#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "huffman.h"
#include "compression.h"
#include "decompression.h"
#include "compression_fonctions.h"
#include "utilitaire_compression.h"
#include "cli.h"

int main(int argc, char const *argv[]) {


  FILE* file_source;
  int c=0;
  int d=0;
  char* input = malloc(100*sizeof(char));
  char* input2;
  char* output = malloc(100*sizeof(char));
  char* outputCompressed = malloc(strlen(input)+1);
  //char* outputCompressedExt = malloc(strlen(input)+1);
  
  int nbParam=0;
  int source=0;
  
  int erreur = shell(&file_source,input,&source,argc,argv,&c,&d,&nbParam,output);
  if(erreur != 0){
    affichage_erreur(erreur);
  }
  else{
    if(source == 0){
      printf("Aucun nom de fichier source saisi, veuillez le faire maintenant :\n");
      scanf("%s",input);
      while(access(input,F_OK) == -1){
        printf("Nom de fichier saisi incorrect, recommencez:\n");
        scanf("%s",input);
      }
    }
    if(c == 1){
      while(access(input,F_OK) == -1){
        printf("Nom de fichier saisi incorrect, recommencez:\n");
        scanf("%s",input);
      }

      sprintf(outputCompressed,"%s%s%c",input,".chf",'\0');
      printf("On effectue la compression de %s vers %s\n",input,outputCompressed);
      compression(input,outputCompressed);
      
      
      /*outputCompressedExt = strrchr(input,'.');
      *outputCompressedExt = '\0';
      sprintf(outputCompressed,"%sbis%c",input,'\0');*/
      
    }
    if (d == 1){
      if(c == 0){
        printf("On effectue la decompression sur %s vers %s\n",input,output);
        decompression(input,output);
      }
      else{
        input2 = outputCompressed;
        printf("On effectue la decompression sur %s vers %s\n",input2,output);
        decompression(input2,output);
      }
    }
    
  }

  return 0;
}