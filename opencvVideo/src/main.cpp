#include <opencv/cv.hpp>
#include <opencv/highgui.h>
#include <iostream>
#include <vector>

using namespace cv;
CascadeClassifier face_cascade;

void detectFace(Mat frame) {
	std::vector<Rect> faces;
	Mat frame_gray;
	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

	for (const auto& f : faces) {
		Point pt1(f.x, f.y);
		Point pt2(f.x + f.height, f.y + f.width);
		rectangle(frame, pt1, pt2, Scalar(0, 255, 0), 2, 8, 0);
	}

	imshow("frame", frame);
	if (waitKey(30) == 27) return;
}

int main()
{
	VideoCapture cap(0);
	if (!cap.isOpened())
		return -1;
	namedWindow("frame", CV_WINDOW_AUTOSIZE);

	if (!face_cascade.load("haarcascades/haarcascade_frontalface_alt.xml")) {
		printf("Error\n");
		return -1;
	}

	while (true) {
		Mat frame;
		cap >> frame;

		/*Mat blured;
		GaussianBlur(frame, blured, Size(15, 15), 0, 0);

		Mat grayScale;
		cvtColor(blured, grayScale, COLOR_BGR2GRAY);

		Mat dX, dY;
		Sobel(grayScale, dX, CV_32F, 1, 0);
		Sobel(grayScale, dY, CV_32F, 0, 1);

		Mat mag, ang;
		cartToPolar(dX, dY, mag, ang);

		Mat frameEdges;
		Canny(frame, frameEdges, 100, 200);*/

		//Mat lightScale;
		//cvtColor(frameEdges, lightScale, COLOR_HSV2BGR);

		detectFace(frame);

		//auto it = std::max_element(mag.begin<float>(), mag.end<float>());
		//auto max_elem = mag.at<float>(it.pos());
		//mag /= max_elem;
		
		//imshow("frame", frame);
		//if (waitKey(30) == 27) break;
	}
	return 0;
}
