// g++ -o tryen tryen.cpp `pkg-config opencv --cflags --libs`

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

// int DELAY_CAPTION = 1500;
// int DELAY_BLUR = 100;
// int MAX_KERNEL_LENGTH = 31;

// Mat src; Mat dst;

// int display_caption( char* caption );
// int display_dst( int delay );



Mat medianFilter(Mat src) {
    vector <int> tmp; 
    int c = 255;
    for (int i = 1; i < src.rows - 1; i++) {
        for (int j = 1; j < src.cols - 1; j++) {
            //src.at<uchar>(i, j) = c;
            tmp.push_back(src.at<uchar>(i, j));
            tmp.push_back(src.at<uchar>(i - 1, j));
            tmp.push_back(src.at<uchar>(i - 1, j + 1));
            tmp.push_back(src.at<uchar>(i, j + 1));
            tmp.push_back(src.at<uchar>(i + 1, j + 1));
            tmp.push_back(src.at<uchar>(i + 1, j));
            tmp.push_back(src.at<uchar>(i + 1, j - 1));
            tmp.push_back(src.at<uchar>(i, j - 1));
            tmp.push_back(src.at<uchar>(i - 1, j - 1));
            sort(tmp.begin(), tmp.end());
            int sum = 0;
            for (int ii = 0; ii < tmp.size(); ii++) {
                sum += tmp[ii];
            }
            src.at<uchar>(j, i) = sum / 9;
            tmp.clear();
        }
    }
    // for (int i = 0; i < src.rows; i++) {
    //     for (int j = 0; j < src.cols; j++) {
    //         // cout << src.at<uchar>(j, i) << " ";
    //         // cout << src.at<uchar>(j, i - 1) << " ";
    //         // cout << src.at<uchar>(j + 1, i - 1) << " ";
    //         // cout << src.at<uchar>(j + 1, i) << " ";
    //         // cout << src.at<uchar>(j + 1, i + 1) << " ";
    //         // cout << src.at<uchar>(j, i + 1) << " ";
    //         // cout << src.at<uchar>(j - 1, i + 1) << " ";
    //         // cout << src.at<uchar>(j - 1, i) << " ";
    //         // cout << src.at<uchar>(j - 1, i - 1) << " ";
    //         src.at<uchar>(j, i) = 255;
    //         // if (i == 0) {
    //         //     if (j == 0) {
                    
    //         //     } else if (j == src.rows - 1) {

    //         //     } else {

    //         //     }
    //         // } else if (j == 0) {

    //         // } else {

    //         // }
    //     }
    // }
    return src;
}

int main() {
    Mat img;
    img = imread("lena-noisycopy.png");
    
    Mat resMedianFilter;
    resMedianFilter = medianFilter(img);

    Mat libMB;

    //cout << typeid(img.at<uchar>(10, 10)).name();
    medianBlur(img, libMB, 9);
    
    namedWindow("image");
    imshow("image", resMedianFilter);

    namedWindow("image lib");
    imshow("image lib", libMB);

    namedWindow("image asli");
    imshow("image asli", img);

    waitKey();
}


//source : https://diffractionlimited.com/help/maximdl/Low-Pass_Filtering.htm