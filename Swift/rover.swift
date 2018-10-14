
/*
* Given an array of commands and a NxN matrix, return the position after the commands
* Hackerrank problem.
*
*/
func roverMove(matrixSize: Int, cmds: [String]) -> Int {
    var pos = 0

    for str in cmds {

        switch str {
        case "UP":
            if !(pos - matrixSize < 0) {
                pos -= matrixSize
            }
        case "DOWN":

            if !(pos + matrixSize > (matrixSize * matrixSize)) {
                pos += matrixSize
            }

        case "LEFT":
            if !(pos % matrixSize == 0){
                pos -= 1
            }
        case "RIGHT":

            if !((pos % matrixSize) + 1 == matrixSize) {
                pos += 1
            }

        default:
            break
        }
    }



    return pos
}
