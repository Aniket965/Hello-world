-- "Hello World" demo for the GUI library

import GUI

main = runGUI "Hello" (Col [] [Label [Text "Hello world!"],
                               Button exitGUI [Text "Stop"]]
