import React from 'react';
import {StyleSheet, TouchableNativeFeedback, View, Text} from 'react-native'


export default class ButtonComponent extends React.PureComponent {
    constructor() {
        super();
        this.state = {

        };
    }


    render() {

        return (
            <TouchableNativeFeedback onPress={this.props.onPress}>

                <View style={[styles.container, this.props.style]}>

                    <Text style={styles.text}>

                        {

                            this.props.text

                        }


                    </Text>

                </View>

            </TouchableNativeFeedback>
        );

    }

}


const styles = StyleSheet.create({

    container: {
        flex: 1,
        alignItems: 'center',
        borderColor : '#c7c7c7',
        borderWidth: 0.5,
        justifyContent: 'center'
    },

    text:{

        fontSize : 30,
        fontWeight: 'bold',
        color : '#4a4a4a'

    }


});