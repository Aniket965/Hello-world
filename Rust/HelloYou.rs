use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() != 0 {
        for argument in env::args() {
            println!("Hello, {}!", argument);
        }
    } else {
        println!("Hello, You!");
    }
}