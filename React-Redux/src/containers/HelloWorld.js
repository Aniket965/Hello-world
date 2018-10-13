import React, { Component } from "react";
import { connect } from "react-redux";

class HelloWorld extends Component {
  constructor(props) {
    super(props);

    this.state = {};
  }

  render() {
    const { text } = this.props;
    return <div>{text}</div>;
  }
}

const mapStateToProps = state => {
  const { text } = state.HelloWorld;

  return {
    text
  };
};

const mapDispatchToProps = dispatch => {};

export default connect(
  mapStateToProps,
  mapDispatchToProps
)(HelloWorld);
