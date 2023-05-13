#include "declarations.h"

extern char currentGLL[50] ;
extern char color[7];
extern double  currentLat, currentLong, sumOfDist, currentDist, distFromLastStep;

void chooseLedColor(double destX, double destY, double currentX, double currentY){
	currentDist = distance(currentX,destX,currentY,destY);
	ledOFF();
	printString("led color: ");
	if (currentDist > 5 ){
		printStringln("red");
		ledON(red);
	} else if (currentDist < 5 && currentDist > 2.5){
		printStringln("yellow");
		ledON(yellow);
	} else {
		printStringln("green");
		ledON(green);
	}
    
}
void calculateStepsTaken(double oldX, double oldY, double currentX, double currentY){
    distFromLastStep = distance(oldX,currentX,oldY,currentY);
	if (distFromLastStep > 0.5) {
		sumOfDist += distFromLastStep;
	}
}

double distance(double x1,double x2,double y1,double y2){
    return (sqrt(pow((x2 - x1),2) + pow((y2 - y1) , 2)) *100000) ;
}

void ledOFF(void){
    GPIO_PORTF_DATA_R &= ~0x0E;
}
void ledON(int color){
    GPIO_PORTF_DATA_R |= color;
}

void serialPrint(void) {
	printString("current message: ");
	printStringln(currentGLL);
	
	printString("currnet Latitude: ");
	printDouble(currentLat);
	printString("current Longitude: ");
	printDouble(currentLong);
	
	printString("distance to destination: ");
	printDouble(currentDist);
	
	printString("Total distance: ");
	printDouble(sumOfDist);
	
	printStringln("");
}
