#include <string>
#include <map>
#include <stack>
#include <iostream>
#include <cassert>

std::map<std::pair<size_t, char>, std::pair<char, size_t>> states = {
	{ { 0, '(' }, {'s', 1} },
	{ { 1, '1' }, {'s', 2} },
	{ { 2, ')' }, {'r', 3} }
};

size_t accept = 4;

bool parse(const std::string& str)
{
	std::stack<size_t> st;
	st.push(0);
	size_t state = 0;
	for (auto e : str) {
		state = st.top();
		auto it = states.find(std::make_pair(state, e));
		if (it == states.end()) { while (!st.empty()) { st.pop(); }; break; }
		if (it->second.first == 's') st.push(it->second.second);
		if (it->second.first == 'r') {
			while (!st.empty()) { st.pop(); };
			st.push(accept);
		}
	}
	if (!st.empty() && st.top() == accept) return true;
	return false;
}

int main()
{
	assert(parse("(1)"));
	assert(!parse("(0)"));
	return 0;
}
