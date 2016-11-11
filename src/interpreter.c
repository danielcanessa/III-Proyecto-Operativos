#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include"deviceLibrary.h"
 

//Method to find the position of a substring
int findSubstr(char *inpText, char *pattern)
{
  int inplen = strlen(inpText);
  while(inpText != NULL) 
  {
    char *remTxt = inpText;
    char *remPat = pattern;
    if(strlen(remTxt) < strlen(remPat)) 
    {     
      return -1;
    }

    while (*remTxt++ == *remPat++) {      
      if(*remPat == '\0' ) {        
        return inplen - strlen(inpText+1) ;
      }
      if(remTxt == NULL) {
        return -1;
      }
    }
    remPat = pattern;
    inpText ++;
   }
}

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

int processMove(char** tokens)
{
	int result=0;
	int posIni = -1;
	int posFin = -1;
	int nextMove = -1;
	for (int i = 0; tokens[i]!=NULL; i++)
	{  		
		if (tokens[i+1]!=NULL)
		{
			char *entry = tokens[i];
			if (strcmp( entry, "-i")==0)
			{  				  
			    posIni = atoi(tokens[i + 1]);    				
			}			
			if (strcmp( entry, "-f")==0)
			{  				  
			    posFin = atoi(tokens[i + 1]);    				
			}
			if (strcmp( entry, "-t")==0)
			{  				  				 
			    char *move =tokens[i + 1];  		    
			    if (strncmp( move, "move",4)==0)
				{
					nextMove=0;
				} 
				if (strncmp( move, "touch",5)==0)
				{
					nextMove=1;
				} 
				if (strncmp( move, "push",4)==0)
				{					
					nextMove=2;
				} 	
				if (strncmp( move, "drag",4)==0)
				{
					nextMove=3;
				} 			
			}		
		}		
	}	
	if(posIni>=0 && posIni<=9 && posFin>=0 && posFin<=9 && nextMove!=-1)
	{
		printf("Sending to the device new move: -i %d -f %d -t %d\n",posIni,posFin,nextMove);		
		int deviceResponse = processMoveDevice(posIni, posFin, nextMove);		
		if(!deviceResponse)
		{
			printf("bad response, check config.txt and the device connection\n");
			exit(1);
		}		
		result = 1;
	}	
	return result;
}

int processBoard(char** tokens)
{
	int sizeBoard = 0;
	for (int i = 0; tokens[i]!=NULL; i++)
	{  
		if (tokens[i+1]!=NULL)
		{
			if (strcmp( tokens[i], "-b")==0)
			{   
				char *entry = tokens[i+1];	
				
				if (strncmp( entry, "1x1",3)==0)
				{					
					sizeBoard=1;
				}  
				if (strncmp( entry, "2x2",3)==0)
				{
					sizeBoard=2;
				}  
				if (strncmp( entry, "4x4",3)==0)
				{
					sizeBoard=3;
				}			       				
			}			
		}		
	}
	if(sizeBoard!=0)
	{	
		printf("Sending to the device new board: -b %d\n",sizeBoard);		
		int deviceResponse = processBoardDevice(sizeBoard);
		if(!deviceResponse)
		{
			printf("bad response, check config.txt and the device connection \n");
			exit(1);
		}		
	}	
	return sizeBoard;
}

int main(int argc, char **argv) 
{  
  char * filedir ="config.txt";
  FILE *ptr_file;
  char line[1000];  
  ptr_file =fopen(filedir,"r");   
 
  if (!ptr_file)
  {
    printf("Can't open config file\n");
    return 0;          
  }	
  while (fgets(line,1000, ptr_file)!=NULL)
  {   		
	    char** tokens;
		tokens = str_split(line, ' ');		
		int isMove = findSubstr(line, "move");
	    if( isMove > -1) {		
			if (tokens)
			{		
				int result = processMove(tokens);		
				if(result==0)
				{
					printf("Error processing movement in line: %s\n",line);
					return 0;
				}	
			}            
	    }	    
	    int isBoard = findSubstr(line, "board");
	    if( isBoard > -1) {		
			if (tokens)
			{		
				int result = processBoard(tokens);		
				if(result==0)				{
					printf("Error processing board in line: %s\n",line);
					return 0;
				}	
			}            
	    }	    
	    free(tokens);
  }  
  fclose(ptr_file);  
  return 0;
}
