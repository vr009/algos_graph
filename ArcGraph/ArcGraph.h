#ifndef ALGOS_GRAPH_ARCGRAPH_H
#define ALGOS_GRAPH_ARCGRAPH_H

#include "../IGraph/IGraph.h"
#include <vector>

struct ArcGraph: IGraph {
    ArcGraph( size_t );
    ArcGraph( const IGraph &);
    virtual ~ArcGraph() = default;
    int VerticesCount() const override ;
    void AddEdge(int from, int to) override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override ;


    bool empty(){
        return nodes.empty();
    }

private:
    std::vector<std::pair<int, int>> nodes;
    size_t count;
};

#endif //ALGOS_GRAPH_ARCGRAPH_H
