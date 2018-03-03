#include <map>
#include <vector>
#include <iostream>

typedef std::map<size_t, size_t> Graph;


std::vector<size_t> closure(const Graph& graph, size_t vertex)
{
	std::vector<size_t> vertices;
	std::vector<size_t> open;
	open.push_back(vertex);
	while (!open.empty()) {		
		auto adjV = graph.find(*open.begin());
		if (adjV != graph.end()) {
			vertices.push_back(adjV->second);
			open.push_back(adjV->second);
		}
		open.erase(open.begin());

	}
	return vertices;
}

int main()
{
	Graph graph = {
		{ 0,1 },
		{ 1,2 }
	};

	auto res = closure(graph, 0);
	for (auto const &e : res) {
		std::cout << e << std::endl;
	}
	return 0;
}
