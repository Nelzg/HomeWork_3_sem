#include "Vector2.h"

float Vector2::len() {
	return sqrt(x * x + y * y);
}

float Vector2::len(float x) {
	return x;
}