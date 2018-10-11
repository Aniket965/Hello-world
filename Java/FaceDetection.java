/*
 *
 * PROGRAM FOR DETECTING FACES FROM GIVEN IMAGE USING OPENCV 
 *
 *
 */


import org.opencv.core.Core;
import java.lang.String;
import org.opencv.core.Mat;
import org.opencv.core.MatOfRect;
import org.opencv.core.Point;
import org.opencv.core.Rect;
import org.opencv.core.Scalar;
import org.opencv.imgcodecs.Imgcodecs;
import org.opencv.imgproc.Imgproc;
import org.opencv.objdetect.CascadeClassifier;

class FaceDetector
{
    public static void main(String[] args)
    {

        // For proper execution of native libraries
        // Core.NATIVE_LIBRARY_NAME must be loaded before
        // calling any of the opencv methods
        System.loadLibrary("opencv");

        // Face detector creation by loading source cascade xml file
        // using CascadeClassifier.
        // the file can be downloade from
        // https://github.com/opencv/opencv/blob/master/data/haarcascades/
        // haarcascade_frontalface_alt.xml
        // and must be placed in same directory of the source java file
        CascadeClassifier faceDetector = new CascadeClassifier();
        faceDetector.load("/home/hawkeye/haarcascade_frontalface_alt.xml");

        // Input image
        Mat image = Imgcodecs.imread("/home/hawkeye/1.jpg");

        // Detecting faces
        MatOfRect faceDetections = new MatOfRect();
        faceDetector.detectMultiScale(image, faceDetections);

        // Creating a rectangular box showing faces detected
        for (Rect rect : faceDetections.toArray())
        {
            Imgproc.rectangle(image, new Point(rect.x, rect.y),
             new Point(rect.x + rect.width, rect.y + rect.height),
                                           new Scalar(0, 255, 0));
        }

        // Saving the output image
        String filename = "face1.png";
        Imgcodecs.imwrite("/home/hawkeye/Pictures/"+filename, image);
    }
}
