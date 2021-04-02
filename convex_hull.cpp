#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

cv::Mat src_grayed;
cv::RNG rng(1233);
int thresh = 100;

void thresh_callback(int, void*);

int main() {

	cv::Mat src = cv::imread("hands.jpg", cv::IMREAD_COLOR);

	// gray the image
	cv::cvtColor(src, src_grayed, cv::COLOR_BGR2GRAY);

	// blur the 
	cv::blur(src_grayed, src_grayed, cv::Size(5, 5));

	// Window showing the actual image
	cv::namedWindow("Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Image", src);
	
	const int max_thresh = 255;
	cv::createTrackbar("Canny threshold", "Image", &thresh, max_thresh, thresh_callback);
	thresh_callback(0, 0);

	cv::waitKey();

	return 0;
}

/**
 * @brief Call back for the trackbar
 * @param  
 * @param  
*/
void thresh_callback(int, void*) {
	cv::Mat canny_output;
	cv::Canny(src_grayed, canny_output, thresh, thresh*2);

	std::vector<std::vector<cv::Point>> contours;

	cv::findContours(canny_output, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

	std::vector<std::vector<cv::Point>> convex_hull_pts(contours.size());
	
	for (size_t i = 0; i < contours.size(); i++) {
		cv::convexHull(contours[i], convex_hull_pts[i]);
	}

	cv::Mat drawing = cv::Mat::zeros(canny_output.size(), CV_8UC3);

	for (size_t i = 0; i < contours.size(); i++) {
		cv::drawContours(drawing, contours, (int) i, cv::Scalar(0, 0, 255));
		cv::drawContours(drawing, convex_hull_pts, (int) i, cv::Scalar(255, 0, 0));
	}

	cv::imshow("Convex Hull Drawing", drawing);
}	
