#include "token.h"

const unordered_map<Token::Types, string> Token::token_map = {
	{Token::Types::VAR_NAME, "VAR_NAME"},
	{Token::Types::REM, "REM" },
	{Token::Types::INPUT, "INPUT" },
	{Token::Types::OUTPUT, "PRINT" },
	{Token::Types::GOTO, "GOTO" },
	{Token::Types::IF, "IF" },
	{Token::Types::LET, "LET" },
	{Token::Types::END, "END" },

};

Token::Types Token::get_type_by_name(string name)
{
	for (const auto& pair : token_map) {
		if (pair.second == name) {
			return pair.first;
		}
	}
	return Token::Types::UNKNOWN;
}

string Token::get_token_name(Token::Types type) {
	auto it = Token::token_map.find(type);
	if (it != Token::token_map.end()) {
		return it->second;
	}
	else {
		return "Unknown";
	}
}