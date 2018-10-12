const form = document.querySelector('#task-form')
const taskList = document.querySelector('.collection')
const clearBtn = document.querySelector('.clear-tasks')
const filter = document.querySelector('#filter')
const taskInput = document.querySelector('#task')

loadEventListeners()

function loadEventListeners(){
    document.addEventListener('DOMContentLoaded', getTasks)
    form.addEventListener('submit', addTask)
    taskList.addEventListener('click', removeTask)
    clearBtn.addEventListener('click', clearTasks)
    filter.addEventListener('keyup', filterTasks)
}

function getTasks(){
    let tasks;
    if(localStorage.getItem('tasks') === null){
        tasks = []
    }else {
        tasks = JSON.parse(localStorage.getItem('tasks'))
    }

    tasks.forEach((task) => {
        const li = document.createElement('li')
        li.className = 'collection-item'
        li.appendChild(document.createTextNode(task))
        
        const link = document.createElement('a')
        link.href = '#'
        link.className = 'delete-item secondary-content'
        link.innerHTML = '<i class="fa fa-remove"></i>'
    
        li.appendChild(link)
        taskList.appendChild(li)
    })
}

function addTask(e){
    if(taskInput.value === ''){
        alert('Please, enter a task!')
    } else {
        const li = document.createElement('li')
        li.className = 'collection-item'
        li.appendChild(document.createTextNode(taskInput.value))
        
        const link = document.createElement('a')
        link.href = '#'
        link.className = 'delete-item secondary-content'
        link.innerHTML = '<i class="fa fa-remove"></i>'
    
        li.appendChild(link)
        taskList.appendChild(li)

        addTaskToLocalStorage(taskInput.value)
        
        taskInput.value = ''
    }

    e.preventDefault()
}

function addTaskToLocalStorage(task){
    let tasks
    if(localStorage.getItem('tasks') === null){
        tasks = []
    }else {
        tasks = JSON.parse(localStorage.getItem('tasks'))
    }

    tasks.push(task)

    localStorage.setItem('tasks', JSON.stringify(tasks))
}


function removeTask(e){
    if(e.target.parentElement.classList.contains('delete-item')){
        if(confirm('Are you sure of that?'))
            e.target.parentElement.parentElement.remove()
            removeTaskFromLocalStorage(e.target.parentElement.parentElement)
    }
    e.preventDefault()
}

function removeTaskFromLocalStorage(taskItem){
    let tasks
    if(localStorage.getItem('tasks') === null){
        tasks = []
    }else {
        tasks = JSON.parse(localStorage.getItem('tasks'))
    }
    
    tasks.forEach((task, index) => {
        if(taskItem.textContent === task){
            tasks.splice(index, 1)
        }
    })

    localStorage.setItem('tasks', JSON.stringify(tasks))
}

function clearTasks(e){
    if(confirm('Are you dure of that?')){
        while(taskList.firstChild){
            taskList.removeChild(taskList.firstChild)
            clearTasksFromLocalStorage()
        }
    }

    e.preventDefault()
}

function clearTasksFromLocalStorage(){
    localStorage.clear()
}

function filterTasks(e){
    const text = e.target.value.toLowerCase()

    document.querySelectorAll('.collection-item').forEach((task) => {
        const item = task.firstChild.textContent
        if(item.toLowerCase().indexOf(text) != -1){
            task.style.display = 'block'
        } else{
            task.style.display = 'none'
        }
    })
}