import React, {Component} from 'react';
import {Platform, StyleSheet, Text, View} from 'react-native';
 export default class App {
  render() {
    return (
      <View style={styles.container}>
        <Text>World</Text>
      </View>
    );
  }
}
 const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#000',
  }
});
