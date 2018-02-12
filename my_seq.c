/* Including libraries needed to run the code. */

#include <stdlib.h> 
#include <getopt.h>
#include <stdio.h>	
#include <math.h>	


/* Setting up the main function of the program */

int main(int argc, char *argv[]) /* Using required syntax in main() arguments in order to use getopt() */
{ 
	/* Defining/initialising the key variables of the program */

	int FIRST = 1;
	int INCREMENT = 1;
	int LAST;
	int padding = 0;
	char str[20];
	int i = 0;

	int option = getopt(argc, argv, "w"); /* Setting up -w option */

	/* This sets i = 1 when the option -w is used. */
	if(option != -1) {
		i = 1;}

	/* Prints error when too few options are inputted. */
	if(argc < 2 + i) {
		printf("You must use an addtional option.\n");		
		return 0;}

	/* Prints error when too many options are inputted. */
	if(argc > 4 + i) {
		printf("You have used too many options.\n");		
		return 0;}

	/* This sets the LAST variable for the case in which the user only inputs one number (e.g ./my_seq 25).*/
	if(argc == 2 + i) {
		LAST = atoi(argv[1]);}

	/* This sets the FIRST and LAST variables for the case in which the user inputs two number (e.g ./my_seq 25 50).*/
	if(argc == 3 + i) {
		FIRST = atoi(argv[1]);
		LAST = atoi(argv[2]);}

	/* This sets the FIRST, INCREMENT and LAST variables for the case in which the user inputs three number (e.g ./my_seq 25 5 50).*/
	if(argc == 4 + i) {
		FIRST = atoi(argv[1]);
		INCREMENT = atoi(argv[2]);
		LAST = atoi(argv[3]);}

	/* This while loop prints out the sequence of numbers. It adds leading zeroes when -w is selected (when i == 1). */ 
	while(FIRST <= LAST) {
		if(i == 1) {
			padding = (floor(log10(abs(LAST)))) + 1;}
		sprintf(str, "%%0%dd \n", padding);
		printf(str, FIRST);
		FIRST += INCREMENT;
	}
}