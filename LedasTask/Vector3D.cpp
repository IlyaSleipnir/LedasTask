#include "Vector3D.h"
#include "cmath"

Vector3D::Vector3D(double x, double y, double z)
{
	X = x;
	Y = y;
	Z = z;
}

Vector3D::Vector3D()
{
}

Vector3D::~Vector3D()
{
}

Vector3D Vector3D::operator+ (const Vector3D vec) const
{
	return Vector3D(this->X + vec.X, this->Y + vec.Y, this->Z + vec.Z);
}

Vector3D Vector3D::operator- (const Vector3D vec) const
{
	return Vector3D(this->X - vec.X, this->Y - vec.Y, this->Z - vec.Z);
}

Vector3D Vector3D::operator* (const Vector3D vec) const
{
	return Vector3D(this->X * vec.X, this->Y * vec.Y, this->Z * vec.Z);
}

Vector3D Vector3D::operator* (const double num) const
{
	return Vector3D(this->X * num, this->Y * num, this->Z * num);
}