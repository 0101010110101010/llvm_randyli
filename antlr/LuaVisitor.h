
// Generated from Lua.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "LuaParser.h"


namespace luac {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by LuaParser.
 */
class  LuaVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by LuaParser.
   */
    virtual antlrcpp::Any visitChunk(LuaParser::ChunkContext *context) = 0;

    virtual antlrcpp::Any visitBlock(LuaParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitStat(LuaParser::StatContext *context) = 0;

    virtual antlrcpp::Any visitAttnamelist(LuaParser::AttnamelistContext *context) = 0;

    virtual antlrcpp::Any visitAttrib(LuaParser::AttribContext *context) = 0;

    virtual antlrcpp::Any visitRetstat(LuaParser::RetstatContext *context) = 0;

    virtual antlrcpp::Any visitLabel(LuaParser::LabelContext *context) = 0;

    virtual antlrcpp::Any visitFuncname(LuaParser::FuncnameContext *context) = 0;

    virtual antlrcpp::Any visitVarlist(LuaParser::VarlistContext *context) = 0;

    virtual antlrcpp::Any visitNamelist(LuaParser::NamelistContext *context) = 0;

    virtual antlrcpp::Any visitExplist(LuaParser::ExplistContext *context) = 0;

    virtual antlrcpp::Any visitExp(LuaParser::ExpContext *context) = 0;

    virtual antlrcpp::Any visitPrefixexp(LuaParser::PrefixexpContext *context) = 0;

    virtual antlrcpp::Any visitFunctioncall(LuaParser::FunctioncallContext *context) = 0;

    virtual antlrcpp::Any visitVarOrExp(LuaParser::VarOrExpContext *context) = 0;

    virtual antlrcpp::Any visitVar_(LuaParser::Var_Context *context) = 0;

    virtual antlrcpp::Any visitVarSuffix(LuaParser::VarSuffixContext *context) = 0;

    virtual antlrcpp::Any visitNameAndArgs(LuaParser::NameAndArgsContext *context) = 0;

    virtual antlrcpp::Any visitArgs(LuaParser::ArgsContext *context) = 0;

    virtual antlrcpp::Any visitFunctiondef(LuaParser::FunctiondefContext *context) = 0;

    virtual antlrcpp::Any visitFuncbody(LuaParser::FuncbodyContext *context) = 0;

    virtual antlrcpp::Any visitParlist(LuaParser::ParlistContext *context) = 0;

    virtual antlrcpp::Any visitTableconstructor(LuaParser::TableconstructorContext *context) = 0;

    virtual antlrcpp::Any visitFieldlist(LuaParser::FieldlistContext *context) = 0;

    virtual antlrcpp::Any visitField(LuaParser::FieldContext *context) = 0;

    virtual antlrcpp::Any visitFieldsep(LuaParser::FieldsepContext *context) = 0;

    virtual antlrcpp::Any visitOperatorOr(LuaParser::OperatorOrContext *context) = 0;

    virtual antlrcpp::Any visitOperatorAnd(LuaParser::OperatorAndContext *context) = 0;

    virtual antlrcpp::Any visitOperatorComparison(LuaParser::OperatorComparisonContext *context) = 0;

    virtual antlrcpp::Any visitOperatorStrcat(LuaParser::OperatorStrcatContext *context) = 0;

    virtual antlrcpp::Any visitOperatorAddSub(LuaParser::OperatorAddSubContext *context) = 0;

    virtual antlrcpp::Any visitOperatorMulDivMod(LuaParser::OperatorMulDivModContext *context) = 0;

    virtual antlrcpp::Any visitOperatorBitwise(LuaParser::OperatorBitwiseContext *context) = 0;

    virtual antlrcpp::Any visitOperatorUnary(LuaParser::OperatorUnaryContext *context) = 0;

    virtual antlrcpp::Any visitOperatorPower(LuaParser::OperatorPowerContext *context) = 0;

    virtual antlrcpp::Any visitNumber(LuaParser::NumberContext *context) = 0;

    virtual antlrcpp::Any visitString(LuaParser::StringContext *context) = 0;


};

}  // namespace luac
