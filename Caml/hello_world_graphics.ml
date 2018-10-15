
(* Implementation of the Hello World! using the graphics library of Caml *)
(* Lozul, Hacktoberfest 2018 *)

(* Load library *)
#load "graphics.cma" ;; (* Load the graphics library *)
open Graphics ;;        (* Open the module *)
open_graph "300x300" ;; (* 300w x 300h window *)

let hello = "Hello World!";;
let window_width = size_x () and window_height = size_y ();;
let text_width = match (text_size hello) with (a,b) -> a;;

moveto ((window_width / 2) - (text_width / 2)) (window_height / 2);;
draw_string hello;;