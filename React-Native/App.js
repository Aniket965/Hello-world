import React, { Component } from 'react';
import { Platform, StyleSheet, Text, View, Alert } from 'react-native';

export default class App extends Component<Props> {
  render() {
    return (
      Alert.alert('I hate java.');
      <View style={styles.container}>
        <Text>Hello World</Text>
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#F5FCFF',
  },
});
