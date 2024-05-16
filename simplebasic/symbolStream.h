#pragma once
#include "token.h"
#include <istream>

class TokenStream
{
private:
  istream stream;
  bool full;
  Token::Types prev_type;
  Token buffer;

public:
  TokenStream (istream &str)
      : stream (str.rdbuf ()), prev_type (Token::UNKNOWN), full (false),
        buffer (Token::EXIT_FLAG){};
  Token get_token ();
  void put_back (Token t);
  void ignore ();
};