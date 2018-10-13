#version 300 es
// See readme.md for info and example

precision mediump float;
out vec4 outColor;
void main() {
    int x = int(gl_PointCoord.x * 19.0);
    int y = int(gl_PointCoord.y * 5.0);
    bool colored = false;
    switch(x) {
        case 0: case 2: case 4: case 8: case 12: case 16: case 18:
            colored = true; break;
        case 1: colored = y == 2; break;
        case 5: case 6: colored = y % 2 == 0; break;
        case 9: case 10: case 13: case 14:
            colored = y == 4; break;
        case 17: colored = y % 4 == 0; break;
    }
    outColor = colored? vec4(0.1, 0.3, 0.5, 1.0) : vec4(0.0, 0.0, 0.0, 0.0);
}
