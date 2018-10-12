import React, {Component} from 'react';

export default class Display extends Component {
  constructor(props){
    super(props);
    this.state = {label: "", intro: true , typeSpeed: 200}
    this.parent = props.parent;
  }
 
  activateW = () => document.getElementById('label').focus(); 

  clearTimers = () => {
    clearTimeout();
    clearInterval();
  }
  typeAnim = () => {
    const word = "Hello World...".split('');
    const speedVariant = [1000, 800, 600, 500,400, 300, 200, 100];
    setTimeout(() => {
      setInterval(() => {
        if(word.length){
          return this.setState({label: this.state.label += word.shift(), typeSpeed: speedVariant[Math.floor(Math.random() * Math.floor(speedVariant.length - 1))]});
        } 
        this.clearTimers();
        this.setState({intro: false});
      }, this.state.typeSpeed);
    }, 5000);
  }
  updateLabel = (input)=> {
    if(input.length <= 15){
      this.parent.setState({command: input}); 
      this.setState({label: input});
    } 
  };

  componentDidMount(){
    this.clearTimers();
    this.typeAnim();
  }
  componentWillUnmount(){
    this.clearTimers();
  } 
  render(){
    return (
      <div className="Display" onBlur={() => this.activateW()}>
        <div style={{position: 'fixed', width: '100%', height: '100%', overflow: 'hidden', zIndex: -1, display: 'flex', justifyContent: 'center', alignItems: 'center'}}>
          <img src={'images/background.jpg'} style={window.innerHeight > window.innerWidth ? {height: '100%'} : {width: '100%', left: '50rem'}} height="100%"/>
        </div>
        {/*DISPLAY*/}
        <label >
          <p >{this.state.label}</p> 
          <span className="cursor"><i className="fas fa-code" style={!this.state.intro ? {color:'red', transition: 'color 0.1s'} : null}/></span>
        </label>
        {<img src={'images/smoke.gif'} style={{position: 'absolute', bottom: '-70%', opacity: !this.state.intro ? 0.12 : 0, transition: 'opacity 5s'}} width="100%" />}

        {
          !this.state.intro && 
            <input id="label" style={{opacity:0, height: 0}} 
              onChange={(e) => {
                !this.state.intro && this.updateLabel(e.target.value);
              }} 
              value={this.state.label} autoFocus={true} 
            />
        }
      </div>
    )
  }
}