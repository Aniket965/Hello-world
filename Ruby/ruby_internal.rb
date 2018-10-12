require 'ripper'
require 'pp'

prog = "x > 10 ? 'foo' : 'bar'"

puts "How Ruby interpreter works \n"

puts "Program to interpret: \n" + prog
puts


puts "#" * 40
puts "Tokenizing: break the program into chunk"
puts "#" * 40
pp Ripper.tokenize(prog)
puts


puts "#" * 40
puts "Lexing: identify each chunk"
puts "#" * 40
pp Ripper.lex(prog)
puts


puts "#" * 40
puts "Parsing: organize all chunks into a tree structure (AST)"
puts "#" * 40
pp Ripper.sexp(prog)
puts


puts "#" * 40
puts "RubyVM: run bytecode using the AST"
puts "#" * 40
puts RubyVM::InstructionSequence.compile(prog).disassemble
puts
