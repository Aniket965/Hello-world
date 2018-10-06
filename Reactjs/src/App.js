# Importing react modules

import React, { Component } from "react";
import ducky from "././images/HalloweenDuck.jpg";
import "./App.css";

class App extends Component {
  render() {
    return (
      <div className="App">
        <header className="App-header">
          <img src={ducky} className="pumpkin" alt="pumpkin duck" />
          <p>Hello World! Quack!</p>
        </header>

        <footer>
          created by <a href="https://github.com/CQW-Code"> CQW-Code</a>
        </footer>
      </div>
    );
  }
}

export default App;
