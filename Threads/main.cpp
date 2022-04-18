#include <iostream>
#include <thread>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <ctime>
#include <ratio>
#include <chrono>

#define R 10
#define N 500000
#define numbThreads 8

using namespace std;

struct point {
	float x = rand() % (2 * R);
	float y = rand() % (2 * R);
	float z = rand() % (2 * R);
	point (float x_ = 0, float y_ = 0, float z_ = 0) {
		x = x_;
		y = y_;
		z = z_;
	}
	float getDistance(point a) {
		return sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y) + (z - a.z) * (z - a.z));
	}
};

void func(int j, vector<point> points, int* count) {
	for (int i = j * N / numbThreads; i < (j + 1) * N / numbThreads; i++) {
		if (((points[i].x - R) * (points[i].x - R) + (points[i].y - R) * (points[i].y - R) + (points[i].z - R) * (points[i].z - R)) < R * R) {
			//if (points[i].getDistance(point(R, R, R)) <= R)
			(*count)++;
		}
	}
}

int main() {
	vector<point> points(N);
	vector<int> counts(numbThreads);
	vector<thread> threads(numbThreads);
	int count = 0;

	auto start = chrono::high_resolution_clock::now();

	for (int i = 0; i < numbThreads; i++) {
		threads[i] = thread(func, i, points, &counts[i]);
	}
	for (int i = 0; i < numbThreads; i++) {
		threads[i].join();
	}

	for (int i = 0; i < numbThreads; i++) {
		count = count + counts[i];
	}
	
	chrono::duration<double> time_span = chrono::high_resolution_clock::now() - start;

	float volume_est = 8 * R * R * R * count / N;
	float volume_act = 4 * M_PI * R * R * R / 3;
	cout << volume_est << "\n" << volume_act << "\nTime " << time_span.count() << "\n" << count;
}