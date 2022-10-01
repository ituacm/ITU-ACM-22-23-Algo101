#include <stack>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

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
    stack<int> dfs;
    dfs.push(1);
    while(!dfs.empty())
    {
        int current_node = dfs.top();
        dfs.pop();
        for(int x: adjacency_list[current_node])
        {
            if(!visited[x]) 
                dfs.push(x);
        }
        if(!visited[current_node])
        {
            visited[current_node] = true;
            cout << current_node << " ";
        }
    }    
    cout << endl;
    return 0;
}