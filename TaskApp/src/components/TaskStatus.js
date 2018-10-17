import React, {Component} from 'react'
import styled, { css } from 'styled-components'
import ButtonStatus from "./ButtonStatusTask"
import '../App.css'

export default class TaskStatus extends Component{
    constructor(props){
        super(props);
        this.state = {
            colors:props.colors,
            nameStatus:props.names,
            current:props.current
        }
        this.setStatus = this.setStatus.bind(this);
        this.addTaskEvent = this.addTaskEvent.bind(this);
    }
    setStatus(idStat){
        console.log('SetStatus: ',idStat);
        this.setState({ current: idStat })
        this.props.handleClick(idStat)
    }
    addTaskEvent = e => {
        e.preventDefault();
        console.log(this.newTask.value,Date.now());
        const nTask ={
            "taskId":Date.now(),
            "taskTitulo":this.newTask.value,
            "taskstatus":0
        }
        this.props.onAddTask(nTask);
        this.newTask.value = '';
    }
    render(){
        return(
            <Sidebar>
                <LOGO>LOGO</LOGO>
                <form onSubmit={this.addTaskEvent}>
                    <input type="text" placeholder="Add new task" ref={node => this.newTask = node} style={inputAdd}/>
                    <Button type="submit">Add Task</Button>
                </form>
                <ViewAll onClick={this.props.toggleAllTask}>[ View all tasks ]</ViewAll>
                <WrapperButtons>
                    {
                        this.state.colors.map((color,index)=>(
                            <ButtonStatus handleClick={this.setStatus} idStatus={index} color={this.state.colors[index]} texto={this.state.nameStatus[index]} key={index}/>
                        ))
                    }
                </WrapperButtons>
            </Sidebar>
        )
    }
}
const inputAdd = {
    border: '1px solid #a9a9ef',
    margin: '15px auto',
    padding: '.375rem .75rem',
    fontSize: '1rem',
    lineHeight: 1.5,
    color: '#495057',
    backgroundColor: '#fff',
    backgroundClip: 'padding-box',
    border: '1px solid #a9a9ef',
    borderRadius: '.25rem',
    transition: 'border-color .15s ease-in-out,box-shadow .15s ease-in-out',
}

const LOGO = styled.div`
    display: block;
    width: 50px;
    height: 50px;
    border-radius: 7px;
    background: #d20f51;
    margin: 50px auto;
    font-size: 11px;
    line-height: 50px;
    color:#fff;
`;
const ViewAll = styled.a`
    display:block;
    cursor:pointer;
    color:#fff!important;
    margin: 30px 0 0;
`

const Sidebar = styled.div`
  background-color: rgba(0,0,0,.2);
  overflow: hidden;
  display: inline-block;
  height: 99vh;
  width: 20%;
  text-align: center;
` 

const Button = styled.button`
    display: block;
    font-weight: 400;
    text-align: center;
    white-space: nowrap;
    margin: 0 auto;
    color: #fff;
    background-color: #007bff;
    border-color: #007bff;
    border: 1px solid transparent;
    padding: .375rem .75rem;
    font-size: 1rem;
    line-height: 1.5;
    border-radius: .25rem;
`;

const WrapperButtons = styled.div`
    margin: 0;
`;