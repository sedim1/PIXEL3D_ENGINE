#include "Mesh.h"

MeshCube CubePrimitive(){
	MeshCube cube;
	//front face
	vec3 p1 = {0,0,0};
	vec3 p2 = {0,1,0};
	vec3 p3 = {1,1,0};
	vec3 p4 = {1,0,0};
	//back face
	vec3 p5 = {0,1,1};
	vec3 p6 = {1,1,1};
	vec3 p7 = {0,0,1};
	vec3 p8 = {1,0,1};

	// Front
	glm_vec3_copy(p1, cube.triangles[0].p[0]);
	glm_vec3_copy(p2, cube.triangles[0].p[1]);
	glm_vec3_copy(p3, cube.triangles[0].p[2]);
	
	glm_vec3_copy(p1, cube.triangles[1].p[0]);
	glm_vec3_copy(p3, cube.triangles[1].p[1]);
	glm_vec3_copy(p4, cube.triangles[1].p[2]);

	// Back
	glm_vec3_copy(p7, cube.triangles[2].p[0]);
	glm_vec3_copy(p6, cube.triangles[2].p[1]);
	glm_vec3_copy(p5, cube.triangles[2].p[2]);
	
	glm_vec3_copy(p7, cube.triangles[3].p[0]);
	glm_vec3_copy(p8, cube.triangles[3].p[1]);
	glm_vec3_copy(p6, cube.triangles[3].p[2]);

	// Left
	glm_vec3_copy(p7, cube.triangles[4].p[0]);
	glm_vec3_copy(p5, cube.triangles[4].p[1]);
	glm_vec3_copy(p2, cube.triangles[4].p[2]);
	
	glm_vec3_copy(p7, cube.triangles[5].p[0]);
	glm_vec3_copy(p2, cube.triangles[5].p[1]);
	glm_vec3_copy(p1, cube.triangles[5].p[2]);

	// Right
	glm_vec3_copy(p4, cube.triangles[6].p[0]);
	glm_vec3_copy(p3, cube.triangles[6].p[1]);
	glm_vec3_copy(p6, cube.triangles[6].p[2]);
	
	glm_vec3_copy(p4, cube.triangles[7].p[0]);
	glm_vec3_copy(p6, cube.triangles[7].p[1]);
	glm_vec3_copy(p8, cube.triangles[7].p[2]);

	// Top
	glm_vec3_copy(p2, cube.triangles[8].p[0]);
	glm_vec3_copy(p5, cube.triangles[8].p[1]);
	glm_vec3_copy(p6, cube.triangles[8].p[2]);
	
	glm_vec3_copy(p2, cube.triangles[9].p[0]);
	glm_vec3_copy(p6, cube.triangles[9].p[1]);
	glm_vec3_copy(p3, cube.triangles[9].p[2]);

	// Bottom
	glm_vec3_copy(p1, cube.triangles[10].p[0]);
	glm_vec3_copy(p7, cube.triangles[10].p[1]);
	glm_vec3_copy(p8, cube.triangles[10].p[2]);
	
	glm_vec3_copy(p1, cube.triangles[11].p[0]);
	glm_vec3_copy(p8, cube.triangles[11].p[1]);
	glm_vec3_copy(p4, cube.triangles[11].p[2]);
	return cube;
}
