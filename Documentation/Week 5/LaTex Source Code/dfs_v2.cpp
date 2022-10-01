#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void dfs(int current_node, 
         vector<vector<int>>& adjacency_list, 
         unordered_map<int, bool>& visited);

int main()
{
    vector<vector<int>> adjacency_list = {
        {},
        {2, 3, 4, 5},
        {1, 6},
        {1, 4},
        {1, 3, 5},
        {1, 4, 7},
        {2},
        {5}};
    unordered_map<int, bool> visited;
    dfs(1, adjacency_list, visited); 
    cout << endl;
    return 0;
}

void dfs(int current_node, 
         vector<vector<int>>& adjacency_list, 
         unordered_map<int, bool>& visited)
{
    visited[current_node] = true;
    cout << current_node << " ";
    for(int x : adjacency_list[current_node])
    {
        if(!visited[x])
            dfs(x, adjacency_list, visited);
    }
}