#antlr4 install
#antlr lua grammar show

# http://github.com/antlr/grammars-v4

#antlr4 Lua.g4
#javac Lua*.java
#java org.antlr.v4.gui.TestRig Lua chunk -gui < test.lua
#grun Lua chunk -gui


# include generated files in project environment
include_directories(
	${PROJECT_SOURCE_DIR}
)

set(MLIR_DIR /home/zx/Desktop/llvmbuild/lib/cmake/mlir)
Link_directories(/usr/local/lib)
find_package(MLIR REQUIRED CONFIG)
message(STATUS "Using MLIRConfig.cmake in: $(MLIR_DIR)")
message(STATUS "Using LLVMConfig.cmake in: $(LLVM_DIR)")

set(LLVM_RUNTIME_OUTPUT_INTDIR ${CMAKE_BINARY_DIR}/bin)
set(LLVM_LIBRARY_OUTPUT_INTDIR ${CMAKE_BINARY_DIR}/lib)
set(MLIR_BINARY_DIR ${CMAKE_BINARY_DIR})

list(APPEND CMAKE_MODULE_PATH "${MLIR_CMAKE_DIR}")
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(TableGen)
include(AddLLVM)
include(AddMLIR)
include(HandleLLVMOptions)

include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})
link_directories(${LLVM_BUILD_LIBRARY_DIR})

include_directories(${MLIR_INCLUDE_DIRS})

include_directories(include/)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(LLVM_COMPONENTS Support)

set(LIBS
	MLIROptLib
	MLIRExecutionEngine
	#MLIRAffine
	LLVMLinker
)
#antlr4 -Werror -Dlanguage=Cpp -listener -visitor -package luac -o ./ Lua.g4
#clang++ *.cpp -std=c++17 -lantlr4-runtime -I/usr/local/include/antlr4-runtime

SET(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



include_directories(/home/zx/Desktop/antlrbuild/include/antlr4-runtime)
include_directories(./)

# 创建一个变量来存储所有的 .cpp 文件
file(GLOB_RECURSE CPP_FILES *.cpp)
file(GLOB_RECURSE H_FILES *.h)

add_executable(mylua
    ${CPP_FILES}
    ${H_FILES}
)

target_link_directories(mylua PUBLIC "/home/zx/Desktop/antlrbuild/lib")

target_link_libraries(mylua
	PRIVATE
	${LIBS}
	MLIRAnalysis
	MLIRCallInterfaces
	MLIRIR
	MLIRParser
	MLIRPass
	MLIRSideEffectInterfaces
	MLIRDialect
	#MLIRFunc
	MLIRFuncToLLVM
    antlr4-runtime
)