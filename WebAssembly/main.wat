(module
  (memory (export "memory") 1)
  (data (i32.const 0) "Hello, world!")
  (global (export "length") i32 (i32.const 12))
  (global (export "position") i32 (i32.const 0)))
