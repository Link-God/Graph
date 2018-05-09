#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include <stdexcept>

using namespace std;

class Graph {
private:
	vector < vector<unsigned> > graph;
	vector<bool> used;
	vector<unsigned> result;
	unsigned N;
public:
	Graph();
	Graph(vector < vector<unsigned> > in);
	Graph(unsigned n);
	void read();
	~Graph();
	Graph(Graph & other);
	Graph operator = (Graph & other);
	void dfs(unsigned index);
	void dfs();
	void return_result(ostream & stream);
	void set_vertices(unsigned count);
	void input(vector < vector<unsigned> > & in);
};
