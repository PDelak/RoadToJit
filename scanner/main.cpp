#include <string>
#include <algorithm>
#include <iostream>


struct scanning_state
{
	scanning_state(const std::string& input) :current(input.begin()), end(input.end()) {}
	std::string::const_iterator current;
	std::string::const_iterator end;
	bool eof() const { return current == end; }
};

bool isbracket(char c) {
	return c == '(' || c == ')';
}

std::string getNextToken(scanning_state& state)
{
	if (!state.eof() && isspace(*state.current)) {
		auto end = std::find_if_not(state.current, state.end, isspace);
		state.current = end;
	}
	if (!state.eof() && isalpha(*state.current)) {
		auto token_end = std::find_if_not(state.current, state.end, isalpha);
		std::string token = std::string(state.current, token_end);
		state.current = token_end;

		return token;
	}
	if (!state.eof() && isdigit(*state.current)) {
		auto token_end = std::find_if_not(state.current, state.end, isdigit);
		std::string token = std::string(state.current, token_end);
		state.current = token_end;

		return token;
	}

	if (!state.eof() && isbracket(*state.current)) {
		auto token_end = state.current + 1;
		std::string token = std::string(state.current, token_end);
		state.current = token_end;
		return token;
	}
	return "";
}

int main()
{
	std::string input = "    (1) ";
	scanning_state state(input);
	std::string token = getNextToken(state);
	while(!token.empty()) {
		std::cout << "token:" << token << std::endl;
		token = getNextToken(state);
	} 
	return 0;
}

