#include"opencv2/core/core.hpp"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<vector>

int main() {

	cv::Mat img = cv::imread("amg.jpg", cv::IMREAD_COLOR);
    //cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);
    //cv::imshow("Display window", img);
    //cv::waitKey(0);

    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    cv::Canny(gray, gray, 100, 200, 3);

    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    // Random Number Generator

    cv::RNG rng(1231216);

    cv::findContours(gray, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

    // To draw the contours

    cv::Mat drawing = cv::Mat::zeros(gray.size(), CV_8UC3);

    for (int i = 0; i < contours.size(); i++) {
        cv::drawContours(drawing, contours, i, cv::Scalar(0, 0, 255), 2, 8, hierarchy, 0,cv::Point());
    }

    cv::imshow("Result of Contour", drawing);

    cv::waitKey(0);
    return 0;
}
