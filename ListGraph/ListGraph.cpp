#include "ListGraph.h"
#include <algorithm>

ListGraph::ListGraph( size_t count ): count(count) {
    nodes.resize(count);
}

void ListGraph::AddEdge( int from, int to ) {
    nodes[from].push_back(to);
}

ListGraph::ListGraph( const IGraph &IG ) {
    nodes.resize( IG.VerticesCount() );
    for ( size_t i = 0; i < count; ++i){
        nodes[i] = IG.GetNextVertices(i);
    }
}

std::vector<int> ListGraph::GetNextVertices( int vertex ) const {
    return nodes[vertex];
}

std::vector<int> ListGraph::GetPrevVertices( int vertex ) const {
    std::vector <int> out;
    for(size_t i = 0; i < count; ++i){
        std::for_each(nodes[i].begin(), nodes[i].end(), [&vertex, &out, &i](int a){ if (a == vertex) out.push_back(i); });
    }
    return out;
}

int ListGraph::VerticesCount() const {
    return count;
}


