#include "ArcGraph.h"
#include <algorithm>

ArcGraph::ArcGraph( size_t count ): count(count) {
    nodes.resize(count);
}

void ArcGraph::AddEdge( int from, int to ) {
    auto p = std::make_pair(from, to);
    if ( offset < count ) nodes.insert(nodes.begin() + offset, p);
    offset++;
}

ArcGraph::ArcGraph( const IGraph &IG ) : ArcGraph(IG.VerticesCount()) {

    for ( size_t i = 0; i < count; ++i){
        for(auto a: IG.GetNextVertices(i)){
            AddEdge(i, a);
        }
    }
}

std::vector<int> ArcGraph::GetNextVertices( int vertex ) const {
    std::vector<int> out;
    std::for_each(nodes.begin(), nodes.end(), [&](std::pair<int, int> a) { if(a.first == vertex){out.push_back(a.second);}; });
    return out;
}

std::vector<int> ArcGraph::GetPrevVertices( int vertex ) const {
    std::vector<int> out;
    std::for_each(nodes.begin(), nodes.end(), [&](std::pair<int, int> a) { if(a.second == vertex){out.push_back(a.first);}; });
    return out;
}

int ArcGraph::VerticesCount() const {
    return count;
}
