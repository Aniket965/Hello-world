const taskForm = document.querySelector("form");
const filterInput = document.getElementById('filter');
const clearTasksBtn = document.querySelector('.clear-tasks');
const collection = document.querySelector('.collection');

taskForm.addEventListener('submit',addToCollection);
collection.addEventListener('click',removeTaskItem);
clearTasksBtn.addEventListener('click',clearTasks);
filterInput.addEventListener('keyup',filterTask);
document.addEventListener('DOMContentLoaded',getTasks);

function addToCollection(e)
{
    e.preventDefault();
    let task = document.getElementById('task'); 

    if(task.value != "")
    {
        let textNode = document.createTextNode(task.value);

        let li = document.createElement('li');
        li.className = "collection-item";

        let delLink = document.createElement('a');
        
        delLink.className = "delete-item secondary-content";

        delLink.innerHTML = '<i class="fa fa-remove"></i>';

        li.appendChild(textNode);
        li.appendChild(delLink);
        collection.appendChild(li);
        addToLocalStorage(task.value);
        task.value = "";
    }
    else
    {
        alert("Please Enter Task");
    }
    
    
}


function removeTaskItem(e)
{
    e.preventDefault();

    if(e.target.parentElement.classList.contains("delete-item"))
    {
        collection.removeChild(e.target.parentElement.parentElement);
        removeFromLocalStorage(e.target.parentElement.parentElement);
    }
}


function clearTasks(e)
{
    e.preventDefault();

    while(collection.firstChild)
    {
        collection.removeChild(collection.firstChild);
        if(localStorage.getItem('tasks')===null)
        {
            
        }
        else
        {
            localStorage.clear();
        }
    }
}

function filterTask(e)
{
    const text = e.target.value.toLowerCase();

    collectionItem=document.querySelectorAll('.collection-item');

    collectionItem.forEach(function(task){
        const taskContent = task.firstChild.textContent;

        if(taskContent.toLowerCase().indexOf(text)!=-1)
        {
            task.style.display = 'block';
        }
        else
        {
            task.style.display = 'none';
        }
    })
}

function addToLocalStorage(task)
{
    let tasks;
    if(localStorage.getItem('tasks')===null)
    {
        tasks = []
    }
    else
    {
        tasks = JSON.parse(localStorage.getItem('tasks'));
    }

    tasks.push(task);
    localStorage.setItem('tasks',JSON.stringify(tasks));
}

function getTasks()
{
    let tasks;
    if(localStorage.getItem('tasks')===null)
    {
        tasks = []
    }
    else
    {
        tasks = JSON.parse(localStorage.getItem('tasks'));
    }

    tasks.forEach(function(task){
        let textNode = document.createTextNode(task);

        let li = document.createElement('li');
        li.className = "collection-item";

        let delLink = document.createElement('a');
        
        delLink.className = "delete-item secondary-content";

        delLink.innerHTML = '<i class="fa fa-remove"></i>';

        li.appendChild(textNode);
        li.appendChild(delLink);
        collection.appendChild(li);
    });
}

function removeFromLocalStorage(taskItem)
{
    const taskText = taskItem.textContent;

    let tasks;
    if(localStorage.getItem('tasks')===null)
    {
        tasks = []
    }
    else
    {
        tasks = JSON.parse(localStorage.getItem('tasks'));
    }

    tasks.forEach(function(task,index){
        if(taskText === task)
        {
            tasks.splice(index,1);
        }
    });

    localStorage.setItem('tasks',JSON.stringify(tasks));
}