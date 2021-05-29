#ifndef ALGOS_GRAPH_SETGRAPH_H
#define ALGOS_GRAPH_SETGRAPH_H
#include <vector>
#include <set>

#include "../IGraph/IGraph.h"

struct SetGraph: IGraph {
    SetGraph( size_t );
    SetGraph( const IGraph &);
    virtual ~SetGraph() = default;
    int VerticesCount() const override ;
    void AddEdge(int from, int to) override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override ;


    bool empty(){
        return nodes.empty();
    }

private:
    std::vector<std::set<int>> nodes;
    size_t count;
};



#endif //ALGOS_GRAPH_SETGRAPH_H
