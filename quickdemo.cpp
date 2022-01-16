//
// Created by Apple on 2022/1/15.
//

#include "quickdemo.h"
#include <iostream>
//----------- 使用cv名字空间 -----------
using namespace cv;
using namespace std;

void QuickDemo::color_space_demo(Mat &image){
  cout << "进入了color_space_demo" << endl;
  Mat hsv, gray;
  //----------- 转换色彩空间 -----------
  cvtColor(image, hsv, COLOR_BGR2HSV);
  cvtColor(image, gray, COLOR_BGR2GRAY);
  //----------- 显示图片 -----------
  imshow("原始图像BGR", image);
  imshow("原始图像BGR->HSV", hsv);
  imshow("原始图像BGR->GRAY", gray);
  //----------- 保存图片 -----------
  imwrite("/Users/apple/Desktop/bgr2hsv.png", hsv);
  imwrite("/Users/apple/Desktop/bgr2gray.png", gray);
  imwrite("/Users/apple/Desktop/bgr.png", image);

  waitKey(0);
  destroyAllWindows();
}

void QuickDemo::mat_creation_demo(Mat &image) {
  Mat m1, m2, m3, m4;

  //----------- 用zeros创建一张 800*600 (单/3通道) 的空图片 -----------
  m1 = Mat::zeros(Size(480,320), CV_8UC(3));
  //----------- 用Scalar函数给每个像素点的每个通道负值 -----------
  m1 = Scalar(255, 0, 0);

  m2 = m1;
  m2 = Scalar(0, 255, 0);

  m3 = m1.clone();
  m3 = Scalar(0, 0, 255);

  m1.copyTo(m4);
  m3 = Scalar(127, 127, 127);

  imshow("m1", m1);
  imshow("m2", m2);
  imshow("m3", m3);
  imshow("m4", m4);

  waitKey(0);
  destroyAllWindows();
}