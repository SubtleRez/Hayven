#include "Vec3.h"

Vec3::Vec3(float x_in, float y_in, float z_in)
	:
	x(x_in),
	y(y_in),
	z(z_in)
{
}

Vec3 Vec3::add(Vec3 a, Vec3 b)
{
	float sum_x = a.x + b.x;
	float sum_y = a.y + b.y;
	float sum_z = a.z + b.z;
	return Vec3(sum_x,sum_y,sum_z);
}

Vec3 Vec3::subtract(Vec3 a, Vec3 b)
{
	float diff_x = b.x - a.x;
	float diff_y = b.y - a.y;
	float diff_z = b.z - a.z;

	return Vec3(diff_x,diff_y,diff_z);
}

Vec3 Vec3::scale(Vec3 a, float c)
{
	float mul_x = a.x * c;
	float mul_y = a.y * c;
	float mul_z = a.z * c;

	return Vec3(mul_x,mul_y,mul_z);
}
