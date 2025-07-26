#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>

//For locking

#include<windows.h>   // For locking the screen
#include<thread>      // To pause before locking (optional)


using namespace std;
using  namespace cv;


bool isLocked = false;

void lockScreen() {
	cout << "More than 1 face detected. Locking screen in 3 seconds..." << endl;
	this_thread::sleep_for(chrono::seconds(3));
	LockWorkStation(); // Windows API to lock screen
	isLocked = true;
}

void main() {
	VideoCapture video(0);
	CascadeClassifier facedetect;
	Mat img;
	if (!facedetect.load("haarcascade_frontalface_default.xml")) {
		cerr << "Could not load Haar Cascade file!" << endl;
		return;
	}

	
	
	
	while (true) {
		video.read(img);

		vector<Rect> faces;

		facedetect.detectMultiScale(img, faces, 1.3, 5);

		cout << faces.size() << endl;

		for (int i = 0; i < faces.size(); i++) {
			
			rectangle(img, faces[i], Scalar(0, 255, 0), 3);

	
			rectangle(img, Point(10, 10), Point(300, 60), Scalar(0, 0, 0), FILLED);

			putText(img, to_string(faces.size()) + " Face(s) Detected", Point(20, 45),
				FONT_HERSHEY_SIMPLEX, 0.8, Scalar(255, 255, 255), 2);


			if (faces.size() > 1) {
				lockScreen();
				break; 
			}


		}

		imshow("SilentGuardian++", img);

		if (waitKey(1) == 27) break;

	}

}

