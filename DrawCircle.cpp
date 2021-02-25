#include<opencv2/core.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>

//variable declaration
#define w 400

using namespace cv;

//circle function prototype
void MyFilledCircle(Mat img, Point center);

int main() {

	//declaring a black zeros image
	Mat img = Mat::zeros(w, w, CV_8UC3);
	namedWindow("Image_Window", WINDOW_NORMAL);
	MyFilledCircle(img, Point(w / 2, w / 2));
	imshow("Image_Window", img);
	waitKey(0);
	return 0;
}

//drawing a circle 
void MyFilledCircle(Mat img, Point center) {
	circle(img, center, w / 32, Scalar(0, 0, 255), FILLED, LINE_AA);
}
