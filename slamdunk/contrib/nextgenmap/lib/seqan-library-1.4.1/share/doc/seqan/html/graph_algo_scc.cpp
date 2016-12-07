#include <iostream>
#include <seqan/graph_algorithms.h>

using namespace seqan;


int main() {
	typedef Graph<Directed<> > TGraph;
	typedef VertexDescriptor<TGraph>::Type TVertexDescriptor;
	typedef EdgeDescriptor<TGraph>::Type TEdgeDescriptor;
	typedef Size<TGraph>::Type TSize;
	TSize numEdges = 14;
	TVertexDescriptor edges[] = {1,0, 0,4, 2,1, 4,1, 5,1, 6,2, 3,2, 2,3, 7,3, 5,4, 6,5, 5,6, 7,6, 7,7};
	TGraph g;
	addEdges(g, edges, numEdges);
	std::cout << g << std::endl;
	String<char> nameMap;
	char names[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	assignVertexMap(g,nameMap, names);
	String<unsigned int> component;
	stronglyConnectedComponents(g, component);
	std::cout << "Strongly Connected Components: " << std::endl;
	typedef Iterator<TGraph, VertexIterator>::Type TVertexIterator;
	TVertexIterator it(g);
	while(!atEnd(it)) {
		std::cout << "Vertex " << getProperty(nameMap, getValue(it)) << ": ";
		std::cout << "Component = " << getProperty(component, getValue(it)) << std::endl;
		goNext(it);
	}
	return 0;
}