use std::{
    io::{stdin, stdout, Write},
    str::FromStr,
};

fn main() {
    loop {
        println!("1. rectangle");
        println!("2. triangle");
        println!("3. diagonal line");

        let selection: u8 = match get_input("select a shape (0 to quit): ") {
            Ok(num) => match num {
                0 => break,
                1..=3 => num,
                _ => {
                    println!("invalid selection.");
                    println!();
                    continue;
                }
            },
            Err(_) => {
                println!("invalid selection.");
                println!();
                continue;
            }
        };

        let size: u128 = match get_input("select a size: ") {
            Ok(num) => num,
            Err(_) => {
                println!("invalid size.");
                println!();
                continue;
            } 
        };

        println!();
        match selection {
            1 => {
                for _row in 0..size {
                    for _col in 0..size {
                        print!("+");
                    }
                    println!();
                }
            },
            2 => {
                for row in 0..size {
                    for col in 0..size {
                        if col <= row {
                            print!("+");
                        } else {
                            print!(" ");
                        }
                    }
                    println!();
                }
            },
            3 => {
                for row in 0..size {
                    for col in 0..size {
                        if col == row {
                            print!("+");
                        } else {
                            print!(" ");
                        }
                    }
                    println!();
                }
            },
            _ => continue
        }
        println!();
    }
}

fn get_input<T: FromStr>(prompt: &str) -> Result<T, T::Err> {
    print!("{}", prompt);
    stdout().flush().expect("failed to flush stdout.");

    let mut input = String::new();
    match stdin().read_line(&mut input) {
        Ok(_) => (), // line goes into input
        Err(_) => (), // input isn't changed; is blank
    }

    input.trim().parse::<T>()
}
