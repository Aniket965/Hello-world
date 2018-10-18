import React, { Component } from 'react';
import { StyleSheet, View, Text } from 'react-native';
import ButtonComponent from '../component/ButtonComponent'

export default class MainScreen extends Component {
    constructor(props) {
        super(props);
        this.state = {

            result : '',
            symbol : '',
            firstNumber : '',
            secondNumber : ''

        };
    }

    addSymbol = (symbol)=>{

      if(this.state.firstNumber!==''){
          this.setState({
              symbol : symbol,
          })
      }

    };

    addNumber = (number) =>{

        if(this.state.symbol===''){
            this.setState((prevState, props)=>(
                {
                    firstNumber : prevState.firstNumber+""+number,
                    result : ''
                }
            ))
        }else{

            this.setState((prevState, props)=>(
                {
                    secondNumber : prevState.secondNumber+""+number,
                    result : ''
                }
            ))

        }

    };

    countResult = () =>{

        if(this.state.firstNumber!=='' && this.state.secondNumber!=='' && this.state.symbol!==''){
            if(this.state.symbol==='+'){

                this.setState((prevState, props)=>(
                    {
                        result : parseInt(prevState.firstNumber) + parseInt(prevState.secondNumber),
                    }
                ))

            }else if (this.state.symbol==='-'){
                this.setState((prevState, props)=>(
                    {
                        result : parseInt(prevState.firstNumber) - parseInt(prevState.secondNumber),
                    }
                ))
            }else if (this.state.symbol==='x'){
                this.setState((prevState, props)=>(
                    {
                        result : parseInt(prevState.firstNumber) * parseInt(prevState.secondNumber),
                    }
                ))
            }else if (this.state.symbol==='/'){
                this.setState((prevState, props)=>(
                    {
                        result : parseInt(prevState.firstNumber) / parseInt(prevState.secondNumber),
                    }
                ))
            }

            this.resetState();
        }

    };

    resetState = ()=>{
        this.setState((prevState, props)=>(
            {
                firstNumber : '',
                secondNumber : '',
                symbol : ''
            }
        ))
    };

    render() {
        console.log(this.state.firstNumber);
        console.log(this.state.symbol);
        console.log(this.state.secondNumber);
        console.log("result = "+this.state.result);
        return (
            <View style={styles.container}>


                <View style={styles.resultContainer}>

                    <Text style={styles.resultText}>{ this.state.result!=='' ? this.state.result : this.state.firstNumber+" "+this.state.symbol +" "+this.state.secondNumber}</Text>

                </View>

                <View style={styles.buttonContainer}>

                    <View style={styles.rowContainer}>

                        <ButtonComponent text="1" onPress={()=>this.addNumber(1)} style={styles.columnContainer}/>
                        <ButtonComponent text="2" onPress={()=>this.addNumber(2)} style={styles.columnContainer}/>
                        <ButtonComponent text="3" onPress={()=>this.addNumber(3)} style={styles.columnContainer}/>
                        <ButtonComponent text="+" onPress={()=>this.addSymbol("+")} style={styles.columnContainer}/>

                    </View>
                    <View style={styles.rowContainer}>

                        <ButtonComponent text="4" onPress={()=>this.addNumber(4)} style={styles.columnContainer}/>
                        <ButtonComponent text="5" onPress={()=>this.addNumber(5)} style={styles.columnContainer}/>
                        <ButtonComponent text="6" onPress={()=>this.addNumber(6)} style={styles.columnContainer}/>
                        <ButtonComponent text="-" onPress={()=>this.addSymbol("-")} style={styles.columnContainer}/>

                    </View>
                    <View style={styles.rowContainer}>

                        <ButtonComponent text="7" onPress={()=>this.addNumber(7)} style={styles.columnContainer}/>
                        <ButtonComponent text="8" onPress={()=>this.addNumber(8)} style={styles.columnContainer}/>
                        <ButtonComponent text="9" onPress={()=>this.addNumber(9)} style={styles.columnContainer}/>
                        <ButtonComponent text="x" onPress={()=>this.addSymbol("x")} style={styles.columnContainer}/>

                    </View>
                    <View style={styles.rowContainer}>

                        <ButtonComponent text="0" onPress={()=>this.addNumber(0)} style={styles.columnContainer}/>
                        <ButtonComponent text="=" onPress={()=>this.countResult()} style={[styles.columnContainer, {flex:2}]}/>
                        <ButtonComponent text="/" onPress={()=>this.addSymbol("/")} style={styles.columnContainer}/>

                    </View>

                </View>

            </View>

            // <ButtonComponent text="1" onPress={()=>alert("kliked")}/>
        );
    }
}

const styles = StyleSheet.create({

    container : {
        flex : 1
    },

    buttonContainer : {
        flex: 2,
    },

    resultContainer : {
        flex: 1,
        justifyContent: 'flex-end',
        alignItems: 'flex-end',
        padding : 16,
    },

    resultText:{
        fontSize : 40
    },

    rowContainer : {
        flex : 1,
        flexDirection: 'row'
    },


    columnContainer : {
        flex : 1,
    }

});
