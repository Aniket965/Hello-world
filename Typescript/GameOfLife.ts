module Conway {
    export class Cell {
        public row: number;
        public col: number;
        public live: boolean;

        constructor(row: number, col: number, live: boolean){
            this.row = row;
            this.col = col;
            this.live = live;
        }
    }

    export class GameOfLife {
        private gridSize: number;
        private canvasSize: number;
        private lineColor: string;
        private liveColor: string;
        private deadColor: string;
        private initialLifeProbability: number;
        private animationRate: number;
        private cellSize: number;
        private context: CanvasRenderingContext2D;
        private world;

        constructor(){
            this.gridSize = 50;
            this.canvasSize = 600;
            this.lineColor = "#cdcdcd";
            this.liveColor = "#10f";
            this.deadColor = "#b01";
            this.initialLifeProbability = 0.5;
            this.animationRate = 60;
            this.cellSize = 0;
            this.context = null;
            this.world = this.createWorld();
            this.circleOfLife();
        }

        public createWorld(){
            return this.travelWorld( (cell : Cell) => {
                cell.live = Math.random() < this.initialLifeProbability;
                return cell; 
            });
        }

        public circleOfLife() : void {
            this.world = this.travelWorld( (cell : Cell) => {
                cell = this.world[cell.row][cell.col];
                this.draw(cell);
                return this.resolveNextGeneration(cell);
            });
            setTimeout( () => {
                this.circleOfLife()
            },
            this.animationRate);
        }

        public resolveNextGeneration(cell : Cell){
            let count = this.countNeighbors(cell);
            let newCell = new Cell(cell.row, cell.col, cell.live);
            if(count < 2 || count > 3){
                newCell.live = false;
            } else if(count === 3){
                newCell.live = true;
            }
            return newCell;
        }

        public countNeighbors(cell : Cell){
            var neighbors = 0;
            for (let row = -1; row <= 1; row++) {
                for (let col = -1; col <= 1; col++) {
                    if(row === 0 && col === 0) continue;
                    if(this.isAlive(cell.row + row, cell.col + col)){
                        neighbors++;
                    }
                }
            }
            return neighbors;
        }

        public isAlive(row : number, col : number){
            if(row < 0 || col < 0 || row >= this.gridSize || col >= this.gridSize){
                return false;
            }
            return this.world[row][col].live;
        }

        public travelWorld(callback){
            let result = [];
            for (let row = 0; row < this.gridSize; row++) {
                let rowData = [];
                for (let col = 0; col < this.gridSize; col++) {
                    rowData.push(callback(new Cell(row, col, false)));
                }
                result.push(rowData);
            }
            return result;
        }

        public draw(cell : Cell){
            if(this.context === null){
                this.context = this.createDrawingContext();
            }
            if(this.cellSize === 0){
                this.cellSize = this.canvasSize/this.gridSize;
            }
            this.context.strokeStyle = this.lineColor;
            this.context.strokeRect(cell.row * this.cellSize, cell.col * this.cellSize, this.cellSize, this.cellSize);
            this.context.fillStyle = cell.live ? this.liveColor : this.deadColor;
            this.context.fillRect(cell.row * this.cellSize, cell.col * this.cellSize, this.cellSize, this.cellSize);
        }

        public createDrawingContext(){
            let canvas = <HTMLCanvasElement> document.createElement("canvas");
            canvas.id = "conway-canvas";
            canvas.width = this.canvasSize;
            canvas.height = this.canvasSize;
            document.body.appendChild(canvas);
            return canvas.getContext("2d");
        }
    }
}

const game = new Conway.GameOfLife();
