#include <iostream>
#include <cassert>

#include "./ListGraph/ListGraph.h"
#include "./IGraph/IGraph_funcs.cpp"
#include "./MatrixGraph/MatrixGraph.h"
#include "./SetGraph/SetGraph.h"
#include "./ArcGraph/ArcGraph.h"


int main() {
    size_t n = 8;
    ListGraph graph(n + 1);

    for(size_t i = 0 ; i < n ; ++i){
        graph.AddEdge(i,i+1);
    }
    graph.AddEdge(0,5);

    auto func = [&](int a){ std::cout << a << std::endl;};

    dfs(graph, func);
    std::cout << "=================================" << std::endl;
    bfs(graph, func);
    std::cout << "=================================" << std::endl;

    SetGraph set_g(graph);
    dfs(set_g, func);
    std::cout << "=================================" << std::endl;
    bfs(set_g, func);
    std::cout << "=================================" << std::endl;


    MatrixGraph mat_g(set_g);
    dfs(mat_g, func);
    std::cout << "=================================" << std::endl;
    bfs(mat_g, func);
    std::cout << "=================================" << std::endl;

    ArcGraph arc_g(set_g);
    dfs(arc_g, func);
    std::cout << "=================================" << std::endl;
    bfs(arc_g, func);
    std::cout << "=================================" << std::endl;



    return 0;
}
