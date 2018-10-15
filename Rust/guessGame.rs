extern crate rand;

use std::io;
use std::cmp::Ordering;
use rand::Rng;
use std::mem;


fn main() {
    println!("Guess the number!");

    let secret_number = rand::thread_rng().gen_range(1, 101);

    loop {
        println!("Please input your guess.");

        let mut guess = String::new();

        io::stdin().read_line(&mut guess)
            .expect("Failed to read line");

        let guess: u32.parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        println!("You guessed: {} also the size of it is {}", guess, mem::size_of_val(&guess));

        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal => {
                println!("You win!");
                break;
            }
        }
    }
}

