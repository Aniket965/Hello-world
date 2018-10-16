import React, { Component } from 'react';
import {
  View, Text, StyleSheet, TextInput,
} from 'react-native';
import { connect } from 'react-redux';
import { increment, decrement, setNumber, reset } from './home.actions';
import ButtomCustom from '../../components/buttom-custom';

const mapStateToProps = state => ({
  number: state.home.number,
});

const mapDispatchToProps = dispatch => ({
  increment: () => dispatch(increment()),
  decrement: () => dispatch(decrement()),
  setNumber: (number) => dispatch(setNumber(number)),
  reset: () => dispatch(reset()),
});

export class HomeComponent extends Component {

  constructor(props) {
    super(props);
    this.state = {
      number: 0,
      inputNumber: '0',
    };
  }

  render() {
    return (
      <View style={styles.container}>
        <View style={styles.homeForm}>
          <Text style={styles.homeNumber}>Number: {this.props.number}</Text>
          <View style={styles.viewButtom}>
            <ButtomCustom
              styleButtom={styles.buttonHome}
              styleText={styles.textButtom}
              textButtom="Decrement"
              onPress={() => this.props.decrement()}
            />
            <ButtomCustom
              styleButtom={styles.buttonHome}
              styleText={styles.textButtom}
              textButtom="Increment"
              onPress={() => this.props.increment()}
            />
          </View>
          <TextInput
            style={styles.textInput}
            value={this.state.inputNumber}
            onChangeText={(value) => {
              this.setState({ inputNumber: value });
            }}
            keyboardType={'decimal-pad'}
            placeholder='Enter number'
          />
           <ButtomCustom
              styleButtom={styles.buttonHome}
              styleText={styles.textButtom}
              textButtom="Set Number"
              onPress={() => this.props.setNumber(this.state.inputNumber)}
            />
           <ButtomCustom
              styleButtom={styles.buttonHome}
              styleText={styles.textButtom}
              textButtom="Reset Number"
              onPress={() => {
                this.props.reset();
                this.setState({ inputNumber: '0' });
              }}
            />
        </View>
      </View>
    );
  }
}

export default connect(mapStateToProps, mapDispatchToProps)(HomeComponent);

const styles = StyleSheet.create({
  container: {
    flex: 1,
  },
  homeForm: {
    width: '100%',
    height: '100%',
    justifyContent: 'center',
    alignItems: 'center',
  },
  homeNumber: {
    marginBottom: 35,
    fontSize: 20,
    fontWeight: 'bold',
    color: '#3b5998',
  },
  textButtom: {
    marginBottom: 0,
    fontSize: 18,
    fontWeight: 'bold',
    color: '#fff',
  },
  textInput: {
    width: '80%',
    height: 50,
    borderColor: '#3b5998',
    borderWidth: 1,
    borderRadius: 10,
    padding: '3%',
  },
  viewButtom: {
    flexDirection: "row",
    justifyContent: "center"
  },
  buttonHome: {
    height: 50,
    width: 150,
    backgroundColor: '#3b5998',
    justifyContent: 'center',
    alignItems: 'center',
    borderRadius: 10,
    margin: 10,
  },
});
