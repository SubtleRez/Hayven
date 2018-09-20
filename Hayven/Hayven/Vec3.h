#pragma once

class Vec3 {
private:
	float x, y, z;
public:
	Vec3(float x_in, float y_in, float z_in);

	// Math Functions
	Vec3 add(Vec3 a, Vec3 b);
	Vec3 subtract(Vec3 a, Vec3 b);
	Vec3 scale(Vec3 a, float c);
};