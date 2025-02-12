; ModuleID = 'testir'
source_filename = "testir"

@0 = private unnamed_addr constant [6 x i8] c"\22abc\22\00", align 1
@1 = private unnamed_addr constant [7 x i8] c"\22abc1\22\00", align 1
@2 = private unnamed_addr constant [7 x i8] c"\22abc2\22\00", align 1

define i32 @main() {
entry:
  call void @print(ptr @0)
  call void @print(ptr @1)
  call void @print(ptr @2)
  ret i32 0
}

declare void @print(ptr)
