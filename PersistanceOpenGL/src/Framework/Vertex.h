#pragma once

struct Vertex
{
	Vertex(float v0, float v1, float v2, float tex0, float tex1, float norm0, float norm1, float norm2)
		:x(v0), y(v1), z(v2), u(tex0), v(tex1), n0(norm0), n1(norm1), n2(norm2)
	{};
	
	
	float x, y, z, u, v, n0, n1 ,n2;



	
};
