import React from 'react';
import { Text, TouchableOpacity } from 'react-native';

const ButtomCustom = ({
  children, onPress, styleButtom, styleText, textButtom, ...rest
}) => (
    <TouchableOpacity
      style={styleButtom}
      onPress={() => {
        onPress();
      }}>
      <Text style={styleText}>{textButtom}</Text>
    </TouchableOpacity>
  );

export default ButtomCustom;
