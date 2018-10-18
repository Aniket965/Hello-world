import React, { Component } from 'react';
import {
  Display,
  Splash,
  GFX_Matrix
} from './components';

import './App.css';

class App extends Component {
  constructor(){
    super();
    this.state = {command: null, anim: {name:'_MATRIX_', data: new GFX_Matrix()}}
  }
  ent_check = (e) => {
    if(e.key !== 'Enter') return;
    switch(String(this.state.command).toUpperCase()){
      case 'HACK':
        return this.state.anim.data.start();
      case 'REBOOT':
        return window.location.reload();
      case 'LINKEDIN':
        return window.open('https://linkedin.com/in/brandon-fizer');
      case 'EMAIL':
        return window.open('mailto:brandon.m.fizer@gmail.com');
      case 'CALL':
        return window.open('tel:+19107581607');
      case 'GITHUB':
        return window.open('https://github.com/track7dev');
      case 'PORTFOLIO':
        return window.open('http://BrandonFizer.com');
      
      default:
      return;
    }
  }

  render() {
    return (
      <main className="App" onKeyUp={(e) => this.ent_check(e)}>
  
        {
          //OVERVIEWS
          //this.state.anim && 
            <section id="App-Overviews" className="App-Overviews">
              {
                this.state.anim ?
                  this.state.anim.name === "_MATRIX_" ?
                    this.state.anim.data.init() //call matrix anim
                    :
                    null //call next anim
                  : <p style={{color: 'white'}}>NOTHING</p>
                              
              }
            </section>
        }

        <header className="App-header">
          <img src={'images/hacktoberfest.png'} width="50%"/>
        </header>
        
        <section className="App-Display">
          <Splash />
          <Display parent={this}/>
        </section> 

      </main>
    );
  }
}

export default App;
