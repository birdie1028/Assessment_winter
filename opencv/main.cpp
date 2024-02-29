#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
int main()
{
	Mat srcMat = imread("/home/xch/project/Assessment_winter-main/opencv/huixingzhen/count.png", 0);
	Mat resMat;
	Mat binary;
	Mat binary_dec;
	Mat binary_sign;
	Mat Matstate;
	Mat center;
	Mat kernel(14, 14, CV_8UC1);
	threshold(srcMat, resMat, 100, 255, THRESH_OTSU);  
	bitwise_not(resMat, binary);
	imshow("binary", binary);
	connectedComponentsWithStats(binary, binary_sign, Matstate, center, 8, CV_32S);  
	int line = 0;
	int clipnum = 0;
	int i;
	line = Matstate.rows;
	for (i = 0; i < Matstate.rows; i++)
	{
		if (Matstate.at<int>(i, 4) >= 2000&& Matstate.at<int>(i, 4)<=8000)
		{

			clipnum = clipnum + 1;
			cv::Rect rect;
			rect.x = Matstate.at<int>(i, 0);
			rect.y = Matstate.at<int>(i, 1);
			rect.width = Matstate.at<int>(i, 2);
			rect.height = Matstate.at<int>(i, 3);
			rectangle(binary, rect, CV_RGB(255, 255, 255), 1, 8, 0);
		}

	}
	cout << clipnum << std::endl;
	imshow("Í¼Ïñ", binary);
	waitKey(0);
	return 0;
}
