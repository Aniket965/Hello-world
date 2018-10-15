function drawLive(x, y) {
    context.fillRect(cellSize * x, cellSize * y, cellSize, cellSize);
}

function drawDead(x, y) {
    context.strokeRect(cellSize * x, cellSize * y, cellSize, cellSize);
}

function drawField() {
    context.clearRect(0, 0, field.width, field.height);
    var stateToDraw = running ? currentState : initialState;
    stateToDraw.forEach(
        (col, x) => col.forEach(
            (cell, y) => cell ? drawLive(x, y) : drawDead(x, y)
        )
    );
}

function handleFieldClick(event) {
    if (running && !paused) return;

    var x = Math.floor(event.offsetX / cellSize);
    var y = Math.floor(event.offsetY / cellSize);

    if (x >= size || y >= size || x < 0 || y < 0) return;

    var stateToDraw = running ? currentState : initialState;
    stateToDraw[x][y] = !stateToDraw[x][y];
    drawField();
}

function countAliveAround(x, y) {
    var above = y > 0 ? y - 1 : size - 1;
    var below = y < size - 1 ? y + 1 : 0;
    var right = x < size - 1 ? x + 1 : 0;
    var left  = x > 0 ? x - 1 : size - 1;
    return (
        currentState[left][above] + currentState[x][above] + currentState[right][above] +
        currentState[left][y] + currentState[right][y] +
        currentState[left][below] + currentState[x][below] + currentState[right][below]
    );
}

function updateState() {
    currentState.forEach(
        (col, x) => col.forEach(
            (cell, y) => {
                var aliveAround = countAliveAround(x, y);
                if (cell && (aliveAround === 2 || aliveAround === 3) ||
                    !cell && aliveAround === 3) {
                    newState[x][y] = true;
                }
                else newState[x][y] = false;
            }
        )
    )
    var tmp = currentState;
    currentState = newState;
    newState = tmp;
}

function loop() {
    if (running && !paused) {
        return window.setInterval(() => {
            updateState();
            drawField();
            genCount++;
            genText.innerHTML = genCount;
            // loop();
        }, period * 1000);
    }
}

function abort() {
    window.clearInterval(timer);
    running = paused = false;
    genCount = 0;
    drawField();
}

function start() {
    if (!paused) {
        initialState.forEach(
            (col, i) => col.forEach(
                (elem, j) => currentState[i][j] = elem
            )
        );
    }
    running = true;
    paused = false;
    
    timer = loop();
}

function pause() {
    window.clearInterval(timer);
    paused = true;
}

function clear() {
    initialState.forEach(col => col.fill(false));
    drawField();
}

function onStartClick() {
    startPauseButton.value = 'Pause';
    startPauseButton.removeEventListener('click', onStartClick);
    startPauseButton.addEventListener('click', onPauseClick);
    clearButton.disabled = true;
    sizeSlider.disabled = true;
    periodSlider.disabled = true;
    start();
}

function onPauseClick() {
    startPauseButton.value = 'Start';
    startPauseButton.removeEventListener('click', onPauseClick);
    startPauseButton.addEventListener('click', onStartClick);
    periodSlider.disabled = false;
    pause();
}

function onAbortClick() {
    startPauseButton.value = 'Start';
    startPauseButton.removeEventListener('click', onPauseClick);
    startPauseButton.addEventListener('click', onStartClick);
    clearButton.disabled = false;
    sizeSlider.disabled = false;
    periodSlider.disabled = false;
    genCount = 0;
    genText.innerHTML = genCount;
    abort();
}

function onClearClick() {
    if (!running) clear();
}

function shrinkStates(diff) {
    for (var i = 0; i < diff; i++) {
        initialState.pop();
        currentState.pop();
        newState.pop();
    }
    for (var i = 0; i < diff; i++) {
        initialState.forEach(col => col.pop());
        currentState.forEach(col => col.pop());
        newState.forEach(col => col.pop());
    }
}

function expandStates(diff) {
    for (var i = 0; i < diff; i++) {
        initialState.push(new Array(size));
        initialState[initialState.length - 1].fill(false);
        currentState.push(new Array(size));
        currentState[currentState.length - 1].fill(false);
        newState.push(new Array(size));
        newState[newState.length - 1].fill(false);
    }
    for (var i = 0; i < diff; i++) {
        initialState.forEach(col => col.push(false));
        currentState.forEach(col => col.push(false));
        newState.forEach(col => col.push(false));
    }
}

function updateStatesSizes(newSize) {
    var sizeDiff = newSize - size;
    
    if (sizeDiff > 0) expandStates(sizeDiff);
    else if (sizeDiff < 0) shrinkStates(-sizeDiff);
}

function updateSize(event) {
    if (!event) return;
    var newSize = event.target.valueAsNumber;
    if (newSize === size) return;
    cellSize = field.width / newSize < defaultCellSize 
             ? Math.floor(field.width / newSize) 
             : defaultCellSize;

    updateStatesSizes(newSize);

    size = newSize;
    sizeText.innerHTML = size;
    abort();
    drawField();
}

function initializeState() {
    newState = new Array(size);
    currentState = new Array(size);
    initialState = new Array(size);
    for (var i = 0; i < size; i++) {
        newState[i] = new Array(size);
        currentState[i] = new Array(size);
        initialState[i] = new Array(size);
    }
    clear();
    abort();
    drawField();
}

var running = false;
var paused = false;

var timer;

var field = document.getElementById('field');
var fieldContainer = document.getElementById('fieldContainer').getBoundingClientRect();
var maxHeight = window.innerHeight - fieldContainer.y - 25;
var maxWidth = window.innerWidth - fieldContainer.x - fieldContainer.y;
field.width = field.height = maxHeight > maxWidth ? maxWidth : maxHeight;
var context = field.getContext('2d');
field.addEventListener('click', handleFieldClick);

var defaultCellSize = 50;
var cellSize = defaultCellSize;

var genCount = 0;
var genText = document.getElementById('genText');

var sizeText = document.getElementById('sizeText');
var sizeSlider = document.getElementById('sizeSlider');
var size = Number(sizeSlider.value);

var periodText = document.getElementById('periodText');
var periodSlider = document.getElementById('periodSlider');
var period = Number(periodSlider.value);

sizeText.innerHTML = size;
// sizeSlider.oninput = () => {
//     size = Number(sizeSlider.value);
//     sizeText.innerHTML = size;
//     updateSize();
//     drawField();
// };
sizeSlider.oninput = updateSize;

periodText.innerHTML = period;
periodSlider.oninput = () => {
    period = Number(periodSlider.value);
    periodText.innerHTML = period;
};

var initialState = new Array(size);
var currentState = new Array(size);
var newState = new Array(size);

updateSize();

var startPauseButton = document.getElementById('startPauseButton');
var abortButton = document.getElementById('abortButton');
var clearButton = document.getElementById('clearButton');

startPauseButton.addEventListener('click', onStartClick);
abortButton.addEventListener('click', onAbortClick);
clearButton.addEventListener('click', onClearClick);

initializeState();