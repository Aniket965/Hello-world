"use strict";

/**
 * A Diamond Square implementation operating on flat `Float32Array`.
 */
class DiamondSquare {

    /**
     * Creates a heightmap based on parameters passed.
     * @param {number} sideLength - Side length of a the resulting grid array. Diamond-Square can only have a size (2^n)+1.
     * @param {number} maxHeight - Max height value for the heightmap's values.
     * @param {number} roughness - A factor which is used as offset value for the heightmap. Defines the roughness of a heightmap.
     * @returns {Float32Array} - A flat `Float32Array` representing a 2D-grid with size `sideLength * sideLength`.
     */
    static HeightMap(sideLength, maxHeight, roughness) {

        const n = Math.log(sideLength - 1) / Math.log(2);
        if (n < 0 || n % 1 != 0) {
            throw "Invalid side length in Diamond Square: Side Length has to be in range of `(2^n) + 1`.";
        }

        let gridArray = new Float32Array(sideLength * sideLength);
        this._initGrid(gridArray, sideLength, maxHeight);
        this._seed(gridArray, sideLength, roughness);

        return gridArray;
    }

    /**
     * Sets the initial corner values for a Diamond-Square grid.
     * @param {Float32Array} gridArray - An `Float32Array` with its values (ideally) set to `0`.
     * @param {number} sideLength - Side length of a the resulting grid array. Diamond-Square can only have a size `(2^n)+1`.
     * @param {number} maxHeight - Max height value for the heightmap's values.
     * @returns {Float32Array} - A flat `Float32Array` representing a 2D-grid with its NW, NE, SE and SW values initialized.
     */
    static _initGrid(gridArray, sideLength, maxHeight) {

        gridArray[0] = MathHelper.RandomInt(0, maxHeight); // NW
        gridArray[sideLength - 1] = MathHelper.RandomInt(0, maxHeight); // NE
        gridArray[sideLength * sideLength - 1] = MathHelper.RandomInt(0, maxHeight); // SE
        gridArray[sideLength * sideLength - sideLength] = MathHelper.RandomInt(0, maxHeight); // SW

        return gridArray;
    }

    /**
     * Performs the Diamond Square (aka. Midpoint displacement) algorithm on a given flat TypedArray.
     * @param {Float32Array} gridArray - An (Diamond-Square-initialized) `Float32Array`.
     * @param {number} sideLength - Side length of a the resulting grid array.
     * @param {number} roughness - A factor which is used as offset value for the heightmap. Defines the roughness of a heightmap.
     * @returns {Float32Array} - Returns a ready to use heightmap produced by the Diamond-Square algorithm.
     */
    static _seed(gridArray, sideLength, roughness) {
        let step = Math.sqrt(gridArray.length) - 1;
        let size = Math.sqrt(gridArray.length) - 1;
        let currentRoughness = roughness;

        while (step / 2 >= 1) {
            let rough = MathHelper.RandomInt(0, currentRoughness); // TODO: WARN: Random function should return float

            let numSquares = (Math.pow(size, 2)) / (Math.pow(step, 2));
            let perRowSquares = Math.floor(Math.sqrt(numSquares));
            for (let i = 0; i < perRowSquares; i++) {
                for (let j = 0; j < perRowSquares; j++) {
                    const nwIndex = this._getNWIndex(i, j, step, sideLength);
                    const cornerValues = this._getCornerValues(nwIndex, gridArray, sideLength, step);
                    this._diamondStep(nwIndex, cornerValues, gridArray, sideLength, step);
                    this._squareStep(nwIndex, cornerValues, gridArray, sideLength, step, rough);
                }
            }

            currentRoughness /= 2.0;
            step /= 2;
        }

        return gridArray;
    }

    /**
     * Performs the Diamond Step by setting the center value for the current step.
     * @param {number} nwIndex - North-West index for current step.
     * @param {number[]} cornerValues - The corner values for the current step.
     * @param {Float32Array} gridArray - Array holding heightmap data. Function will write to this array.
     * @param {number} sideLength - Grid's side length. 
     * @param {number} stepSize - Current step size.
     * @returns {Float32Array} - Returns the typed array the function of operating on.
     */
    static _diamondStep(nwIndex, cornerValues, gridArray, sideLength, stepSize) {

        // Center point. Calculated from "East - `stepSize / 2`"
        gridArray[(((nwIndex + stepSize * sideLength) + stepSize) - (stepSize * sideLength) / 2) - stepSize / 2]
            = (cornerValues[0] + cornerValues[1] + cornerValues[2] + cornerValues[3]) / 4;

        return gridArray;
    }

    /**
     * Performs the Square Step by setting the north, east, south and west values for the current step.
     * @param {number} nwIndex - North-West index for current step.
     * @param {number[]} cornerValues - The corner values for the current step. 
     * @param {Float32Array} gridArray - Array holding heightmap data. Function will write to this array. 
     * @param {number} sideLength - Grid's side length.  
     * @param {number} stepSize - Current step size. 
     * @param {number} roughness - Roughness factor for the current step.
     * @returns {Float32Array} - Returns the typed array the function of operating on.
     */
    static _squareStep(nwIndex, cornerValues, gridArray, sideLength, stepSize, roughness) {

        const average = (cornerValues[0] + cornerValues[1] + cornerValues[2] + cornerValues[3]) / 4;
        const value = average + (roughness * MathHelper.RandomInt(-1, 1));

        // N
        gridArray[nwIndex + (stepSize / 2)] = value;
        // E
        gridArray[((nwIndex + stepSize * sideLength) + stepSize) - (stepSize * sideLength) / 2] = value;
        // S
        gridArray[(nwIndex + stepSize * sideLength) + stepSize / 2] = value;
        // W
        gridArray[(nwIndex + stepSize * sideLength) - (stepSize * sideLength) / 2] = value;

        return gridArray;
    }

    /**
     * Return an array holding the north-west, north-east, south-west and south-east values for the current step.
     * @param {number} nwIndex - North-West index for current step. 
     * @param {Float32Array} gridArray - The corner values for the current step.  
     * @param {number} sideLength - Grid's side length. 
     * @param {number} stepSize - Current step size.  
     * @returns {Float32Array} - Returns the typed array the function of operating on.
     */
    static _getCornerValues(nwIndex, gridArray, sideLength, stepSize) {
        return [
            gridArray[nwIndex], // NW
            gridArray[nwIndex + stepSize], // NE
            gridArray[nwIndex + stepSize * sideLength], // SW
            gridArray[nwIndex + stepSize + stepSize * sideLength] // SE
        ];
    }

    /**
     * Returns the array index for the north-west value for the current step.
     * @param {number} i - Current row, I guess.
     * @param {number} j - Current column, I guess.
     * @param {number} stepSize - Current step size.
     * @param {number} sideLength - Grid's side length.  
     * @returns {number} - Returns the index for current north-west value.
     */
    static _getNWIndex(i, j, stepSize, sideLength) {
        return (i * (stepSize * sideLength)) + j * stepSize;
    }

    /**
     * Produces an array holding all valid Diamond Square grid sizes up to a passed max value.
     * @param {number} max - The maximum amount of iteration sizes to produce.
     * @returns {number[]} - Array holding valid Diamond Square grid sizes.
     */
    static GenerateIterations(max) {
        let iterations = [];
        for (let n = 0; n < max; n++) {
            iterations.push(Math.pow(2, n) + 1);
        }
        return iterations;
    }

}

