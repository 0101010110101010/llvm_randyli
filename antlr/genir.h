#pragma once
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "LuaParser.h"
#include "LuaBaseVisitor.h"

namespace luac
{
    class IRGenerator : public LuaBaseVisitor
    {
        public:
        IRGenerator(const char * name)
        {
            context = std::make_unique<llvm::LLVMContext>();
            module = std::make_unique<llvm::Module>(name, *context);
            builder = std::make_unique<llvm::IRBuilder<>>(*context);
        }

        antlrcpp::Any visitFunctioncall(LuaParser::FunctioncallContext *ctx) override;
        antlrcpp::Any visitChunk(LuaParser::ChunkContext *ctx) override;
        void dump() {module->print(llvm::errs(), nullptr);};

        private:
        std::unique_ptr<llvm::LLVMContext> context;
        std::unique_ptr<llvm::Module> module;
        std::unique_ptr<llvm::IRBuilder<>> builder;
    };
}