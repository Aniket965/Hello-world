import React, {Component} from 'react';
import TaskListItem from './TaskListItem';

export default class TaskList extends Component{
    constructor(props){
        super(props);
        this.jumpModal = this.jumpModal.bind(this);
        console.log('TaskList::',props)
    }
    jumpModal(index){
        console.log('jumpModal',index);
        this.props.onClick(index);
    }
    render(){
        console.log('TaskList-',this.props.tareas)
        return(
            <ul>
                {
                    this.props.tareas.map((tarea) => <TaskListItem titulo={tarea.taskTitulo} state={tarea.taskstatus} key={tarea.taskId} id={tarea.taskId} colors={this.props.colors} onClick={this.jumpModal} nombres={this.props.nombres}/>)
                }
            </ul>
        )
    }
}