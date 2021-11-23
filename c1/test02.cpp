//
// Created by Administrator on 2021/11/12.
//
#include <opencv2/opencv.hpp>

int main(){
    cv::Mat img = cv::Mat(200,200,CV_8UC3,cv::Scalar(0,0,255));
    cv::imshow("pic",img);
    cv::waitKey(0);
    cv::destroyAllWindows();
}
