
# How to compile and run
```
$ brew install nasm
$ nasm -version
NASM version 2.12.02 compiled on Sep 14 2016
$ nasm -f macho64 hello.s
$ ld -macosx_version_min 10.7.0 -lSystem -o hello hello.o
$ ./hello
Hello, world!
```
# Atribution
Thanks to https://jameshfisher.com/2017/02/20/macos-assembly-hello-world.html
