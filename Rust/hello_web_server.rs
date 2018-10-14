// https://doc.rust-lang.org/book/second-edition/ch20-01-single-threaded.html

use std::net::TcpListener;
use std::io::Write;

fn main() {
    let listener = TcpListener::bind("0.0.0.0:9802").unwrap();

    println!("Server started!");
    println!("http://localhost:9802");

    for stream in listener.incoming() {
        let mut stream = stream.unwrap();

        let contents = r#"<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <title>NeuroWhAI</title>
    <style>
      h {
        font-size: 64px;
      }
    </style>
  </head>
  <body>
    <h>Hello, World!</h>
  </body>
</html>"#;
        let response = format!("HTTP/1.1 200 OK\r\n\r\n{}", contents);

        stream.write(response.as_bytes()).unwrap();
        stream.flush().unwrap();
    }
}
