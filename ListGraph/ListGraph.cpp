#include "ListGraph.h"

ListGraph::ListGraph( size_t count ) {
    nodes.resize(count);
}

void ListGraph::AddEdge( int from, int to ) {}

ListGraph::ListGraph( const IGraph &IG ) {}

std::vector<int> ListGraph::GetNextVertices( int vertex ) const {}

std::vector<int> ListGraph::GetPrevVertices( int vertex ) const {}

ListGraph::~ListGraph() noexcept {}

int ListGraph::VerticesCount() const {}
