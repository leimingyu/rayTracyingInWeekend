#include <iostream>
#include <math.h>

// vec3.h
class vec3
{

public:
	vec3() {}
	vec3(float e0, float e1, float e2) {e[0] = e0; e[1] = e1; e[2] = e2; }

	inline float x() const { return e[0]; }
	inline float y() const { return e[1]; }
	inline float z() const { return e[2]; }

	inline float r() const { return e[0]; }
	inline float g() const { return e[1]; }
	inline float b() const { return e[2]; }

	inline const vec3& operator+() const { return *this; }
	inline vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

	inline float  operator[](int i) const { return e[i]; }
	inline float& operator[](int i)       { return e[i]; }

	inline vec3& operator+=(const vec3 &v2);
	inline vec3& operator-=(const vec3 &v2);
	inline vec3& operator*=(const vec3 &v2);
	inline vec3& operator/=(const vec3 &v2);

	inline vec3& operator*=(const float t) {
		e[0] *= t;
		e[1] *= t;
		e[2] *= t;
		return *this;
	}
	inline vec3& operator/=(const float t);

	inline float length()         const { return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]); }
	inline float squared_length() const { return e[0]*e[0] + e[1]*e[1] + e[2]*e[2]; }
	inline void make_unit_vector();

	float e[3];
};

// vec3 utility
inline vec3 operator*(float t, const vec3 &v) {
	return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3 &v, float t) {
	return t * v;
}

inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

// division
inline vec3 operator/(vec3 v, double t) {
    return (1/t) * v;
}

// unit vector
inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}



// ray.h
class ray
{
	public:
		ray() {}
		ray(const vec3 &a, const vec3 &b) { A = a; B = b; }
		vec3 origin()    const { return A; }
		vec3 direction() const { return B; }
		vec3 point_at_parameter(float t) const { return A + t*B; }

		vec3 A;
		vec3 B;
};


// color function : return the background color
vec3 color(const ray& r)
{
	vec3 unit_direction = unit_vector(r.direction());
	float t = 0.5 * (unit_direction.y() + 1.0);
	return (1.0-t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}


int main() {

    // chapter 1: image 
    int nx = 200;  //col, width
    int ny = 100;  //row, height 

    std::cout << "P3\n" << nx << ' ' <<  ny << "\n255\n";

    vec3 origin(0.0, 0.0, 0.0); 		// camera center
    vec3 lower_left_corner(-2.0, -1.0, -1.0); 	// where ray starts

    // two vectors to move the ray endpoint across screen
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);


    // rows : decreasing , top down
    // cols:  increasing, left to right
    for (int j = ny-1; j >= 0; j--)
    {
        for (int i = 0; i < nx; i++) 
	{
		// generate r/g/b color : 0.0  - 1.0
		float u = float(i) / float(nx);
		float v = float(j) / float(ny);

		ray r(origin, lower_left_corner + u * horizontal + v * vertical);

		vec3 col =  color(r);	

		int ir = int(255.99 * col[0]);
		int ig = int(255.99 * col[1]);
		int ib = int(255.99 * col[2]);

		std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
}
