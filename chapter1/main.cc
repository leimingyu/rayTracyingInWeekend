#include <iostream>

int main() {

    // chapter 1: image 
    int nx = 200;  //col, width
    int ny = 100;  //row, height 

    std::cout << "P3\n" << nx << ' ' <<  ny << "\n255\n";

    for (int j = ny-1; j >= 0; j--)
    {
	// rows : decreasing , top down
        //std::cerr << "\rWorking on row : " << j << ' ' << std::flush;

	// cols:  increasing, left to right
        for (int i = 0; i < nx; i++) 
	{
		// generate r/g/b color : 0.0  - 1.0
		float r = float(i) / float(nx);
		float g = float(j) / float(ny);
		float b = 0.2f;

		int color_r = int(255.99 * r);
		int color_g = int(255.99 * g);
		int color_b = int(255.99 * b);

		// red from left to right
		// green from bottom to top
		// red and green makes yellow, therefore upper right shoud be yellow
		std::cout << color_r << " " << color_g << " " << color_b << "\n";
        }
    }
}
