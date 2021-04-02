#include"opencv2/core/core.hpp"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<vector>

int main() {

	cv::Mat img;

	img = cv::imread("shapes.png", cv::IMREAD_COLOR);

	cv::Mat gray_img;

	gray_img = cv::imread("shapes.png", cv::IMREAD_GRAYSCALE);

	// To draw the contours on

	cv::Mat drawing = cv::Mat::zeros(gray_img.size(), CV_8UC3);

	// To draw the bounding rectangle on

	cv::Mat rect_drawing= cv::Mat::zeros(gray_img.size(), CV_8UC3);
	
	cv::Canny(gray_img, gray_img, 10, 150, 3);

	std::vector<std::vector<cv::Point>> contours;

	std::vector<cv::Vec4i> hierarchy;

	cv::findContours(gray_img, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));


	// To check for the largest area and draw a box around it
	double largest_area = 0;
	double curr_area = 0;
	int largest_contour_idx = 0;
	cv::Rect largest_bounding_rectangle;

	for (int i = 0; i < contours.size(); i++) {
		
		curr_area = cv::contourArea(contours[i], false);
		
		if (curr_area > largest_area) {
			largest_area = curr_area;
			std::cout << "Largest area has been changed to : " << largest_area << std::endl;
			largest_bounding_rectangle = cv::boundingRect(contours[i]);
		}

		// Draw all the contours on the drawing image

		cv::drawContours(drawing, contours, i, cv::Scalar(0, 0, 255), cv::FILLED, 8, hierarchy, 0, cv::Point());


	}

	// Draw the biggest contour bounding rectangle

	cv::rectangle(rect_drawing, largest_bounding_rectangle, cv::Scalar(0, 25, 65), 1, 8, 0);
	cv::imshow("Result of Contour", drawing);
	cv::imshow("Bounding rectangle", rect_drawing);
	cv::waitKey(0);
	return 0;

}
