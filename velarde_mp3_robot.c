/*
* COMPRO1 Machine Problem Part III
* VELARDE, ROLLO DENZEL A.
* 11728132
* S18A
*
* This source code contains functions that would enable the robot to move using the supplied input by the user
*
*     
* NOTES:                                                                    
* 1. Change the word "lastname" in the filename to your own last name.      
*    For example, if your last name is SANTOS, then this file should be     
*    named as santos_mp3_robot.c   
*                                          
* 2. Your main task is to fill-up the body of the functions given below.                
*                                                                           
* 3. The following are NOT ALLOWED:           
*                              
*    a. calling printf() inside the functions except in DisplayStatus(),    
*       and Quit() functions.                                               
*
*    b. addition of  new codes other than the implementation of the body      
*       of the functions and the entries in this preamble                   


*


*    c. changing the return type, function name and parametrizations        
*/
                                             
#include <stdio.h>

#include "mp2_math.h"  
#include "mp3_robot.h"





/*
*  Initialize/Reset Command 
*
*  Task:       
*    Initialize/ReSet the robot’s position to (0, 0), and its orientation to 0 degree.  
*/
void 
InitializeReset(float *pfRobotX, float *pfRobotY, double *pdRobotAngle)
{
	*pfRobotX = 0;
	*pfRobotY = 0;
	*pdRobotAngle = 0;
}


/*
*  Display Status Command 
*
*  Task: 
*    Display the robot current state, i.e., its current position 
*    and orientation (in degrees).  For the robot position, there should be 
*    four digits after the decimal point.  For the orientation, there should
*    be 2 digits after the decimal point.  Output should always start on a
*    new line.
*/
void 
DisplayStatus(float fRobotX, float fRobotY, double dRobotAngle)
{
	printf("Robby's x-coordinate: %.4f\n", fRobotX);
	printf("Robby's y-coordinate: %.4f\n", fRobotY);
	printf("Robby's orientation: %.2lf\n", dRobotAngle);
}   


/*
*  Forward Translation Command
*
*  Pre-Condition: 
*    a. fDistance contains the translation distance
*    b. *pfRobotX is the robot's current x-coordinate (before translation)
*    c. *pfRobotY is the robot's current y-coordinate (before translation)
*    d. dRobotAngle is the robot's current orientation
*
*  Post-Condition:
*    a. *pfRobotX is the robot's new x-coordinate (after translation)
*    b. *pfRobotY is the robot's new y-coordinate (after translation)
*   
*  Task:
*    Translate the robot forward by a distance equivalent to fDistance.
*    Compute the robot’s new coordinates.    
*/

void 
TranslateForward(float fDistance, float *pfRobotX, float *pfRobotY, double dRobotAngle)
{
	double rad;
	rad = PI * dRobotAngle / 180;
    	*pfRobotX += cosine(rad) * fDistance;
    	*pfRobotY += sine(rad) * fDistance;
     /* Note: you will need to call cosine() and sine() in this function. */
}
/*
*  Backward Translation Command 
* 
*
*  Pre-Condition: 
*    a. fDistance contains the translation distance
*    b. *pfRobotX is the robot's current x-coordinate (before translation)
*    c. *pfRobotY is the robot's current y-coordinate (before translation)
*    d. dRobotAngle is the robot's current orientation
*
*  Post-Condition:
*    a. *pfRobotX is the robot's new x-coordinate (after translation)
*    b. *pfRobotY is the robot's new y-coordinate (after translation)
*   
*  Task:
*    Translate the robot forward by a distance equivalent to fDistance.
*    Compute the robot’s new coordinates. 
*/

void 
TranslateBackward(float fDistance, float *pfRobotX, float *pfRobotY, double dRobotAngle)
{
	double rad;
	rad = PI * dRobotAngle / 180;
    *pfRobotX -= cosine(rad) * fDistance;
    *pfRobotY -= sine(rad) * fDistance;
     /* Note: you will need to call cosine() and sine() in this function. */
}
/*
*  Counterclockwise Rotation Command 
*
*  Pre-Condition: 
*     a. dTheta is the angle of rotation
*     b. *pdRobotAngle is the robot's current orientation (before rotation)
*
*   Post-Condition:
*     a. *pdRobotAngle is the robot's new orientation (after rotation)
*
*   Task:
*     Rotate the robot counterclockwise by an angle equivalent to dTheta.
*     Compute the robot’s new orientation.  
*
*     VERY IMPORTANT NOTE!!!  Make sure that you keep the value of 
*     *pdRobotAngle within the range  -360 to 360 degrees.
*/
void 
RotateCounterClockwise(double dTheta, double *pdRobotAngle)
{
	double y;
	int x;
	
	if(dTheta <= 360){
    *pdRobotAngle += dTheta;
    }
    
    else if(dTheta > 360){
    	x =	dTheta / 360.00;
    	y = 360 * (x * 1.00);
    	dTheta -= y;
   		*pdRobotAngle += dTheta;
	}
}
/*
*  Clockwise Rotation Command 
*
*  Pre-Condition: 
*     a. dTheta is the angle of rotation
*     b. *pdRobotAngle is the robot's current orientation (before rotation)
*
*   Post-Condition:
*     a. *pdRobotAngle is the robot's new orientation (after rotation)
*
*   Task:
*     Rotate the robot clockwise by an angle equivalent to dTheta.
*     Compute the robot’s new orientation.  
*
*     VERY IMPORTANT NOTE!!!  Make sure that you keep the value of 
*     *pdRobotAngle within the range  -360 to 360 degrees. 
*/
void 
RotateClockwise(double dTheta, double *pdRobotAngle)
{	
	double y;
	int x;
	
    if(dTheta <= 360){
    *pdRobotAngle -= dTheta;
	}
	
	else if(dTheta > 360){
    	x =	dTheta / 360.00;
    	y = 360 * (x * 1.00);
    	dTheta -= y;
   		*pdRobotAngle -= dTheta;
	}
}


/*
*  Quit Simulation Command
*
*  Task:
*    Simply display a message “END SIMULATION”.
*/
void 
Quit(void)
{
     printf("END SIMULATION.\n");
}

  
/***************************  END OF THIS FILE *******************************/


