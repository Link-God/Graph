#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include <stdexcept>

using namespace std;

class Graph {
private:
	vector < vector<unsigned> > graph;
	vector<unsigned> result;
	unsigned N;	
	void dfs_help(unsigned index, vector<bool> * used);
public:
	Graph();
	Graph(vector < vector<unsigned> > in);
	Graph(unsigned n);
	void read_with_N();
	void read_wihtout_N();
	void read(istringstream & stream);
	~Graph();
	Graph(Graph & other);
	Graph operator = (Graph & other);
	void dfs(unsigned index);
	void dfs();
	void return_result(ostream & stream);
	void set_vertices(unsigned count);
	void input(vector < vector<unsigned> > & in);
	void print_to_console();
	void print_to_stream(ostream & stream);
};
