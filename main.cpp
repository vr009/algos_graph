#include <iostream>
#include <cassert>

#include "./ListGraph/ListGraph.h"
#include "./IGraph/IGraph_funcs.cpp"
#include "./MatrixGraph/MatrixGraph.h"
#include "./SetGraph/SetGraph.h"
#include "./ArcGraph/ArcGraph.h"
#include <ctime>

int main() {
    size_t n = 8;
    ListGraph list_g(n);
    list_g.AddEdge(0,1);
    list_g.AddEdge(0,2);
    list_g.AddEdge(0,5);
    list_g.AddEdge(1,3);
    list_g.AddEdge(5,7);
    list_g.AddEdge(6,3);
    list_g.AddEdge(2,7);
    list_g.AddEdge(3,4);

    auto func = [&](int a){ std::cout << a << std::endl;};
    std::cout << "==============ListGraph==========" << std::endl;
    dfs(list_g, func);
    std::cout << "=================================" << std::endl;
    bfs(list_g, func);

    std::cout << "==============SetGraph===========" << std::endl;
    SetGraph set_g(list_g);
    dfs(set_g, func);
    std::cout << "=================================" << std::endl;
    bfs(set_g, func);

    std::cout << "==============MatrixGraph========" << std::endl;
    MatrixGraph mat_g(set_g);
    dfs(mat_g, func);
    std::cout << "=================================" << std::endl;
    bfs(mat_g, func);

    std::cout << "==============ArcGraph===========" << std::endl;
    ArcGraph arc_g(set_g);
    dfs(arc_g, func);
    std::cout << "=================================" << std::endl;
    bfs(arc_g, func);
    std::cout << "=================================" << std::endl;


    for (size_t i = 0; i < n; ++i){
        auto a = list_g.GetNextVertices(i);
        auto b = set_g.GetNextVertices(i);
        auto c = mat_g.GetNextVertices(i);
        auto d = arc_g.GetNextVertices(i);

        assert( a == b && b == c && c == d);
        std::cout << "Next Vertices test " << i << "- ok" << std::endl;
    }

    std::cout << "==========================================" << std::endl;

    for (size_t i = 0; i < n; ++i){
        auto a = list_g.GetPrevVertices(i);
        auto b = set_g.GetPrevVertices(i);
        auto c = mat_g.GetPrevVertices(i);
        auto d = arc_g.GetPrevVertices(i);
        assert( a == b && b == c && c == d);
        std::cout << "Prev Vertices test " << i << "- ok" << std::endl;
    }
    return 0;
}
