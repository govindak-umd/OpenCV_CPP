#include<opencv2/core.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>

//variable declarations
#define w 400
#define thickness 2

using namespace cv;

//circle function prototype
void MyFilledCircle(Mat img, Point center);
//line funcstion prototype
void DrawLine(Mat img, Point point1, Point point2);

int main() {

	//declaring a black zeros image
	Mat img = Mat::zeros(w, w, CV_8UC3);
	//Generate a window to do all the drawings
	namedWindow("Image_Window", WINDOW_NORMAL);

	//Draw the shapes

	MyFilledCircle(img, Point(w / 2, w / 2));
	DrawLine(img, Point(0, 0), Point(w / 4, w / 4));
	
	//Show the image
	imshow("Image_Window", img);
	//Hold until a key is pressed
	waitKey(0);
	return 0;
}

//drawing a circle 
void MyFilledCircle(Mat img, Point center) {
	circle(img, center, w / 32, Scalar(0, 0, 255), FILLED, LINE_AA);
}

//drawing a line
void DrawLine(Mat img, Point point1, Point point2) {
	line(img, point1, point2, Scalar(255, 24, 56), thickness, LINE_8);
}
