import React, {Component} from 'react'
import TaskStatus from '../components/TaskStatus'
import TaskMain from '../components/TaskMain'
import TaskDetail from '../components/TaskDetail'
import fuzzysearch from 'fuzzysearch'
import { debounce } from 'lodash'

export default class TaskManager extends Component{
    constructor(){
        super();
        this.state = {
            tareas:[
                { "taskId":1, "taskTitulo":"Tarea demo 1", "taskstatus":0 },
                { "taskId":2, "taskTitulo":"Tarea demo 2", "taskstatus":1 },
                { "taskId":3, "taskTitulo":"Tarea demo 3", "taskstatus":0 },
                { "taskId":4, "taskTitulo":"Tarea demo 4", "taskstatus":2 },
                { "taskId":5, "taskTitulo":"Tarea demo 5", "taskstatus":0 },
                { "taskId":6, "taskTitulo":"Tarea demo 6", "taskstatus":1 },
                { "taskId":7, "taskTitulo":"Tarea demo 7", "taskstatus":2 }
            ],
            currentTasks:0,
            colors:['#03a9f4','#ffc107','#3dd843'],
            namesStatus: ['To Do','In Progress','Done!'],
            viewAll:'on',
            filterTasks:[],
            idForModal:0,
            viewModal:'off',
            taskDetail:{}
        }
        this.setCurrentState = this.setCurrentState.bind(this);
        this.openModalOf = this.openModalOf.bind(this);
        this.closeModal = this.closeModal.bind(this);
        this.getTaskForDetail = this.getTaskForDetail.bind(this);
        this.viewAllTasks = this.viewAllTasks.bind(this);
        this.addTask = this.addTask.bind(this);
        this.filterTasksFunc = this.filterTasksFunc.bind(this);
    }
    setCurrentState(idCurrent){
        var filtrados = [];
        this.state.tareas.map((tarea,index) => {
            console.log('map tareas',tarea.taskstatus)
            if(tarea.taskstatus===idCurrent){filtrados.push(tarea)} 
        })
        setTimeout(()=>{
            this.setState({ 
                currentTasks: idCurrent,
                filterTasks: filtrados,
                viewAll:'off'
            });
            console.log('filterTasks',this.state.filterTasks);
        },100)
        
    }
    getTaskForDetail(idmod){
        let tarea=[]
        console.log("length tareas ",this.state.tareas.length)
        for(var i=0;i<this.state.tareas.length;i++){
            if(idmod==this.state.tareas[i].taskId){
                console.log('getTaskForDetail',this.state.tareas[i])
                tarea = this.state.tareas[i]
            }
        }
        return tarea;
    }
    openModalOf(idmod){
        this.setState({
            idForModal:idmod,
            viewModal:'on',
            taskDetail:this.getTaskForDetail(idmod)
        })
        console.log('openModalOf',idmod);
    }
    viewAllTasks(){
        this.setState({
            viewAll:'on'
        })
    }
    closeModal(){
        this.setState({
            viewModal:'off'
        })
    }
    addTask(objTask){
        console.log('statusAddTaskkk ',objTask)
        this.setState({
            tareas: [...this.state.tareas, objTask],
            viewAll:'on'
        })
        console.log('status task update... ',this.state.tareas)
    }
    filterTasksFunc(filterTasks){
        this.setState({
            filterTasks,
        })
        console.log('TaskManager',filterTasks);
    }
    render(){
        const tit = this.state.namesStatus[this.state.currentTasks]
        return(
            <div className='row'>
                <TaskStatus current={this.state.currentTasks} colors={this.state.colors} names={this.state.namesStatus} handleClick={this.setCurrentState} toggleAllTask={this.viewAllTasks} onAddTask={this.addTask}/>

                <TaskMain colors={this.state.colors} tasks={this.state.viewAll=='off'?this.state.filterTasks:this.state.tareas} current={this.state.currentTasks} titulo={this.state.viewAll=='off'?tit:'Select a task for detail'} onClick={this.openModalOf} nombres={this.state.namesStatus} onFilter={this.filterTasksFunc}/>

                <TaskDetail detalle={this.state.taskDetail}  visible={this.state.viewModal} colores={this.state.colors} onClick={this.closeModal}/>
            </div>
        )
    }
}