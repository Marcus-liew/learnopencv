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

  QuickDemo qd;
  //qd.color_space_demo(src);
  qd.mat_creation_demo(src);

  return 0;
}
