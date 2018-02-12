/* Including libraries needed to run the code. */

#include<stdio.h> 
#include<unistd.h> 
#include<stdlib.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include<string.h> 
#include <fcntl.h> 
#include<math.h>

/* Defining RED and RESET */
#define RED "\x1b[31m"
#define RESET "\x1b[0m"

void match_pattern(char *argv[], char flag)  /* Using required syntax in match_pattern() arguments in order to use getopt() */
{

	/* Defining/initialising the key variables/strings of the program. */
	int open_file_int; 
	int read_file_int;
	int line_index;
	int line_number=0; 
	char line[100]; 
	char indiv_char;

	if((open_file_int=open(argv[2],O_RDONLY)) != -1) /* The open function returns an integer value, which is used to refer to the file. In this case it is set to fd. The filename is the first command line input after the program name. The if statement ensures the program does not proceed if open is unsuccessful. */
	{ 
		while((read_file_int=read(open_file_int,&indiv_char,sizeof(char)))!= 0) {  /* Defining loop to be expecuted when file is being read. */

        		if(indiv_char!='\n') { 
        			line[line_index]=indiv_char; 
        			line_index++; 
        		} 

        		else { 

        			 /* Defining flags. */

					if ( flag == 'b' ) {
						if(strstr(line,argv[1])!=NULL) 
	         				printf("%s\n",line); 
						memset(line,0,sizeof(line)); 
	         				line_index=0;
					}

					if ( flag == 'n' ) {
						if(strstr(line,argv[1])!=NULL)
						printf("%d%s%s\n",line_number," ",line);
	         				memset(line,0,sizeof(line)); 
	         				line_index=0;
						line_number++;
					}

					if ( flag == 'v' ) {
	         				if(strstr(line,argv[1])==NULL) 
	         				printf("%s\n",line); 
	         				memset(line,0,sizeof(line)); 
	         				line_index=0;
	         			} 

					if ( flag == 'c' ) {
						if(strstr(line,argv[1])!=NULL) 
	         				printf(RED "%s\n" RESET,line);
						memset(line,0,sizeof(line)); 
	         				line_index=0;

					}
         		} 
		} 
	} 	
}

/* Defining main function*/
int main(int argc, char *argv[] ) { 

	int option = getopt(argc, argv, "bnvc");


	if(argc==3) { 
		match_pattern(argv, 'b');
			}

	if(strcmp(argv[3], "-n") == 0){
		match_pattern(argv, 'n'); }
			

	if(strcmp(argv[3], "-v") == 0){
		match_pattern(argv, 'v'); }
			

	if(strcmp(argv[3], "-c") == 0){
		match_pattern(argv, 'c'); }
			


	
}

