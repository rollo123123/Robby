/*
*	COMPRO1 Machine Problem Part I
*	VELARDE, ROLLO DENZEL A.
*	11728132
*	S18A
*	
*	This program computes the Taylor series approximation of the cos x and sin x.
*/

#include <stdio.h>
#define PI 3.141592653589
#define NUMBER_OF_TERMS 12

int
main()
{
	double angX, rad; // variables that represent angle degree and angle radians
	double tayCos, taySin; // variables that represent the taylor series
	double	cosNum, cosDen, sinNum, sinDen; // variables needed for the fraction of the Taylor series
	double ans; // ans represents the whole fraction
	int sqTer, fTer; // (counters) sqTer represents the term with the square; fTer represents the term with the factorial
	int x; // variable needed for the for loops (factorial and power)
	
	printf("11728132\n");
	printf("\n");

	for (angX = -180; angX <= 180; angX += 5) // main loop that displays the degree angles from -180.00 to 180.00 
	{
		rad = PI * angX / 180;  // converts angle degrees to radians	
		tayCos = 1;  // 1 represents the initial term in cos
		taySin = rad; // rad represents the initial term in sin
		
		for(x = 2; x <= (NUMBER_OF_TERMS-1)*2; x += 2) // numerator and denominator code of cos
		{
			cosNum = rad; // numerator square code
			for(sqTer = 2; sqTer <= x; sqTer ++)
				cosNum *= rad;
			
			
			cosDen = 1; // denominator factorial code
			for(fTer = 1; fTer <= x; fTer ++ )
				cosDen *= fTer;
			
		
			ans = cosNum / cosDen;
		
			if (( x / 2 ) % 2 == 1) // this code determines whether you add or subtract the last term to following term
			tayCos = tayCos - ans; // IF TERM IS ODD, SUBTRACT TO THE NEXT TERM
			else
			tayCos = tayCos + ans; // IF TERM IS EVEN, ADD TO THE NEXT TERM
		}
		
		for(x = 3; x <= (NUMBER_OF_TERMS*2) - 1; x += 2) // numerator and denominator code of sin
		{
			sinNum = rad; // numerator square code
			for(sqTer = 2; sqTer <= x; sqTer ++)
				sinNum *= rad;
			
			
			sinDen = 1; // denominator factorial code
			for(fTer = 1; fTer <= x; fTer ++)
				sinDen *=  fTer;
			
		
			ans = sinNum / sinDen; 
		
			if (( x / 2 ) % 2 == 1) // this code determines whether you add or subtract the last term to following term
			taySin = taySin - ans; //IF TERM IS ODD, SUBTRACT TO THE NEXT TERM
			else
			taySin = taySin + ans; //IF TERM IS EVEN, ADD TO THE NEXT TERM
		}
	
		printf("%.2lf", angX);
		printf("\t \t %.12lf \t %.12lf \t %.12lf\n", rad, tayCos, taySin);
	
	}

	return 0;
}
