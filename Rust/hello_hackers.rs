// first Hacktoberfest #2018
// Greets from Bochum (Germany)
fn main() {
    let mut name = String::new();

    std::io::stdin()
        .read_line(&mut name)
        .expect("please enter a valid string");

    println!("Hello World, from {}", name);
    
}