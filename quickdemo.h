//
// Created by Apple on 2022/1/15.
//
#include <opencv2/opencv.hpp>

#ifndef LEARNOPENCV__QUICKDEMO_H_
#define LEARNOPENCV__QUICKDEMO_H_

using namespace cv;

class QuickDemo{
 public:
  // ------ 转换颜色空间 ------
  static void color_space_demo(Mat &image);
  // ------ 创建图像 ------
  static void mat_creation_demo(Mat &image);
  // ------ 像素读写 ------
  static void pixel_visit_demo(Mat &image);
  // ------ 像素操作 ------
  static void operation_demo(Mat &image);
  // ------ 像素操作(利用opencv api) ------
  static void operation_opencv_api_demo(Mat &image);
  // ------ 通过滚动条实现调整图像亮度，采用tracking bar ------
  static void tracking_bar_demo(Mat &image);
};


#endif //LEARNOPENCV__QUICKDEMO_H_
