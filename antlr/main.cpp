#include <antlr4-runtime.h>

#include <iostream>
#include <typeinfo>

#include "LuaBaseListener.h"
#include "LuaLexer.h"
#include "LuaParser.h"
#include "genir.h"

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