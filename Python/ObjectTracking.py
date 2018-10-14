# Libraries
import imutils
import cv2
import argparse
from imutils.video import VideoStream, FPS
 
# construct the argument parse and parse the arguments
ap = argparse.ArgumentParser()
ap.add_argument("-t", "--tracker", required=False, help='''Name of the Tracker. List of Available Trackers in OpenCV: "csrt", "kcf", "boosting", "mil", "tld", "medianflow", "mosse"''')
args = vars(ap.parse_args())

# Dictionary of trackers available in OpenCV
object_trackers = {
		'csrt': cv2.TrackerCSRT_create,
		'kcf': cv2.TrackerKCF_create,
		'boosting': cv2.TrackerBoosting_create,
		'mil': cv2.TrackerMIL_create,
		'tld': cv2.TrackerTLD_create,
		'medianflow': cv2.TrackerMedianFlow_create,
		'mosse': cv2.TrackerMOSSE_create,
	}

def trackers(name):
	assert name.lower() in object_trackers.keys(), f"No tracker with name {name}"

	return object_trackers[name.lower()]()

# Initialize Variables

## name & path of the video to be used
video_path = "drone.mp4"
## Object of tracker to be used.
'''
	List of Available Trackers in OpenCV
		1. csrt
		2. kcf
		3. boosting
		4. mil
		5. tld
		6. medianflow
		7. mosse
'''
# Using CSRT Tracker by Default.
tracker_name = "csrt"

if args['tracker'] is not None:
	tracker_name = args['tracker']

tracker = trackers(tracker_name)
## Count number of Frames per Second
fps = None
## Keep track of Coordinates of Bounding Box around the object to track
init_BB = None

# Fetch video from the directory and
# store it vs variable
vs = cv2.VideoCapture(video_path)

# for each frame in the video
# loop over till end of the video is reached.
while True:
	# Read the current frame from the video
	frame = vs.read()[1]

	# check whether we have reached the end of the stream (video)
	# if frame is None i.e video ended
	if frame is None:
		# break the loop and come out of the loop
		# as we have reached the end of the video
		break

	# else

	# resize the frame to make processing faster
	# Fetch Height & Width of the frame after resizing
	frame = imutils.resize(frame, width = 600)
	(Height, Width) = frame.shape[:2]

	# check whether we are tracking an object currently or not

	# if we are tracking an object currently
	if init_BB is not None:
		# get the new bounding box coordinate of the object
		## update method return a success boolean value
		## if success is true then value of the bounding box
		(success, box) = tracker.update(frame)

		# if tracking was a success i.e success = true
		if success:
			# get the coordinates of the bounding box for the object
			(x, y, w, h) = [int(v) for v in box]
			# draw a rectangle around the object
			cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)
		# else 
		else:
			pass

		# update the fps counter
		fps.update()
		fps.stop()

		# Information to display with each frame
		# Tracker being used along with the Frame per Second
		info = [
			("Tracker Used: ", tracker_name),
			("FPS: ", "{:.2f}".format(fps.fps()))
		]

		# loop over the information list and display it on each frame
		for (i, (k, v)) in enumerate(info):
			text = f"{k}: {v}"
			# write the information on the frame in blue color at the bottom left corner
			cv2.putText(frame, text, (10, Height - ((i * 20) + 20)), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 0), 3)

	# else
	## we are not tracking any object currenty

	# display the frame
	cv2.imshow("Video Frame", frame)
	# wait for key to be pressed by user
	key = cv2.waitKey(1) & 0xFF

	# if 's' is pressed, pause the video
	## select a bounding box around an object to track in the video
	if key == ord("s"):
		# Select (or draw) a bounding box around the object to track in the video
		init_BB = cv2.selectROI("Frame", frame, fromCenter = False, showCrosshair = True)

		# execute the tracker on the selected object and start the fps counter.
		tracker.init(frame, init_BB)
		fps = FPS().start()

	# if 'q' is pressed, stop the video and terminate
	elif key == ord('q'):
		break

# stop capturing video
vs.release()
# destory all the windows and terminate
cv2.destroyAllWindows()
