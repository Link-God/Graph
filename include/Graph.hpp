#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

class Graph {
private:
	vector < vector<unsigned> > graph;
	vector<bool> used;
	vector<unsigned> result;
	unsigned N;
public:
	Graph();
	Graph(unsigned n);
	void read();
	~Graph();
	Graph(Graph & other);
	Graph operator = (Graph & other);
	void dfs(unsigned index);
	void return_result(ostream & stream);
	void set_vertices(unsigned count);
};
