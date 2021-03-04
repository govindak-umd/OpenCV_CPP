#include"opencv2/imgproc.hpp"
#include"opencv2/highgui.hpp"
#include"opencv2/videoio.hpp"
#include<iostream>
#include<String>

using namespace cv;


const int max_value_H = 360 / 2;
const int max_val = 255;

int low_h = 0;
int low_s = 0;
int low_v = 0;

int high_h = max_value_H;
int high_s = max_value_H;
int high_v = max_value_H ;

const String image_window = "Feed";
const String trackbar_window = "Trackbar";

static void low_h_thresh_track(int, void*) {
	low_h = min(high_h, low_h);
	setTrackbarPos("Low H", trackbar_window, low_h);
}

static void high_h_thresh_track(int, void*) {
	high_h = max(high_h, low_h);
	setTrackbarPos("High H", trackbar_window, high_h);
}

int main(int argc, char* argv[]) {
	VideoCapture cap(argc > 1 ? atoi(argv[1]) : 0);
	namedWindow(image_window);
	namedWindow(trackbar_window);

	createTrackbar("Low H", trackbar_window, &low_h, max_value_H, low_h_thresh_track);
	createTrackbar("High H", trackbar_window, &high_h, max_value_H, high_h_thresh_track);

	Mat frame;
	Mat frame_HSV;
	Mat frame_thresh;

	while (true) {
		cap >> frame;
		if (frame.empty()) {
			break;
		}

		//Convert image to HSV format

		cvtColor(frame, frame_HSV, COLOR_BGR2HSV);
		
		// Conversion to HSV based on the trackbar range

		inRange(frame_HSV, Scalar(low_h, low_s, low_v), Scalar(high_h, high_s, high_v), frame_thresh);

		//Showing the images

		imshow(image_window, frame);
		imshow(trackbar_window, frame_thresh);

		char key = (char)waitKey(20);
		if (key == 'q' || key == 27) {
			break;
		}
	}


	return 0;
}
