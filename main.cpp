#include <iostream>
#include "./ListGraph/ListGraph.h"
#include "./IGraph/IGraph_funcs.cpp"
#include "./MatrixGraph/MatrixGraph.h"
#include "./SetGraph/SetGraph.h"
#include "./ArcGraph/ArcGraph.h"

int main() {
    size_t n = 8;
    ArcGraph graph(n + 1);

    for(size_t i = 0 ; i < n ; ++i){
        graph.AddEdge(i,i+1);
    }
    graph.AddEdge(0,5);


    auto func = [&](int a){ std::cout << a << std::endl;};

    dfs(graph, func);

    std::cout << "=================================" << std::endl;

    bfs(graph, func);

    return 0;
}
