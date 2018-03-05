#include <string>
#include <iostream>
#include <algorithm>

struct scanner_state
{
	std::string::const_iterator current;
	std::string::const_iterator end;

	bool eof() const { return current == end; }

	scanner_state(const std::string& s):current(s.begin()), end(s.end()) {}

};

bool isbracket(char c) {
	return c == '{' || c == '}';
}

std::string getNextToken(scanner_state& state)
{
	if (!state.eof() && isspace(*state.current)) {
		auto token_end = std::find_if_not(state.current, state.end, isspace);
		state.current = token_end;
	}
	if (!state.eof() && isalpha(*state.current)) {
		auto token_end = std::find_if_not(state.current, state.end, isalpha);
		std::string token = std::string(state.current, token_end);
		state.current = token_end;		
		return token;
	}
	if (!state.eof() && isbracket(*state.current)) {
		auto token_end = state.current + 1;
		std::string token = std::string(state.current, token_end);
		state.current = state.current + 1;
		return token;
	}
	return "";
}

int main()
{
	std::string input = "program {}";
	while ()
	return 0;
}