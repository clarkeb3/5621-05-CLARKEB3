#include <stdio.h>	// Including library required to run the code.
#include <math.h>	// Including library required to run the code.
#include <stdlib.h> // for atoi, atof
#include <getopt.h>

void print_usage() {
	printf("Usage: ./round.o [Number to be rounded] [-option(for unit)] <rounded number in preffered units> \n");
	exit(1);
}
void input_number_K(float input_number) {
	input_number = input_number/1024.;
	printf("%.1fK \n", input_number);
}
void input_number_M(float input_number) {
	input_number = input_number/1048576.;
	printf("%.1fM \n", input_number);
}
void input_number_G(float input_number) {
	input_number = input_number/1073741824.;
	printf("%.1fG \n", input_number);
}
void input_number_T(float input_number) {
	input_number = input_number/1099511627776.;
	printf("%.1fT \n", input_number);
}
void input_number_P(float input_number) {
	input_number = input_number/1125899906842624.;
	printf("%.1fP \n", input_number);
}
void input_number_E(float input_number) {
	input_number = input_number/1152921504606847000.;
	printf("%.1fE \n", input_number);
}
int main(int argc, char **argv) 
{
	if (argc < 2) {
			print_usage();
	}
	if (argc > 3) {
			print_usage();
	}	
	float the_passed_number;
	int option;
	int unit = 1024;
	int index = 0;
	const char suffixes[] = {' ', 'K', 'M', 'G', 'T', 'P', 'E'};
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
