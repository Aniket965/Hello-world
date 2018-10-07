// Importing react modules

import React, { Component } from "react";
import brownPumpkin from "./images/pumpkin-brown.png";
import orangePumpkin from "./images/pumpkin-orange.png";
import "./App.css";

class App extends Component {
  constructor(props) {
    super(props);
    this.state = {
      isDark: false
    };
  }

  toggleDark = () => {
    this.setState(previousState => {
      return { isDark: !previousState.isDark };
    });
  };
  render() {
    return (
      <div
        className="App"
        style={{ backgroundColor: `${this.state.isDark ? "black" : "orange"}` }}
      >
        <header className="App-header">
          <p style={{ color: `${this.state.isDark ? "white" : "black"}` }}>
            Hello World! Happy Halloween!
          </p>
          <img
            className="logo"
            src={this.state.isDark ? orangePumpkin : brownPumpkin}
            alt=""
          />
        </header>

        <footer className="footer">
          <button className="button" onClick={this.toggleDark}>
            Turn {this.state.isDark ? "on" : "off"} the lights
          </button>
          created by <a href="https://github.com/CQW-Code"> CQW-Code</a>
        </footer>
      </div>
    );
  }
}

export default App;
