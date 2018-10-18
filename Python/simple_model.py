from tensorflow import keras


inputs = keras.layers.Input(None, 100)
outputs = keras.layers.Dense(10)(inputs)
model = keras.models.Model(inputs, outputs)
model.compile(optimizer='adam', loss='categorical_crossentropy')
print(model.summary())
