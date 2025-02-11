
// Generated from Lua.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "LuaVisitor.h"


namespace luac {

/**
 * This class provides an empty implementation of LuaVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  LuaBaseVisitor : public LuaVisitor {
public:

  virtual antlrcpp::Any visitChunk(LuaParser::ChunkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(LuaParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStat(LuaParser::StatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAttnamelist(LuaParser::AttnamelistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAttrib(LuaParser::AttribContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRetstat(LuaParser::RetstatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLabel(LuaParser::LabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncname(LuaParser::FuncnameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarlist(LuaParser::VarlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamelist(LuaParser::NamelistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExplist(LuaParser::ExplistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExp(LuaParser::ExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrefixexp(LuaParser::PrefixexpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctioncall(LuaParser::FunctioncallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarOrExp(LuaParser::VarOrExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar_(LuaParser::Var_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarSuffix(LuaParser::VarSuffixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNameAndArgs(LuaParser::NameAndArgsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgs(LuaParser::ArgsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctiondef(LuaParser::FunctiondefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncbody(LuaParser::FuncbodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParlist(LuaParser::ParlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableconstructor(LuaParser::TableconstructorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFieldlist(LuaParser::FieldlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitField(LuaParser::FieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFieldsep(LuaParser::FieldsepContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperatorOr(LuaParser::OperatorOrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperatorAnd(LuaParser::OperatorAndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperatorComparison(LuaParser::OperatorComparisonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperatorStrcat(LuaParser::OperatorStrcatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperatorAddSub(LuaParser::OperatorAddSubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperatorMulDivMod(LuaParser::OperatorMulDivModContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperatorBitwise(LuaParser::OperatorBitwiseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperatorUnary(LuaParser::OperatorUnaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperatorPower(LuaParser::OperatorPowerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber(LuaParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitString(LuaParser::StringContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace luac
