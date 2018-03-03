#include <string>
#include <map>
#include <stack>
#include <iostream>

std::map<std::pair<size_t, char>, size_t> states = {
	{{0, 'a'}, 1},
	{{1, 'b'}, 2},
	{{2, 'c'}, 3}
};

bool scan(const std::string& str)
{
	std::stack<size_t> st;
	st.push(0);
	size_t state = 0;
	for (auto e : str) {
		state = st.top();
		auto it = states.find(std::make_pair(state, e));		
		if (it == states.end()) { st.pop(); break;}
		st.pop();
		st.push(it->second);
	}
	if (!st.empty() && st.top() == 3) return true;
	return false;
}

int main()
{
	std::cout << scan("abc") << std::endl;
	std::cout << scan("abcc") << std::endl;
	return 0;
}
