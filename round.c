/* Including libraries needed to run the code. */

#include <stdio.h>	
#include <math.h>	
#include <stdlib.h> 
#include <getopt.h>

/* Setting up the function of the program that prints out instructions for usage. This prints when the user incorrectly runs the program.*/
void print_usage() {
	printf("Usage: ./round.o [Number to be rounded] [-option(for unit)] <rounded number in preffered units> \n");
	exit(1);
}

/* Setting up the function for -K option. */
void input_number_K(float input_number) {
	input_number = input_number/1024.;
	printf("%.1fK \n", input_number);
}

/* Setting up the function for -M option. */
void input_number_M(float input_number) {
	input_number = input_number/1048576.;
	printf("%.1fM \n", input_number);
}

/* Setting up the function for -G option. */
void input_number_G(float input_number) {
	input_number = input_number/1073741824.;
	printf("%.1fG \n", input_number);
}

/* Setting up the function for -T option. */
void input_number_T(float input_number) {
	input_number = input_number/1099511627776.;
	printf("%.1fT \n", input_number);
}

/* Setting up the function for -P option. */
void input_number_P(float input_number) {
	input_number = input_number/1125899906842624.;
	printf("%.1fP \n", input_number);
}

/* Setting up the function for -E option. */
void input_number_E(float input_number) {
	input_number = input_number/1152921504606847000.;
	printf("%.1fE \n", input_number);
}

/* Setting up the main function of the program */
int main(int argc, char **argv) /* Using required syntax in main() arguments in order to use getopt() */
{
	if (argc < 2) {					/* Prints error when too few options are inputted. */	
			print_usage();
	}
	if (argc > 3) {
			print_usage();			/* Prints error when too many options are inputted. */	
	}	

	/* Defining/initialising the key variables/strings of the program. */
	float the_passed_number;
	int option;
	int unit = 1024;
	int index = 0;
	const char suffixes[] = {' ', 'K', 'M', 'G', 'T', 'P', 'E'};

	/* This loops when a valid option is selected or when the argument count is 2. */
	/* Depending on the chosen case, the program will round to a particular unit. */
	while((option = getopt(argc, argv, "K:M:G:T:P:E:h:")) != -1 || argc == 2)
	{ 
		switch(option) 
		{
				case 'K' :
					input_number_K(atof(optarg));
					break;					
				case 'M' :
					input_number_M(atof(optarg));
					break;
				case 'G' :
					input_number_G(atof(optarg));
					break;
				case 'T' :
					input_number_T(atof(optarg));
					break;
				case 'P' :
					input_number_P(atof(optarg));
					break;
				case 'E' :
					input_number_E(atof(optarg));
					break;
				default: 
					print_usage();
					break;
				/* Human readable case. */
				case 'h' :
					the_passed_number = (atof(optarg));
					while (the_passed_number >= unit) {
						the_passed_number /= unit;
						index++;}
					printf("%.1f%c\n", the_passed_number, suffixes[index]);	
					break;	
		}
	}					
}
