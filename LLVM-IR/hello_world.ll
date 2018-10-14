@.str = private unnamed_addr constant [13 x i8] c"hello world\0A\00"

declare i32 @puts(i8* nocapture) nounwind

define i32 @main() {
  %hello_world = getelementptr [13 x i8], [13 x i8]* @.str, i64 0, i64 0

  call i32 @puts(i8* %hello_world)
  ret i32 0
}
