#include<iostream>
#include"opencv2/imgproc.hpp"
#include"opencv2/imgcodecs.hpp"
#include"opencv2/highgui.hpp"

using namespace std;
using namespace cv;

int MAX_KERNEL_LENGTH = 25;
char window_name[] = "Demo";
Mat src;
Mat dst;
int main() {
	namedWindow(window_name, WINDOW_AUTOSIZE);

    std::string image_path = samples::findFile("amg.jpg");
    Mat src= imread(image_path, IMREAD_COLOR);
    //clones the source image

    dst = src.clone();
    imshow(window_name, dst);
    waitKey(0);
    
    //blurring

    blur(src, dst, Size(MAX_KERNEL_LENGTH, MAX_KERNEL_LENGTH) , Point(-1, -1));
    imshow(window_name, dst);
    waitKey(0);

    //Gaussian blurring

    GaussianBlur(src, dst, Size(MAX_KERNEL_LENGTH, MAX_KERNEL_LENGTH), 0, 0);
    imshow(window_name, dst);
    waitKey(0);

    return 0;

}
