#include "iostream"
#include "any"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "LuaParser.h"
#include "LuaBaseVisitor.h"
#include "genir.h"

namespace luac
{
    antlrcpp::Any IRGenerator::visitChunk(LuaParser::ChunkContext *ctx)
    {
        // create int main(){}
        std::vector<llvm::Type *> arg_types; //empty
        llvm::FunctionType *function_type = llvm::FunctionType::get(llvm::Type::getInt32Ty(*context), arg_types, false);
        llvm::Function *main_function = llvm::Function::Create(function_type, llvm::Function::ExternalLinkage, "main", *module);

        llvm::BasicBlock *BB = llvm::BasicBlock::Create(*context, "entry", main_function);
        builder->SetInsertPoint(BB);

        //create function body
        LuaBaseVisitor::visitChunk(ctx);
        
        //create main ret
        auto RetVal = llvm::ConstantInt::get(*context, llvm::APInt(/*nbits*/ 32, 0, /*bool*/true));
        builder->CreateRet(RetVal);

        return 0;
    }

    antlrcpp::Any IRGenerator::visitFunctioncall(LuaParser::FunctioncallContext *ctx)
    {
        std::string funcName = ctx->varOrExp()->var_()->getText();
        if(funcName == "print")
        {
            std::string arg= ctx->nameAndArgs()[0]->args()->explist()->exp()[0]->string()->getText();
            std::cout << funcName << std::endl;
            std::cout << arg << std::endl;

            // 1 create the function
            #if 0
            std::vector<llvm::Type *> arg_types = {llvm::Type::getInt8PtrTy(*context)};
            #else
            llvm::Type *int8Type = llvm::Type::getInt8Ty(*context);
            llvm::Type *int8PtrType = llvm::PointerType::get(int8Type, 0);
            std::vector<llvm::Type *> arg_types = {int8PtrType};
            #endif

            llvm::FunctionType *function_type = llvm::FunctionType::get(llvm::Type::getVoidTy(*context), arg_types, false);
            llvm::FunctionCallee print_function = module->getOrInsertFunction("print", function_type);

            //2 call the function
            llvm::Value *strPointer = builder->CreateGlobalStringPtr(arg);
            std::vector<llvm::Value *> args;
            args.push_back(strPointer);
            builder->CreateCall(print_function, args);
            std::cout << "test1" << std::endl;
        }
        return LuaBaseVisitor::visitFunctioncall(ctx);
    }
}





































