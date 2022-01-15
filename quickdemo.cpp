//
// Created by Apple on 2022/1/15.
//

#include "quickdemo.h"

using namespace cv;

void QuickDemo::color_space_demo(Mat &image){
  Mat hsv, gray;

  cvtColor(image, hsv, COLOR_BGR2HSV);
  cvtColor(image, gray, COLOR_BGR2GRAY);

  imshow("bgr", image);
  imshow("bgr2hsv", hsv);
  imshow("bgr2gray", gray);

  imwrite("/Users/apple/Desktop/bgr2hsv.jpeg", hsv);
  imwrite("/Users/apple/Desktop/bgr2gray.jpeg", gray);
  imwrite("/Users/apple/Desktop/bgr.jpeg", image);


}