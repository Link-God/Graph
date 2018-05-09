#include <catch.hpp>
#include <sstream>

#include "Graph.hpp"

TEST_CASE("Test_0")
{
	Graph graph({ { 1 },{ 0 ,2 , 6 },{ 1 ,4 , 5 },{ 6 },{ 2 } ,{ 2 },{ 1,3 } });
	graph.dfs();
	ostringstream stream;
	graph.return_result(stream);
	string out = "0 1 2 4 5 6 3 ";
	REQUIRE( out == stream.str() );
}

TEST_CASE("Test_1")
{
	Graph graph(7);
	vector< vector<unsigned> > in{ { 1 },{ 2,6 },{4,5}, {}, {} ,{}, {3} };
	graph.input(in);
	graph.dfs(0);
	ostringstream stream;
	graph.return_result(stream);
	string out = "0 1 2 4 5 6 3 ";
	REQUIRE( out == stream.str() );
}

TEST_CASE("Test_2")
{
	Graph graph({ { 1 },{0,2,6 },{1,4,5}, {6}, {2} ,{2}, {1,3} });
	graph.dfs(0);
	ostringstream stream;
	graph.return_result(stream);
	string out = "0 1 2 4 5 6 3 ";
	REQUIRE( out == stream.str() );
}

TEST_CASE("Test_3")
{
	Graph graph(9);
	vector< vector<unsigned> > in{ { 1 },{ 2,6 },{4,5}, {}, {} ,{}, {3}, {8},{} };
	graph.input(in);
	graph.dfs(0);
	ostringstream stream;
	graph.return_result(stream);
	string out = "0 1 2 4 5 6 3 ";
	REQUIRE( out == stream.str() );
}

TEST_CASE("Test_4")
{
	Graph graph(9);
	vector< vector<unsigned> > in{ { 1 },{ 2,6 },{4,5}, {}, {} ,{}, {3}, {8},{} };
	graph.input(in);
	graph.dfs(7);
	ostringstream stream;
	graph.return_result(stream);
	string out = "7 8 ";
	REQUIRE( out == stream.str() );
}

TEST_CASE("Test_5")
{
	Graph graph(9);
	vector< vector<unsigned> > in{ { 1 },{ 2,6 },{4,5}, {}, {} ,{}, {3}, {8},{} };
	graph.input(in);
	graph.dfs(8);
	ostringstream stream;
	graph.return_result(stream);
	string out = "8 ";
	REQUIRE( out == stream.str() );
}

TEST_CASE("Test_6")
{
	Graph graph(9);
	vector< vector<unsigned> > in{ { 1 },{0,2,6 },{1,4,5}, {6}, {2} ,{2}, {1,3}, {8}, {7} };
	graph.input(in);
	graph.dfs(8);
	ostringstream stream;
	graph.return_result(stream);
	string out = "8 7 ";
	REQUIRE( out == stream.str() );
}

TEST_CASE("Test_7")
{
	Graph graph(7);
	vector< vector<unsigned> > in{ { 1 },{ 2,6 },{4,5}, {}, {} };
	REQUIRE_THROWS_AS(graph.input(in),std::length_error);
}

TEST_CASE("Test_8")
{
	bool success=false;
	try{
		Graph graph( { {1, 10} } );
	}
	catch(std::length_error)
	{
		success=true;
	}
	REQUIRE(success);
}

TEST_CASE("Test_9")
{
	Graph graph({ { 1 },{ 0 ,2 , 6 },{ 1 ,4 , 5 },{ 6 },{ 2 } ,{ 2 },{ 1,3 } });
	ostringstream stream;
	graph.dfs();
	graph.return_result(stream);
	string out = "0 1 2 4 5 6 3 ";
	REQUIRE( out == stream.str() );
	graph.dfs(1);
	graph.return_result(stream);
	out = "1 0 2 4 5 6 3 ";
	REQUIRE( out == stream.str() );
}
