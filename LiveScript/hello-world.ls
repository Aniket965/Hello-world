hello-world = (name = "World") ->
  console.log "Hello, ${name}!"

# usage:

# with parameter
hello-world "Dude" # => "Hello, Dude!"

# parameterless call with default
hello-world! # => "Hello, World!"