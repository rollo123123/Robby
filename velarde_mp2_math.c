/*
* COMPRO1 Machine Problem Part I
I

* VELARDE, ROLLO DENZEL A.
* 11728132
* S18A
*
* This source file contains the functions seen in "mp2_math.h". It contains a function that gets the power;
* It contains a function that computes for the factorial; It contains functions that computer for the cosine and sine using the taylor series
*
* NOTES: 
* 1. Change the word "lastname" in the filename to your own last name.    
*    For example, if your last name is SANTOS, then this file should be   
*    named as santos_mp2_math.c 
*
* 2. Your main task is to implement the definitions for functions whose 
*    prototypes were declared in mp2_math.h file.                                               
*
* 3. The following are NOT ALLOWED:                                       

*    a. addition of  new codes other than the implementation of mp2_math functions                 
*    b. changing the #define                                              
*    c. changing the return type, function name and parametrizations      
*    d. calling output function such as printf() - do not output anything 
*       inside the function definitions! 

*
* 4. You need to compile this source code separately to produce      
*    the object file. This is done via:
*
*             gcc -Wall -c lastname_mp2_math.c
*
*/

#include <stdio.h>
#include "mp2_math.h"
#define NUMBER_OF_TERMS 20

/*
* This function computes for the value given a base (radians) and an exponent
* Pre-condition: assume this function will be used for the taylor series expansion and the exponent is != 0 and != 1
* @param x is the base 
* @param n is the exponent
* @returns the final value, which is the base^exponent
*/

double 
RaiseTo(double x, int n)
{
	double fOut;
	int y;
	fOut = x;
	
	for(y = 2; y <= n; y ++)
		fOut *= x;
	return fOut;
}

/*
* This function computes for the factorial given a value
* Pre-condition: assume that the value is != 0 and != 1
* @param n is the value inputted
* @returns the final value, which is the factorial of the given value
*/
double 
factorial(int n)
{
	double fOut;
	int x;	
	fOut = 1;
	
	for(x = 1; x <= n; x ++)
		fOut *= x;
	return fOut;
}

/*
* This function computes for the cosine of a given value
* Pre-condition: assume that the value is within the range of -180.00 to 180.00, increments of 5.
* @param x represents the value of the angle (radians)
* @returns the cosine of the given value
* note: contains Raiseto and factorial functions, which were previously created.
*/
double 
cosine(double x)
{
	double tayCos;
	double cosNum, cosDen;
	double ans;
	int y;
	tayCos = 1;
	for(y = 2; y <= (NUMBER_OF_TERMS-1)*2; y += 2)
	{
	cosNum = RaiseTo(x, y);
	cosDen = factorial(y);
	
	ans = cosNum / cosDen;
	if( ( y / 2 ) % 2 == 1)
		tayCos -= ans;
	else
		tayCos += ans;
	}
	return tayCos;
	
}


/*
* This function computes for the sine of a given value
* Pre-condition: assume that the value is within the range of -180.00 to 180.00, increments of 5.
* @param x represents the value of the angle (radians)
* @returns the sine of the given value
* note: contains Raiseto and factorial functions, which were previously created.
*/

double 
sine(double x)
{
	double taySin;
	double sinNum, sinDen;
	double ans;
	int y;
	taySin = x;
	for(y = 3; y <= (NUMBER_OF_TERMS*2) - 1; y += 2)
	{
	sinNum = RaiseTo(x, y);
	sinDen = factorial(y);
	
	ans = sinNum / sinDen;
	if( ( y / 2 ) % 2 == 1)
		taySin -= ans;
	else
		taySin += ans;
	}
	return taySin;
}














