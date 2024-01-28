#pragma once

class Vector3D
{
public:
	double X;
	double Y;
	double Z;

	Vector3D(double x, double y, double z);
	Vector3D();
	~Vector3D();
	Vector3D operator+ (const Vector3D vec) const;
	Vector3D operator- (const Vector3D vec) const;
	Vector3D operator* (const Vector3D vec) const;
	Vector3D operator* (const double num) const;

private:

};