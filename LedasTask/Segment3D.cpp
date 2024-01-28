#include "Segment3D.h"
#include <cmath>

Segment3D::Segment3D(Vector3D start_vec, Vector3D end_vec)
{
	start = start_vec;
	end = end_vec;
}

Segment3D::Segment3D()
{
}

Segment3D::~Segment3D()
{
}

std::pair<bool, Vector3D> Segment3D::Intersect(Segment3D seg)
{
	double eps = 10e-7;

	// p_i - направл€ющий вектор пр€мой 
	Vector3D p1 = this->end - this->start;
	Vector3D p2 = seg.end - seg.start;

	// канонический вид пр€мой: (x - start.x) / p.x = (y - start.y) / p.y = (z - start.z) / p.z
	Vector3D solve[3];
	int ind1 = -1, ind2 = -1;

	// столбец s1
	solve[0].X = p1.X;
	solve[1].X = p1.Y;
	solve[2].X = p1.Z;

	// столбец s2
	solve[0].Y = -p2.X;
	solve[1].Y = -p2.Y;
	solve[2].Y = -p2.Z;

	// свободный член
	solve[0].Z = seg.start.X - this->start.X;
	solve[1].Z = seg.start.Y - this->start.Y;
	solve[2].Z = seg.start.Z - this->start.Z;

	for (int i = 0; i < 3; i++)
	{
		if (abs(solve[i].X) >= eps)
		{
			ind1 = i;
			break;
		}
	}

	if (ind1 == -1)
	{
		return std::make_pair(false, Vector3D());
	}

	for (int i = 0; i < 3; i++)
	{
		if (i == ind1 || abs(solve[i].X) < eps)
			continue;

		double coef = solve[i].X / solve[ind1].X;

		solve[i] = solve[i] - solve[ind1] * coef;
	}

	for (int i = 0; i < 3; i++)
	{
		if (abs(solve[i].Y) >= eps && i != ind1)
		{
			ind2 = i;
			break;
		}
	}

	if (ind2 == -1)
	{
		return std::make_pair(false, Vector3D());
	}

	double s2 = solve[ind2].Z / solve[ind2].Y;
	double s1 = (solve[ind1].Z - solve[ind1].Y * s2) / solve[ind1].X;

	if ( s1 < 0 || s1 > 1 || s2 < 0 || s2 > 1)
	{
		// точка пересечени€ лежить вне отрезков
		return std::make_pair(false, Vector3D());
	}

	Vector3D vec1 = p1 * s1 + this->start;
	Vector3D vec2 = p2 * s2 + seg.start;

	if (abs(vec1.X - vec2.X) >= eps ||
		abs(vec1.Y - vec2.Y) >= eps ||
		abs(vec1.Z - vec2.Z) >= eps)
	{
		return std::make_pair(false, Vector3D());
	}

	return std::make_pair(true, p1 * s1 + this->start);
}