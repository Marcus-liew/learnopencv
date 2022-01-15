#include <opencv2/opencv.hpp>
#include "quickdemo.h"
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc, char** argv) {
  Mat src = imread("/Users/apple/Downloads/111.jpeg");
  if (src.empty()){
    cout << "could not open image..." << endl;
    return -1;
  }

  imshow("show", src);

  QuickDemo qd;

  qd.color_space_demo(src);

  waitKey(0);
  destroyAllWindows();

  return 0;
}
