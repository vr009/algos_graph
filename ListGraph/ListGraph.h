#ifndef ALGOS_GRAPH_LISTGRAPH_H
#define ALGOS_GRAPH_LISTGRAPH_H

#include "../IGraph/IGraph.h"
#include <vector>


struct ListGraph: IGraph {
    ListGraph( size_t );
    ListGraph( const IGraph &);
    virtual ~ListGraph() = default;
    int VerticesCount() const override ;
    void AddEdge(int from, int to) override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override ;




    bool empty(){
        return nodes.empty();
    }

private:
    std::vector<std::vector<int>> nodes;
    size_t count;
};

#endif //ALGOS_GRAPH_LISTGRAPH_H
