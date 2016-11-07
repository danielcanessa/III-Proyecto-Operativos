#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

void help()
{
  printf("-t type\n");
  printf("-di initial Digit\n");
  printf("-df final Digit\n");
  printf("-n Board Size\n");
  printf("-c config file\n");
  printf("-init turn on\n");
  printf("-close turn off\n");
}

void move(char* type,char* digitInit,char* digitFinal,char* size)
{
  printf("Type: %s, Initial Digit: %s,Final Digit: %s, Size: %s\n",type,digitInit,digitFinal,size); 

}

void loadConfiguration(char* file)
{
  printf("Configuration %s\n",file);
}

int main(int argc, char **argv) 
{
  //roboticFinger -t push -di 1 -df 10 -n 1x1        roboticFinger -t push -di 1 -df -n 1x1
  printf("----------------------Interpreter initialized----------------------\n");
  int isRunning=1;
  
  while(isRunning){
    printf("->Waiting new command\n");
    char *line = NULL;
    size_t size;
    if (getline(&line, &size, stdin) == -1) {  
         printf("No line\n");
    } else {
        printf("Response:\n");
        char* type;
        char* digitInit;
        char* digitFinal;
        char* size;
        char** tokens;
        tokens = str_split(line, ' ');
        int process=1;

        if (tokens)
        {
            int i;
            for (i = 0; tokens[i]!=NULL; i++)
            {
                char *entry = tokens[i];

                if (strcmp( entry, "-init")==0) { 
                  process=0;                
                  printf("Turn on\n");  
                  break;                
                }

                if (strcmp( entry, "-close")==0) { 
                  process=0;                           
                  printf("Turn off\n");   
                  break;              
                }

                if (strcmp( entry, "-h")==0) { 
                  process=0;                 
                  help();   
                  break;
                }

                if (tokens[i+1]!=NULL){
                  if (strcmp( entry, "-t")==0) {  //type   
                      if(strstr(tokens[i + 1], "-") != NULL) 
                      {
                        printf("The flag -t must be declared with an argument\n");
                        process=0;              
                        break; 
                      }
                      else
                      {                
                        type=tokens[i + 1]; 
                      }  
                               
                  }
                  if (strcmp( entry, "-di")==0){  //digit    
                      if(strstr(tokens[i + 1], "-") != NULL) 
                      {
                        printf("The flag -di must be declared with an argument\n");
                        process=0;              
                        break; 
                      }
                      else
                      {                
                        digitInit=tokens[i + 1]; 
                      }               
                      
                  }
                  if (strcmp( entry, "-df")==0){  //digit       
                      if(strstr(tokens[i + 1], "-") != NULL) 
                      {
                        printf("The flag -df must be declared with an argument\n");
                        process=0;              
                        break; 
                      }
                      else
                      {                
                        digitFinal=tokens[i + 1]; 
                      }                
                  }
                  if (strcmp( entry, "-n")==0) { //size   
                       if(strstr(tokens[i + 1], "-") != NULL) 
                      {
                        printf("The flag -n must be declared with an argument\n");
                        process=0;              
                        break; 
                      }
                      else
                      {                
                        size=tokens[i + 1]; 
                      }              
                         
                     
                  }

                  if (strcmp( entry, "-c")==0) {  
                      if(strstr(tokens[i + 1], "-") != NULL) 
                      {
                        printf("The flag -c must be declared with an argument\n");
                      }
                      else
                      {                
                        loadConfiguration(tokens[i + 1]);
                      } 
                      process=0;              
                      break;                    
                  }        
                }                              
            }        
        }
       
        if(process){
          if(type!=NULL && digitInit!=NULL && digitFinal!=NULL && size!=NULL)
          {
            move(type,digitInit,digitFinal,size);
            
          }
          else
          {
            printf("You must specified the flags -t, -di, -df, -n for the movement\n");
          }
        }
        else
        {

        }

        free(tokens);
    }
  }

    
 
/*

  
  
  
  
  for (int i = 1; i < argc; i++) {  
    
     
    if (i + 1 != argc)    {
        if (strcmp( entry, "-t")==0) {  //type                   
            type=argv[i + 1];   
            caseAction=1;         
        }
        if (strcmp( entry, "-di")==0){  //digit                 
            digitInit = argv[i + 1];
            caseAction=1;
        }
        if (strcmp( entry, "-df")==0){  //digit                 
            digitFinal = argv[i + 1];
            caseAction=1;
        }
        if (strcmp( entry, "-n")==0) { //size                  
            size = argv[i + 1];    
            caseAction=1;
        }

        if (caseAction==-1 && strcmp( entry, "-c")==0) {  
            caseAction=2;        
            printf("Configuration\n");
            
        }        
    }
    
    if(caseAction==-1){
      if (strcmp( entry, "-init")==0) {
        caseAction=3;
        printf("Turn on\n");
        
      }

      if (strcmp( entry, "-close")==0) {   
        caseAction=4;               
        printf("Turn off\n");
       
      }
      if (strcmp( entry, "-h")==0) {    
        caseAction=5;
        help();   

      }
    }
    else
    {
      printf("The flags -init, -close, -h, -c must be alone\n");
    }

  }

  if(type!=NULL && digitInit!=NULL && digitFinal!=NULL && size!=NULL)
  {
    printf("Type: %s, Initial Digit: %s,Final Digit: %s, Size: %s\n",type,digitInit,digitFinal,size); 
  }
  else
  {

  }


  */
  
  return 0;
}