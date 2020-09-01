/*
* COMPRO1 Machine Problem Part II
* VELARDE, ROLLO DENZEL A.
* 11728132
* S18A
*
* This source file contains the MAIN function of PART 2 of the Machine Problem, which is a table of values.
*
* NOTES: 
* 1. Change the word "lastname" in the filename to your own last name.    
*    For example, if your last name is SANTOS, then this file should be   
*    named as santos_mp2_main.c 


*


* 2. You are NOT ALLOWED to add new codes other than the implementation   
*    of the body of the main() function.  


*
* 3. You have to compile and link this with the object file corresponding 
*    to your lastname_mp2_math.c in order to produce the executable file.
*


*/




#include <stdio.h>
#include "mp2_math.h"
#define PI 3.141592653589
int 
main(void)
{
	double angX, rad;
	double cos, sin;
	
	printf("11728132\n");
	printf("\n");
	
	for (angX = -180; angX <= 180; angX += 5) // main loop that displays the degree angles from -180.00 to 180.00 
	
	{	
		rad = PI * angX / 180;  // converts angle degrees to radians
		cos = cosine(rad); //calls cosine function, which computes for the cosine given n (radians)
		sin = sine(rad); //calls sine function, which computes for the cosine given n (radians)
		printf("%.2lf", angX);
		printf("\t \t %.12lf \t %.12lf \t %.12lf\n", rad, cos, sin);
	
	}


  	return 0;
}
