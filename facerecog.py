import os
import face_recognition

#making the list of all the available images
images = os.listdir('images')

#load your image
image_to_be_matched = face_recognition.load_image_file('my_image.jpg')

#Encoding the loaded image into a feature vector
image_to_be_matched_encoded = face_recognition.face_encodings(image_to_be_matched)[0]

for image in images:
	current_image = face_recognition.load_image_file("images/" + image)
	current_image_encoded = face_recognition.face_encodings(current_image)[0]

	#matching the image encoded with the proposed image
	result = face_recognition.compare_faces([image_to_be_matched_encoded],current_image_encoded)

	#checking if it was a match
	if result[0] == True:
		print ("Matched: " + image)
	else:
		print ("Not Matched:" + image)


