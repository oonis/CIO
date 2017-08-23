#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

void findFaces(CascadeClassifier face_cascade, Mat frame) {
	vector<Rect> faces;
	Mat frame_gray;
	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 3,
		0|CASCADE_SCALE_IMAGE, Size(30, 30));

	for( size_t i = 0; i < faces.size(); i++ ) {
		Rect face = faces[i];
		Point center(faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2);

		rectangle(frame,Point(face.x,face.y),
			Point(face.x+ face.width,face.y+face.height), Scalar(255,0,255),3,8,0 );
		
	}
	imshow("Camera view", frame);
}

int main() {
  
	VideoCapture cap(0);
	if(!cap.isOpened()) {
		cout << "Unable to open camera" << endl;
		return 1;
	}

	Mat frame;

	// Load classifiers: assuming we're in build for now
	CascadeClassifier face_cascade;
	face_cascade.load("../resources/haarcascade_frontalface_default.xml");
  
	while(cap.read(frame) && waitKey(1) != '\33') {
		findFaces(face_cascade,frame);
	}
	return 0;
}
