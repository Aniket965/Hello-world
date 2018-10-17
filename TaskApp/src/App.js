import React, { Component } from 'react'
import styles from './App.css'
import '../node_modules/bootstrap/dist/css/bootstrap.min.css'
import TaskManager from './containers/TaskManager'
import styled from 'styled-components'

export default class App extends Component {
  render() {
    return (
      <Wrapper>
        <TaskManager/>
      </Wrapper>
    )
  }
}

const Wrapper = styled.div`
  background-color: #1d0d3e;
  height: 100vh;
`