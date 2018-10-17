// Importing react modules

import React, { Component } from "react";
import brownPumpkin from "./images/pumpkin-brown.png";
import orangePumpkin from "./images/pumpkin-orange.png";
import "./App.css";

class App extends Component {
  state = {
    isDark: false
  };

  toggleDark = () => {
    this.setState(previousState => ({ isDark: !previousState.isDark }));
  };

  render() {
    const { isDark } = this.state
    return (
      <div
        className="App"
        style={{ backgroundColor: `${isDark ? "black" : "orange"}` }}
      >
        <header className="App-header">
          <p style={{ color: `${isDark ? "white" : "black"}` }} className="rainbow">
            Hello world !<br /> Happy Halloween!</p>
          <img
            className="logo"
            src={isDark ? orangePumpkin : brownPumpkin}
            alt=""
          />
        </header>

        <footer className="footer">
          <button className="button" onClick={this.toggleDark}>
            Turn {isDark ? "on" : "off"} the lights
          </button>
          created by <a href="https://github.com/CQW-Code"> CQW-Code</a>
        </footer>
      </div>
    );
  }
}

export default App;
