#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(size_t count) : count(count) {
    nodes.resize(count);
    for(size_t i = 0; i < count; ++i){
        nodes[i].resize(count);
    }
}


MatrixGraph::MatrixGraph(const IGraph &IG) : MatrixGraph(IG.VerticesCount()) {
    for(size_t i = 0; i < count; ++i){
        for(auto v: IG.GetNextVertices(i)){
            AddEdge( i , v );
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    if(from < count && to < count)
        nodes[from][to] = true;
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    if (vertex >= count)
        return std::vector<int>(0);

    std::vector<int> out;
    for(size_t v = 0; v < count; ++v){
        if(nodes[vertex][v])
            out.push_back(v);
    }
    return out;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    if (vertex >= count)
        return std::vector<int>(0);

    std::vector<int> out;
    for(size_t v = 0; v < count; ++v){
        if (nodes[v][vertex])
            out.push_back(v);
    }
    return out;
}

int MatrixGraph::VerticesCount() const {
    return count;
}
