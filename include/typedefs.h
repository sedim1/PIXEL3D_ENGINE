#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <math.h>
#include "cglm/cglm.h"
#include <stdio.h>
#include <stdlib.h>

#define RESOLUTION 1
#define SW 256*RESOLUTION
#define SH 224*RESOLUTION
#define SW2 (SW/2)
#define SH2 (SH/2)
#define PIXELSCALE 4/RESOLUTION
#define SCREEN_WIDTH (SW*PIXELSCALE)
#define SCREEN_HEIGHT (SH*PIXELSCALE)

#define ZNEAR 0.1f
#define ZFAR 1000.0f
#define ASPECT ((float)SW/(float)SH)
#define FOV 75.0f

#define M_PI 3.14159265358979323846

//Handling input 
typedef struct{
	int w,a,s,d,esc,i,j,k,l,shift;
}Keyboard;


//Structure of a color of pixel
typedef struct{
	int r,g,b;
}RGB;

//Handling triangle and 3D information
typedef struct{
	vec3 p[3];
}Triangle;

typedef struct{
	Triangle* triangles;
	unsigned int nTriangles;
}Mesh;

//Primitives
typedef struct{
	Triangle triangles[12];
}MeshCube;


//MATH FUNCTIONS
float angleAdjust(float angle);
float degToRad(float degrees);
#endif
