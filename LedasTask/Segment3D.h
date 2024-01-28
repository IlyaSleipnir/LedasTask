#pragma once
#include "Vector3D.h"
#include <map>

class Segment3D
{
public:
	Vector3D start;
	Vector3D end;

	Segment3D(Vector3D start_vec, Vector3D end_vec);
	Segment3D();
	~Segment3D();
	std::pair<bool, Vector3D> Intersect(Segment3D seg);

private:

};