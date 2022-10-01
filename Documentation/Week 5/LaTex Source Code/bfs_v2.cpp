#include <queue>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    vector<vector<int>> adjacency_list = {
        {},
        {2, 7, 6},
        {3, 7, 1},
        {4, 7, 2},
        {5, 7, 3},
        {6, 7, 4},
        {1, 7, 5},
        {1, 2, 3, 4, 5, 6}};
    unordered_map<int, bool> visited;
    queue<pair<int, int>> bfs; // First : node
    bfs.push(make_pair(1, 1)); // Second: level
    visited[1] = true;
    while (!bfs.empty())
    {
        int current_node = bfs.front().first;
        int current_level = bfs.front().second;
        for (int x : adjacency_list[current_node])
        {
            if (!visited[x])
            {
                bfs.push(make_pair(x, current_level + 1));
                visited[x] = true;
            }
        }
        bfs.pop();
        cout << current_node << " " << current_level << endl;
    }
    return 0;
}