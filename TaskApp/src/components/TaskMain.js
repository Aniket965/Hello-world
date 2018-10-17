import React, {Component} from 'react';
import styled from 'styled-components';
import TaskHeader from './TaskHeader';
import TaskList from './TaskList';
import fuzzysearch from 'fuzzysearch'
import { debounce } from 'lodash'

export default class TaskMain extends Component{
    constructor(props){
        super(props);
        /* this.state = {
            tasks:props.tasks,
            current:props.current,
            title:props.titulo,
            colors:props.colors,
        } */
        this.paseModal = this.paseModal.bind(this)
        this.filterTasks = this.filterTasks.bind(this)
        console.log('tareas: ',props.tasks);
        console.log('currentMain: ',props);
        
    }
    paseModal(id){
        this.props.onClick(id);
        console.log('paseModal',id)
    }
    filterTasks(filter){
        const filtrado = this.props.tasks.filter(tarea => {
            return (
              fuzzysearch(filter, tarea.taskTitulo)
            )
          })
      
        this.props.onFilter(filtrado)
        console.log('TaskMain',filter);
    }
    render(){
        return(
            <Main>
                <TaskHeader titleTask={this.props.titulo} onChange={this.filterTasks}/>
                <TaskList tareas={this.props.tasks} colors={this.props.colors} onClick={this.paseModal} nombres={this.props.nombres}/>
            </Main>
        )
    }
}

const Main = styled.div`
  overflow: hidden;
  display: inline-block;
  height: 98vh;
  width:78%;
`