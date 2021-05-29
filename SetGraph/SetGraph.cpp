#include "SetGraph.h"
#include <algorithm>

SetGraph::SetGraph(size_t count) : count(count) {
    nodes.resize(count);
}


SetGraph::SetGraph(const IGraph &IG) {
    count = IG.VerticesCount();
    for(size_t i = 0; i < IG.VerticesCount(); ++i){
        std::for_each(IG.GetNextVertices(i).begin(), IG.GetNextVertices(i).end(), [&]( int a ){ AddEdge( i, a ); });
    }
}

void SetGraph::AddEdge(int from, int to) {
    nodes[from].insert(to);
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    std::vector<int> out;
    std::copy(nodes[vertex].begin(), nodes[vertex].end(), std::back_inserter(out));
    return out;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> out;
    for( size_t i = 0; i < count; ++i){
        if( nodes[i].find(vertex) != nodes[i].end() ){
            out.push_back(i);
        }
    }
    return out;
}

int SetGraph::VerticesCount() const {
    return count;
}
