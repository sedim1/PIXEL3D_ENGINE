#include "typedefs.h"

Keyboard key;

float angleAdjust(float angle){
	float x = angle;
	if( angle < 0.0f){
		x = angle + 360.0f;
	}
	else if(x > 359.0f){
		x = angle - 360.0f; 
	}
	return x;
}

float degToRad(float degrees){
	return (degrees/180.0f*M_PI);
}
