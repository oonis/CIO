#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
 
int main() {
	VideoCapture stream1(0);   //ID 0 for first camera source
 
	if (!stream1.isOpened()) {
		cout << "Unable to open camera" << endl;
	}
 
	while (true) {
		Mat cameraFrame;
		stream1.read(cameraFrame);
		imshow("camera", cameraFrame);
		if (waitKey(30) == 27)
			break;
	}
	return 0;
}
