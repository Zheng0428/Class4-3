#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat lableMat;
	Mat statsMat;
	Mat centerMat;
	Mat dstMat;
	Mat outMat;
	Mat srcMat = imread("D:\\a\\5.jpg", 0);
	threshold(srcMat, dstMat, 100, 255, THRESH_BINARY_INV);
	/*int nComp = cv::connectedComponentsWithStats(dstMat,
		lableMat,
		statsMat,
		centerMat,
		8,
		CV_32S);*/
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(12, 12));		//¾ØÐÎ 9*9
	morphologyEx(dstMat, outMat, MORPH_ERODE, element);		//¸¯Ê´
	int nComp = cv::connectedComponentsWithStats(outMat,
		lableMat,
		statsMat,
		centerMat,
		8,
		CV_32S);
	cout << nComp-1 << endl;
	imshow("erode", outMat);
	waitKey(0);
	return 0;
}