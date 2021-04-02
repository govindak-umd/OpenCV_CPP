#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>


int main() {

	cv::Mat src = cv::imread("hands.jpg", cv::IMREAD_COLOR);

	cv::Mat src_grayed;
	cv::RNG rng(1233);


	// gray the image
	cv::cvtColor(src, src_grayed, cv::COLOR_BGR2GRAY);

	// blur the image

	cv::blur(src_grayed, src_grayed, cv::Size(5, 5));

	cv::namedWindow("Image", cv::WINDOW_AUTOSIZE);

	cv::imshow("Image", src);
	cv::waitKey(0);

	return 0;
}
