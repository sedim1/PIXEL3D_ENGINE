#ifndef RENDERER_H
#define RENDERER_H

#include <stdbool.h>
#include "Mesh.h"
#include "typedefs.h"
#include <SDL2/SDL.h>

//Vector and matrices operatrion for the renderer to be able to put onn screen
void MultiplyMatrixVector(vec3 i,vec3 o,mat4 m);

//Drawing on screen
void pixel(int x, int y,RGB* color);
bool isTransparent(RGB* color);
void renderTest();
void renderCubeTest();
void DDA(int x0, int y0, int x1, int y1,RGB* c);
void DrawTriangle(vec3 p1, vec3 p2, vec3 p3);

#endif
