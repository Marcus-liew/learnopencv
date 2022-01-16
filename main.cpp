#include <opencv2/opencv.hpp>
#include "quickdemo.h"
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc, char** argv) {
  Mat src = imread("/Users/apple/Downloads/111.png");
  if (src.empty()){
    cout << "could not open image..." << endl;
    return -1;
  }
  // ------ 打印src（也就是111.png）的宽度，高度，和通道数
  cout << "width:" << src.cols << endl;
  cout << "height:" << src.rows << endl;
  cout << "channels:" << src.channels() << endl;

  // ------ 创建一个QuickDemo对象qd ------
  QuickDemo qd;
  // ------ 转换颜色空间成员函数 ------
  //qd.color_space_demo(src);
  // ------ 调用创建图像成员函数 ------
  //qd.mat_creation_demo(src);
  // ------ 调用读写像素成员函数 ------
  //qd.pixel_visit_demo(src);
  // ------ 调用操作像素成员函数 ------
  qd.operation_demo(src);

  return 0;
}
