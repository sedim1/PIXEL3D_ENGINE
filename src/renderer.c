//This header file is in charge of rendering according to the view
#include "renderer.h"

//window properties
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

//Primitives available

//MATRICES
mat4 projection;

void MultiplyMatrixVector(vec3 i,vec3 o,mat4 m){
	vec4 aux, transformed; glm_vec4(i,1.0f,aux); glm_vec4_zero(transformed);
	glm_mat4_mulv(m,aux,transformed);
	glm_vec4_copy3(transformed,o);
	if(transformed[3] != 0){
		o[0] /= transformed[3];
		o[1] /= transformed[3];
		o[2] /= transformed[3];
	}
}

//Drawing functions
void pixel(int x, int y,RGB* color){
	SDL_Rect Pixel = {x,y,PIXELSCALE,PIXELSCALE};
	SDL_SetRenderDrawColor(renderer,color->r,color->g,color->b,255);
	SDL_RenderFillRect(renderer, &Pixel);
}

bool isTransparent(RGB* color){
	return (color->r == 255 && color->g == 0 && color->b == 255);
}

void renderTest(){
	RGB c[3] = {{255,0,0},{0,255,0},{0,0,255}};
	int i = 0;
	for(int x = 0; x < 10; x++){
		for(int y = 0; y < 10; y++){
			pixel(x*PIXELSCALE, y*PIXELSCALE, &c[i]);
			i+=1;
			if(i >= 3)
				i = 0;
		}
	}
}

void DDA(int x0, int y0, int x1, int y1,RGB* c){
	int dx = x1 - x0;
	int dy = y1 - y0;
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	float xo = dx / (float)steps;
	float yo = dy / (float)steps;
	float x = x0;
	float y = y0;
	for(int i = 0; i <= steps; i++){
		pixel(round(x * PIXELSCALE),round(y*PIXELSCALE),c);
		x+=xo;
		y+=yo;
	}
}

void DrawTriangle(vec3 p1, vec3 p2, vec3 p3){
	RGB c = {255,255,255};
	DDA((int)p1[0],(int)p1[1],(int)p2[0],(int)p2[1],&c); 
	DDA((int)p2[0],(int)p2[1],(int)p3[0],(int)p3[1],&c); 
	DDA((int)p1[0],(int)p1[1],(int)p3[0],(int)p3[1],&c); 
}

void renderCubeTest(){
	MeshCube cube = CubePrimitive();
	glm_perspective(degToRad(FOV),ASPECT,ZNEAR,ZFAR,projection); float theta = 80.0f * (float)(SDL_GetTicks()/1000.0f);
	mat4 matRotZ, matRotX, matTranslated; glm_mat4_identity(matRotZ); glm_mat4_identity(matRotX); glm_mat4_identity(matTranslated);
	vec3 translate; translate[0] = 0.0f; translate[1] = 0.0f; translate[2] = 3.0f;
	vec3 xAxis; xAxis[0] = 1.0f; xAxis[1] = 0.0f; xAxis[2] = 0.0f;
	vec3 zAxis; zAxis[0] = 0.0f; zAxis[1] = 0.0f; zAxis[2] = 1.0f;
	mat4 mvp; glm_mat4_identity(mvp);
	glm_translate(matTranslated,translate); glm_rotate(matRotX,degToRad(theta),xAxis); glm_rotate(matRotZ,degToRad(theta),zAxis);
	glm_mat4_mulN((mat4 *[]){&projection,&matTranslated,&matRotX,&matRotZ},4,mvp);
	for(int i = 0; i < 12; i++){
		Triangle triProjected;
			//Multiply each vertex of the current triangle to projected it
		MultiplyMatrixVector(cube.triangles[i].p[0],triProjected.p[0],mvp);
		MultiplyMatrixVector(cube.triangles[i].p[1],triProjected.p[1],mvp);
		MultiplyMatrixVector(cube.triangles[i].p[2],triProjected.p[2],mvp);
		//Convert To Screen Coordinates the current triangle
		convertToScreenCoordinate(&triProjected);
		DrawTriangle(triProjected.p[0],triProjected.p[1],triProjected.p[2]);
	}
}

void convertToScreenCoordinate(Triangle* triProjected){
	//Scale into view
	//Scale into view - normalize
	triProjected->p[0][0] += 1.0f; triProjected->p[0][1] += 1.0f;
	triProjected->p[1][0] += 1.0f; triProjected->p[1][1] += 1.0f;
	triProjected->p[2][0] += 1.0f; triProjected->p[2][1] += 1.0f;
	// adjust into screen space
	triProjected->p[0][0] *= 0.5f * (float)SW;
	triProjected->p[0][1] *= 0.5f * (float)SH;
	triProjected->p[1][0] *= 0.5f * (float)SW;
	triProjected->p[1][1] *= 0.5f * (float)SH;
	triProjected->p[2][0] *= 0.5f * (float)SW;
	triProjected->p[2][1] *= 0.5f * (float)SH;
}
