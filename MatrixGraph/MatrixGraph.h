#ifndef ALGOS_GRAPH_MATRIXGRAPH_H
#define ALGOS_GRAPH_MATRIXGRAPH_H
#include "../IGraph/IGraph.h"

struct MatrixGraph: IGraph {
    MatrixGraph( size_t );
    MatrixGraph( const IGraph &);
    virtual ~MatrixGraph() = default;
    int VerticesCount() const override ;
    void AddEdge(int from, int to) override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override ;


    bool empty(){
        return nodes.empty();
    }

private:


    std::vector<std::vector<bool>> nodes;
    size_t count;
};


#endif //ALGOS_GRAPH_MATRIXGRAPH_H
