#include "symbolStream.h"
#include <iostream>

Token TokenStream::get_token() {
	if (full) {
		full = false;
		return buffer;
	}

	char ch;
	while (stream.get(ch)) { 
		if (ch != ' ' && ch != '\t' && ch != '\r') {
			break;
		}
	}

	if (stream.eof() || !stream) {
		return Token(Token::EXIT_FLAG);
	}

	switch (ch) {
	case '\n':
		return Token(Token::EXPRESSION_END_FLAG);
	case '(':
	case ')':
	case '=':
	case '+':
	case '-':
	case '>':
	case '<':
	case '*':
	case '/':
		return Token(static_cast<Token::Types>(ch));
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		stream.putback(ch);
		int val;
		stream >> val;
		return Token(Token::Types::NUMBER, val);
	}

	default:
		if (isalpha(ch)) {
			stream.putback(ch);

			std::string s;
			while (stream.get(ch) && (isalpha(ch) || isdigit(ch)))
				s += ch;
			stream.putback(ch);

			Token::Types token_type = Token::get_type_by_name(s);
			if (token_type != Token::UNKNOWN) {
				prev_type = token_type;
				return Token(token_type);
			}

			switch (prev_type) {
				case Token::INPUT:
				case Token::OUTPUT:
				case Token::LET:
				case Token::IF:
				{
					return Token(Token::Types::VAR_NAME, s);
				}
			}

			return Token(Token::UNKNOWN, s);
		}
		else {
			throw runtime_error("Bad token");
		}
	}
}

void TokenStream::put_back(Token t) {
	if (full) {
		throw runtime_error("put_back() into full buffer");
	}
	buffer = t;
	full = true;
}

void TokenStream::ignore() {
	Token t = get_token();
	while (t.type != Token::EXPRESSION_END_FLAG &&
		   t.type != Token::EXIT_FLAG) t = get_token();
}