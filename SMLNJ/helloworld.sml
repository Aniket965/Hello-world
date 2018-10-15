fun helloworld("") = "Hello World!"
  | helloworld(name : string) = "Hello " ^ name ^ "!";

helloworld("");
helloworld("Hacktoberfest 2018");