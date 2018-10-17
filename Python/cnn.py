from keras.preprocessing.image import ImageDataGenerator
from keras.models import Sequential
from keras.layers import Conv2D, MaxPooling2D
from keras.layers import Activation, Dropout, Flatten, Dense
from keras import backend as K
from keras.preprocessing import image
import numpy as np

# SET THE DIMENSIONS OF THE IMAGES BEING USED
img_width, img_height = 150,150

# SET THE TRAIN, TEST AND VALIDATION DIRECTORIES (PLACED ON DESKTOP)
train_data_dir = 'data/train'
test_data_dir = 'data/test'
validation_data_dir = 'data/validation'

# SET THE NUMBER OF SAMPLES FOR TRAINING AND VALIDATION
nb_train_samples = 1000
nb_validation_samples = 100

# SET THE NUMBER OF EPOCHS
epochs = 20

# SET THE BATCH SIZE
batch_size = 16

if K.image_data_format() == 'channels_first':
    input_shape = (3, img_width, img_height)
else:
    input_shape = (img_width, img_height, 3)

#CONVOLUTIONAL NEURAL NETWORK MODEL HERE
model = Sequential()
model.add(Conv2D(32, (3, 3), input_shape=input_shape))
model.add(Activation('relu'))
model.add(MaxPooling2D(pool_size=(2, 2)))

model.add(Conv2D(32, (3, 3)))
model.add(Activation('relu'))
model.add(MaxPooling2D(pool_size=(2, 2)))
model.add(Conv2D(64, (3, 3)))
model.add(Activation('relu'))
model.add(MaxPooling2D(pool_size=(2, 2)))
model.add(Flatten())
model.add(Dense(64))
model.add(Activation('relu'))
model.add(Dropout(0.5))
model.add(Dense(1))
model.add(Activation('sigmoid'))
model.compile(loss='binary_crossentropy',
              optimizer='rmsprop',
metrics=['accuracy'])

# THE FOLLOWING CODE WILL LOAD THE TRAINING AND VALIDATION DATA TO YOUR MODEL NAMED model
train_datagen = ImageDataGenerator(
    rescale=1. / 255,
    rotation_range=90,
    shear_range=0.2,
    zoom_range=0.2,
    horizontal_flip=True)

test_datagen = ImageDataGenerator(rescale=1. / 255)

train_generator = train_datagen.flow_from_directory(
    train_data_dir,
    target_size=(img_width, img_height),
    batch_size=batch_size,
    class_mode='binary')

validation_generator = test_datagen.flow_from_directory(
    validation_data_dir,
    target_size=(img_width, img_height),
    batch_size=batch_size,
    class_mode='binary')

model.fit_generator(
    train_generator,
    steps_per_epoch=nb_train_samples // batch_size,
    epochs=epochs,
    validation_data=validation_generator,
    validation_steps=nb_validation_samples // batch_size)

# DISPLAY THE CLASS NAME AND INDEX USED FOR TRAINING
print "Class : Index"
print train_generator.class_indices

# THE FOLLOWING CODE WILL FEED THE TEST DATA TO YOUR MODEL NAMED model
test_datagen = ImageDataGenerator(rescale=1. / 255)

validation_generator = test_datagen.flow_from_directory(
    test_data_dir,
    target_size=(img_width, img_height),
    batch_size=batch_size,
    class_mode='binary')

predict= model.predict_generator(
    validation_generator,
    nb_validation_samples // batch_size)

# DISPLAY THE PREDICTED CLASS FOR EACH SAMPLE
print predict

