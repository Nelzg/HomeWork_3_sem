#include <opencv/cv.hpp>
#include <opencv/highgui.h>
#include <iostream>

using namespace cv;

int main()
{
	Mat image;
	image = imread("D:/PROJECTS_INFA/HomeWork_3_sem/Opencv/src/загружено.jpg", CV_LOAD_IMAGE_COLOR);

	if (!image.data) {
		std::cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	Mat blured;
	GaussianBlur(image, blured, Size(15,15), 0, 0);

	Mat grayScale;
	cvtColor(blured, grayScale, COLOR_BGR2GRAY);

	Mat dx, dy;
	Sobel(grayScale, dx, CV_32F, 1, 0);
	Sobel(grayScale, dy, CV_32F, 1, 0);

	Mat mag, ang;
	cartToPolar(dx, dy, mag, ang);

	auto it = std::max_element(mag.begin<float>(), mag.end<float>());
	auto max_elem = mag.at<float>(it.pos());
	mag /= max_elem;

	namedWindow("Display window", WINDOW_AUTOSIZE);
	imshow("Display window", ang);

	waitKey(0);
	return 0;
}
