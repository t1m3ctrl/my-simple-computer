#pragma once
#include <string>
#include <unordered_map>

using namespace std;

class Token
{
public:
  enum Types
  {
    NUMBER = '0',

    VAR_NAME,

    REM,
    INPUT,
    OUTPUT,
    GOTO,
    IF,
    LET,
    END,

    OP_PLUS = '+',
    OP_MINUS = '-',
    OP_MULT = '*',
    OP_DIVIDE = '/',
    OP_EQUAL = '=',
    OP_POWER = '^',
    OP_GT = '>',
    OP_LESS = '<',

    OPEN_BRACKET = '(',
    CLOSING_BRACKET = ')',

    EXIT_FLAG = 'q',
    EXPRESSION_END_FLAG = '\n',

    UNKNOWN = -1,
  };

  Types type;
  int value;
  string str_val;

  Token (Types t, int val) : type (t), value (val){};
  Token (Types t) : type (t), value (0){};
  Token (Types t, string n) : type (t), str_val (n), value (0){};

  static const unordered_map<Types, string> token_map;
  static string get_token_name (Types type);
  static Types get_type_by_name (string name);

  bool
  is_operator () const
  {
    return type == OP_PLUS || type == OP_MINUS || type == OP_MULT
           || type == OP_DIVIDE;
  }

  int
  precedence () const
  {
    switch (type)
      {
      case OPEN_BRACKET:
      case CLOSING_BRACKET:
        return -1;
      case OP_MULT:
      case OP_DIVIDE:
        return 2;
      case OP_PLUS:
      case OP_MINUS:
        return 1;
      default:
        return 0;
      }
  }

  bool
  operator== (const Token &other) const
  {
    return this->type == other.type;
  }
};