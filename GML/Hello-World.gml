//see it in your browser: 
//https://yal.cc/r/gml/


global.text_angle = 1;

#define step
//Nothing here

#define draw
draw_hello_world(1,room_width / 2, room_height / 2,0);

#define draw_hello_world
var xops = 0;
var ypos = 0;
var txt_angle = global.text_angle;

var String = "Hello, World!"
var TextSize = argument0;
var XPos = argument1;
var YPos = argument2;
var Color = argument3;
draw_set_color(Color);
var strlen = string_length(String);
var i = 0;
var lengthx = 0;
var lengthy = 0;
var color = Color;
while(i < strlen){
    draw_set_color(color);
    draw_text_transformed(XPos + lengthx + (cos(txt_angle)*1.5), YPos + lengthy+(sin(txt_angle)*1.5), string_char_at(String,i+1),TextSize, TextSize, 0);
    lengthx += string_width(string_char_at(String,i+1));
    
    txt_angle -= 1;
    i++;
}
global.text_angle -= 0.35
