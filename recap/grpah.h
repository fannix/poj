#ifndef __GRAPH_H
#define __GRAPH_H

class graph{
	public:
		virtual graph(int v) = 0;
		virtual insert_edge(edge e) = 0;
		virtual remove_edge(edge e) = 0;
}

#endif

/*
 * there is no abstract keyword in C++
 * just declare function to be virtual
 */
