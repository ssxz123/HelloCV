#include<iostream>
#include<string>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

const double pi = 3.1415926;
int threshold1 = 25,threshold2 = 75;

vector<vector<int>>colors = { {152,179,58,255,150,255} , {55,90,100,255,133,255} };

void Processing(Mat& img,Mat& imgCanny){
    Mat imgBlur,imgGray;
    GaussianBlur(img,imgBlur,Size(7,7),7,0);
    Canny(imgBlur,imgCanny,threshold1,threshold2);
    Mat kernel = getStructuringElement(MORPH_RECT,Size(7,7));
    dilate(imgCanny,imgCanny,kernel);
}

bool isCircle(vector<Point> contour){
    double c = arcLength(contour,true),s = contourArea(contour);
    if ((s * 4 * pi / (c * c)) > 0.82){
        return true;
    }
    else return false;
}

void getContours(Mat& mask,Mat& img,string color){
    vector<vector<Point>>contours;
    vector<Vec4i>hierarchy;
    findContours(mask,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
    for(int i=0;i<contours.size();i++){
        Rect boundRect;
        int area = contourArea(contours[i]);

        if(area > 1000 && isCircle(contours[i])){
            // drawContours(img,contours,i,Scalar(255,0,255),2);
            boundRect = boundingRect(contours[i]);
            rectangle(img,boundRect,Scalar(0,255,0),2);
            putText(img,color,Point(0,50),FONT_HERSHEY_COMPLEX,2,Scalar(0,255,0),2);
        
        }
    }
    
}
int main(){
    string path = "TrafficLight.mp4";
    VideoCapture cap(path);

    double fps = cap.get(CAP_PROP_FPS);
    Size frameSize(cap.get(CAP_PROP_FRAME_WIDTH) * 0.5,cap.get(CAP_PROP_FRAME_HEIGHT) * 0.5);
    VideoWriter writer("result.avi",VideoWriter::fourcc('M','J','P','G'),30.0,frameSize);
    while(1){
        Mat img_origin,img,imgHSV;
        cap.read(img);
        
        if(img.empty()){
            break;
        }

        resize(img,img,Size(),0.5,0.5);
        img_origin = img;
        
        cvtColor(img,imgHSV,COLOR_BGR2HSV);
        Scalar lower_red(colors[0][0],colors[0][2],colors[0][4]);
        Scalar upper_red(colors[0][1],colors[0][3],colors[0][5]);
        Scalar lower_green(colors[1][0],colors[1][2],colors[1][4]);
        Scalar upper_green(colors[1][1],colors[1][3],colors[1][5]);         
        Mat mask_red,mask_green,imgCanny_red,imgCanny_green;
        inRange(imgHSV,lower_red,upper_red,mask_red);
        inRange(imgHSV,lower_green,upper_green,mask_green);
        
        Processing(mask_red,imgCanny_red);
        Processing(mask_green,imgCanny_green);

        // img = Processing(img);

        getContours(imgCanny_red,img,"Red");
        getContours(imgCanny_green,img,"Green");
        
        imshow("Image,img",img);

        writer.write(img);

        if(waitKey(30) == 27){
            break;
        }
        
    }
    writer.release();

    return 0;
}
