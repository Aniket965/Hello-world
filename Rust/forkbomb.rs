#[allow(unconditional_recursion)]
fn main() {
    std::thread::spawn(main);
    main();
}
