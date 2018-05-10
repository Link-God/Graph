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

void Graph::read_wihtout_N()
{
	//N++
	cout << "insert N" << endl;
	cin >> N;
	//N--
	//graph++
	for (unsigned i = 0; i < N; i++) {
		vector<unsigned> temp;
		string line;
			cout << "enter adjacent vertices separated by a space" << endl;// смежные вершины 
			cout << i << ":";
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

void Graph:: read_with_N()
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
		cout << "enter adjacent vertices separated by a space" << endl;// смежные вершины 
		cout << i << ":";
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

void Graph::read(istringstream & stream)
{
	string str;
	while (getline(stream, str))
	{
		istringstream stream(str);
		unsigned n;
		char op;
		if (stream >> n && stream >> op && op==':') {
			N = n + 1;
			int value;
			vector<unsigned> temp;
			while (stream >> value)
			{
				temp.push_back(value);
			}
			graph.push_back(temp);
		}
	}
	
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
	vector<bool> used;
	result.clear();
	for (unsigned i = 0; i < N; i++) {
		used.push_back(false);
	}
	dfs_help(index,&used);
}

void Graph::dfs_help(unsigned index , vector<bool> * used)
{
	(*used)[index] = true;
	result.push_back(index);
	for (const auto& i : graph[index])
	{
		if (!(*used)[i]) dfs_help(i,used);
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

void Graph::print_to_stream(ostream & stream)
{
	for (unsigned i = 0; i < N; i++) {
		stream << i << ":";
		for (const auto j : graph[i]) {
			stream << j << " ";
		}
		stream<< endl;
	}
}

void Graph::print_to_console()
{
	for (unsigned i = 0; i < N; i++) {
		cout << i << ":";
		for (const auto j : graph[i]) {
			cout << j << " ";
		}
		cout << endl;
	}
}
