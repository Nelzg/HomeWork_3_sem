#pragma once
#include <iostream>
#include "Vector2.h"
#define _USE_MATH_DEFINES
#include <math.h>

int main() {
	Vector2 a(1, 0);
	Vector2 b(0, 1);
	//a += b;
    a.getRotated(90);
	std::cout << a.x << " " << a.y << "\n";
	a.getRotated((2*180 - 180 / 2));
	std::cout << a.len(a.x)<< " " << a.len(a.y) << "\n";
	std::cout << a.len() << "\n";
	std::cout << a.squareLen() << "\n";
	std::cout << a.norm().x << " " << a.norm().y << "\n";
	std::cout << (a + b).x << " " << (a + b).y << "\n";
	std::cout << (a - b).x << " " << (a - b).y << "\n";
	std::cout << (a * 2).x << " " << (a * 3).y << "\n";	
	std::cout << (a ^ b) << "\n";
	std::cout << (a / 3).x << " " << (a / 2).y << "\n";
	std::cout << a * b << "\n";
	std::cout << (a += b).x << " " << (a += b).y << "\n";
	std::cout << (a -= b).x << " " << (a -= b).y << "\n";
	std::cout << (a.getRotated(M_PI)).x << " " << (a.getRotated(0)).y << "\n";
	std::cout << (a.rotate(M_PI - M_PI / 2)).x << " " << (a.rotate(M_PI - M_PI / 2)).y << "\n";
}

