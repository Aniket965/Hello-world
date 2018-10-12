fn fib(arg: i32) -> i32 {
    if arg < 0 {
        return 1;
    }
    
    fib(arg - 1) + fib(arg - 2)
}

fn main() {
    println!("{}", fib(10));
}