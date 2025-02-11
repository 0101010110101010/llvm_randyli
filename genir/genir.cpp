#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

int main()
{
    auto context = std::make_unique<llvm::LLVMContext>();
    auto mod = std::make_unique<llvm::Module>("genir.cppcon", *context);
    auto builder = std::make_unique<llvm::IRBuilder<>>(*context);

    //std::vector<llvm::Type*>
    std::vector<llvm::Type *> args(2, llvm::Type::getInt32Ty(*context));
    llvm::FunctionType *functionType = llvm::FunctionType::get(llvm::Type::getInt32Ty(*context), args, false);

    llvm::Function *f = llvm::Function::Create(functionType, llvm::Function::ExternalLinkage, "addtmp", mod.get());

    llvm::BasicBlock *BB = llvm::BasicBlock::Create(*context, "entrytmp", f);
    builder->SetInsertPoint(BB);
    auto RetVal = llvm::ConstantInt::get(*context, llvm::APInt(/*nbits*/32, 666, /*bool*/true));

    builder->CreateRet(RetVal);
    mod->print(llvm::errs(), nullptr);
    return 0;
}