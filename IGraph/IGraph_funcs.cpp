#include "IGraph.h"
#include <stack>
#include <algorithm>
#include <queue>

template<class Callback>
void dfs_aux_recur( const IGraph& graph, std::vector<bool>& visited, int v, Callback callback){
    visited[v] = true;
    callback(v);
    std::vector<int> children = graph.GetNextVertices(v);
    for( auto child: children){
        if(!visited[ child ]){
            dfs_aux(graph, visited, child, callback);
        }
    }
}
template<class Callback>
void dfs_aux( const IGraph& graph, std::vector<bool>& visited, int v, Callback callback){
    std::stack<int, std::vector<int>> work_stack;
    visited[ v ] = true;
    callback( v );
    for( auto child: graph.GetNextVertices( v ) ){
        work_stack.push(child);
        while(!work_stack.empty()){
            if (!visited[ work_stack.top() ]) callback(work_stack.top());
            visited[ work_stack.top() ] = true;
            auto v_t = work_stack.top();
            work_stack.pop();
            for(auto c: graph.GetNextVertices(v_t)){
                if(!visited[c])
                    work_stack.push(c);
            }
            //std::for_each(graph.GetNextVertices(v_t).begin(),graph.GetNextVertices(v_t).end(), [&]( int &a){ if ( !visited[a] ) work_stack.push(a); } );
        }
    }
}

template<class Callback>
void dfs( const IGraph& graph, Callback callback){
    std::vector<bool> visited(graph.VerticesCount(), false);
    for(size_t v = 0; v < graph.VerticesCount() ; ++v){
        if(!visited[v]){
            dfs_aux(graph, visited, v, callback);
        }
    }
}



template <class Callback>
void bfs( const IGraph& graph, Callback callback){
    std::queue<int> work_queue;
    std::vector<bool> visited(graph.VerticesCount(), false);
    for(size_t v = 0; v < graph.VerticesCount(); ++v){
        if(!visited[v]){
            visited[v] = true;
            work_queue.push(v);
            while (!work_queue.empty()){
                auto current = work_queue.front();
                work_queue.pop();
                callback( current );
                std::vector<int> children = graph.GetNextVertices(current);
                for(auto child : children){
                    if(!visited[child]){
                        visited[child] = true;
                        work_queue.push(child);
                    }
                }
            }
        }
    }
}