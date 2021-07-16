#ifndef ALGOS_GRAPH_IGRAPH_H
#define ALGOS_GRAPH_IGRAPH_H
#include <vector>

struct IGraph {
    virtual ~IGraph() {}

    // Добавление ребра от from к to.
    virtual void AddEdge(int from, int to) = 0;

    virtual int VerticesCount() const  = 0;

    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};

template <class Callback>
void dfs_aux( const IGraph&, std::vector<bool> &, int , Callback callback);

template <class Callback>
void dfs( const IGraph&, Callback callback);


template <class Callback>
void bfs( const IGraph&, Callback callback);


#endif //ALGOS_GRAPH_IGRAPH_H
