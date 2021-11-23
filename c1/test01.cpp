//
// Created by Administrator on 2021/11/12.
//
#include <opencv2/opencv.hpp>

int main(){
    cv::Mat img = cv::imread("img/92732188_p0_master1200.jpg");
    cv::imshow("img",img);
    cv::waitKey(0);
    cv::destroyAllWindows();
}