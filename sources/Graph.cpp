#include"Graph.hpp"

Graph::Graph()
{
	N = 0;
}

Graph::Graph(vector < vector<unsigned> > in)
{
	//
	for (unsigned i = 0; i < in.size(); i++) {
		for (const auto& j : in[i]){
			if (j >= in.size()) throw length_error("fail");
		}
	}
	//
	//graph++
	graph = in;
	//graph--
	N = graph.size();
}

Graph::Graph(unsigned n)
{
	N = n;
}

void Graph:: read()
{
	if (N == 0)
	{
		throw logic_error("zero");
		return;
	}
	//graph++
	for (unsigned i = 0; i < N; i++) {
		vector<unsigned> temp;
		string line;
	//	cout << "enter adjacent vertices separated by a space" << endl;// смежные вершины 
	//	cout << i << ":";
		getline(cin, line);
		istringstream stream(line);
		int value;
		while (stream >> value)
		{
			temp.push_back(value);
		}
		graph.push_back(temp);
	}
	//graph--
	//result ++ --
}

Graph::~Graph()
{
	N = 0;
}

Graph::Graph(Graph & other)
{
	N = other.N;
	graph = other.graph;
	if (!(other.result.empty())) result = other.result;
}

Graph Graph::operator = (Graph & other)
{
	if (this != &other) {
		N = other.N;
		graph = other.graph;
		if (!other.result.empty()) result = other.result;
	}
	return (*this);
}

void Graph::dfs(unsigned index)
{
	//used++
	vector<bool> used;
	for (unsigned i = 0; i < N; i++) {
		used.push_back(false);
	}
	//used--  
	used[index] = true;
	result.push_back(index);
	for (const auto& i : graph[index])
	{
		if (!used[i])
			dfs(i);
	}
}

void Graph::dfs()
{
	unsigned index = 0;
	dfs(index);
}

void Graph::return_result(ostream & stream)
{
	for (unsigned i : result) stream << i << " ";
}

void Graph::set_vertices(unsigned count)
{
	N = count;
}

void Graph::input(vector < vector<unsigned> >& in)
{
	if (in.size() != N)
	{
		throw std::length_error("length error");
		return;
	}
	//graph++
	graph = in;
	//graph--
	//result ++ --
}
