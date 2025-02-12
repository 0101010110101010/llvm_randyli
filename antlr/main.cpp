#include <antlr4-runtime.h>

#include <iostream>
#include <typeinfo>

#include "LuaBaseListener.h"
#include "LuaLexer.h"
#include "LuaParser.h"
#include "genir.h"

#if 1
int main(int argc, char *  argv[])
{
    std::ifstream stream;
    stream.open(argv[1]);
    antlr4::ANTLRInputStream input(stream);
    luac::LuaLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    luac::LuaParser parser(&tokens);
    auto chunk = parser.chunk();
    std::cout << chunk->toStringTree(&parser) << std::endl;

    luac::IRGenerator IR ("testir");
    IR.visitChunk(chunk);
    IR.dump();
    return 0;
}
#else
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/GlobalVariable.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Type.h"
#include "llvm/Support/raw_ostream.h"
#include <iostream>

int main() {
    // 创建LLVM上下文和模块
    llvm::LLVMContext context;
    llvm::Module *module = new llvm::Module("testir", context);

    // 创建全局字符串常量
    std::string str0 = "abc\0";  // 包含空终止符
    std::string str1 = "abc1\0";
    std::string str2 = "abc2\0";
    
    llvm::Constant *c0 = llvm::ConstantDataArray::getString(context, str0, true);
    llvm::GlobalVariable *gv0 = new llvm::GlobalVariable(
        *module, c0->getType(), true, llvm::GlobalValue::PrivateLinkage, c0, "0");
    
    llvm::Constant *c1 = llvm::ConstantDataArray::getString(context, str1, true);
    llvm::GlobalVariable *gv1 = new llvm::GlobalVariable(
        *module, c1->getType(), true, llvm::GlobalValue::PrivateLinkage, c1, "1");
    
    llvm::Constant *c2 = llvm::ConstantDataArray::getString(context, str2, true);
    llvm::GlobalVariable *gv2 = new llvm::GlobalVariable(
        *module, c2->getType(), true, llvm::GlobalValue::PrivateLinkage, c2, "2");

    // 创建主函数 @main
    llvm::FunctionType *mainFuncType = llvm::FunctionType::get(llvm::Type::getInt32Ty(context), false);
    llvm::Function *mainFunc = llvm::Function::Create(mainFuncType, llvm::Function::ExternalLinkage, "main", module);
    llvm::BasicBlock *entryBlock = llvm::BasicBlock::Create(context, "entry", mainFunc);
    llvm::IRBuilder<> builder(entryBlock);

    // 创建对 @print 函数的声明
    llvm::Type *int8Ty = llvm::Type::getInt8Ty(context);
    llvm::Type *int8PtrTy = llvm::PointerType::get(int8Ty, 0);
    llvm::FunctionType *printFuncType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context), {int8PtrTy}, false);
    llvm::Function::Create(printFuncType, llvm::Function::ExternalLinkage, "print", module);

    // 生成对 @print 的调用
    llvm::Function *printFunc = module->getFunction("print");
    llvm::Value *gepIndices[] = {builder.getInt32(0), builder.getInt32(0)};

    // 获取每个全局字符串的首元素地址
    llvm::Value *gv0Ptr = builder.CreateInBoundsGEP(
        gv0->getValueType(), gv0, gepIndices, "gv0.ptr");
    builder.CreateCall(printFunc, {gv0Ptr});

    llvm::Value *gv1Ptr = builder.CreateInBoundsGEP(
        gv1->getValueType(), gv1, gepIndices, "gv1.ptr");
    builder.CreateCall(printFunc, {gv1Ptr});

    llvm::Value *gv2Ptr = builder.CreateInBoundsGEP(
        gv2->getValueType(), gv2, gepIndices, "gv2.ptr");
    builder.CreateCall(printFunc, {gv2Ptr});

    // 返回 0
    builder.CreateRet(llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 0));

    // 验证模块
    std::string error;
    llvm::raw_string_ostream errorStream(error);
    if (llvm::verifyModule(*module, &errorStream)) {
        std::cerr << "Error: " << error << "\n";
        return 1;
    }

    // 打印IR到标准输出
    module->print(llvm::outs(), nullptr);

    // 清理
    delete module;
    return 0;
}

#endif