 import javafx.stage.Stage;
 import javafx.scene.Scene;
 import javafx.scene.text.Text;
 import javafx.scene.text.Font;
 
 Stage {
     title: "Hello World"
     width: 250
     height: 80
     scene: Scene {
         content: Text {
             font : Font {
                 size : 24
             }
             x: 10, y: 30
             content: "Hello World"
         }
     } 
 }