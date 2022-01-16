//
// Created by Apple on 2022/1/15.
//

#include "quickdemo.h"
#include <iostream>
// ------ 使用cv名字空间 ------
using namespace cv;
using namespace std;

// ------ 转换颜色空间 ------
void QuickDemo::color_space_demo(Mat &image){
  cout << "进入了color_space_demo" << endl;
  Mat hsv, gray;
  // ------ 转换色彩空间 ------
  cvtColor(image, hsv, COLOR_BGR2HSV);
  cvtColor(image, gray, COLOR_BGR2GRAY);
  // ------ 显示图片 ------
  imshow("原始图像BGR", image);
  imshow("原始图像BGR->HSV", hsv);
  imshow("原始图像BGR->GRAY", gray);
  // ------ 保存图片 ------
  imwrite("/Users/apple/Desktop/bgr2hsv.png", hsv);
  imwrite("/Users/apple/Desktop/bgr2gray.png", gray);
  imwrite("/Users/apple/Desktop/bgr.png", image);

  waitKey(0);
  destroyAllWindows();
}

// ------ 创建图像 ------
void QuickDemo::mat_creation_demo(Mat &image) {
  Mat m1, m2, m3, m4, kernel;

  // ------ 用zeros创建一张 800*600 (单/3通道) 的空图片
  m1 = Mat::zeros(Size(480,320), CV_8UC(3));
  // ------ 用Scalar函数给每个像素点的每个通道负值
  m1 = Scalar(255, 0, 0);
  // ------ m2=m1，相当于m2和m1是同一个东西，改变m2就是改变m1
  m2 = m1;
  m2 = Scalar(0, 255, 0);
  // ------ clone方式相当于新生成了一个对象，m3与m1是不同的，改变m3不改变m1
  m3 = m1.clone();
  m3 = Scalar(0, 0, 255);
  // ------ copyTo的方式也是新生成一个，m4与m1也是不同的
  m1.copyTo(m4);
  m4 = Scalar(127, 127, 127);

  kernel = (Mat_<char>(3,3) << 0,-1,0,-1,5,-1,0,-1,0);
  // ------ 输出图像 ------
  imshow("m1", m1);
  imshow("m2", m2);
  imshow("m3", m3);
  imshow("m4", m4);
  imshow("kernel", kernel);

  waitKey(0);
  destroyAllWindows();
}

// ------ 像素读写 ------
void QuickDemo::pixel_visit_demo(Mat &image) {
  int width = image.cols;
  int height = image.rows;
  int dims = image.channels();

  // ------ (1) 通过数组方式 ------
//  for (int row = 0; row < width; ++row) {
//    for (int col = 0; col < height; ++col) {
//      if (dims == 1){
//        int pv = image.at<uchar>(row, col);
//        image.at<uchar>(row, col) = 255 - pv;
//      }
//      if (dims == 3){
//        Vec3b bgr = image.at<Vec3b>(row, col);
//        image.at<Vec3b>(row, col)[0] = 255 - bgr[0];
//        image.at<Vec3b>(row, col)[1] = 255 - bgr[1];
//        image.at<Vec3b>(row, col)[2] = 255 - bgr[2];
//      }
//    }
//  }

  // ------ (2) 通过指针方式 ------
  for (int row = 0; row < height; ++row) {
    uchar * current_row = image.ptr<uchar>(row);
    for (int col = 0; col < width; ++col) {
      if (dims == 1){
        int pv = *current_row;
        *current_row++ = 255 - pv;
      }
      if (dims == 3){
        *current_row++ = 255 - *current_row;
        *current_row++ = 255 - *current_row;
        *current_row++ = 255 - *current_row;
      }
    }
  }

  imshow("image", image);
  //imwrite("/Users/apple/Desktop/result.png", image);
  waitKey(0);
  destroyAllWindows();

}

// ------ 像素操作（不用OPENCV API） ------
void QuickDemo::operation_demo(Mat &image) {
  Mat dst_add, dst_subtract, dst_multiply, dst_divide;
  // ------ 操作（1）加/减/乘/除 ------
  dst_add = image + Scalar(50,50,50);
  dst_subtract = image - Scalar(50,50,50);
  dst_multiply = image * 3.6; //注意乘法不要用Scalar函数，直接乘数字
  dst_divide = image / 4;     //注意除法不要用Scalar函数，直接除数字

  // ------ 输出 ------
  imshow("dst_plus", dst_add);
  imshow("dst_subtract", dst_subtract);
  imshow("dst_multiply", dst_multiply);
  imshow("dst_divide", dst_divide);

  waitKey(0);
  destroyAllWindows();

}

// ------ 像素操作(利用opencv api) ------
void QuickDemo::operation_opencv_api_demo(Mat &image) {
  Mat dst_add, dst_subtract, dst_multiply, dst_divide;
  Mat tmp = Mat::zeros(image.size(), image.type());

  // ------ 利用opencv api add()，实现像素相加 ------
  tmp = Scalar(50,50,50);
  add(image, tmp, dst_add);

  // ------ 利用opencv api subtract()，实现像素相减 ------
  tmp = Scalar(50,50,50);
  subtract(image, tmp, dst_subtract);

  // ------ 利用opencv api multiply()，实现像素相减 ------
  tmp = Scalar(2, 2, 2);
  multiply(image, tmp, dst_multiply);

  // ------ 利用opencv api divide()，实现像素相减 ------
  tmp = Scalar(4, 4, 4);
  divide(image, tmp, dst_divide);

  // ------ 显示图片 ------
  imshow("origin", image);
  imshow("add", dst_add);
  imshow("subtract", dst_subtract);
  imshow("multiply", dst_multiply);
  imshow("divide", dst_divide);

  waitKey(0);
  destroyAllWindows();
}

// ------ 通过滚动条实现调整图像亮度，采用tracking bar ------
// ------ 回调函数 ------
Mat m, dst, tmp;
int lightness = 50;
static void on_track(int, void*){
  m = Scalar(lightness, lightness, lightness);
  add(tmp, m, dst);
  imshow("original", tmp);
  imshow("亮度调整", dst);

  waitKey(0);
  destroyAllWindows();
}

void QuickDemo::tracking_bar_demo(Mat &image){
  namedWindow("亮度调整", WINDOW_AUTOSIZE);
  dst = Mat::zeros(image.size(), image.type());
  m = Mat::zeros(image.size(), image.type());
  tmp = image;
  //int max_value = 100;

  createTrackbar("lightness_bar", "亮度调整", &lightness, 100, on_track);
  //setTrackbarPos("lightness_bar", "亮度调整", lightness);
  on_track(50, 0);
}
