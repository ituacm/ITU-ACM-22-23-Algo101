#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list = {{},
{6},
{3,5},
{1,4},
{6},
{4,7},
{7},
{},
};

void topSort(int node, vector<vector<int>>& adj_list, unordered_map<int, bool>& visited, stack<int>& top_sort_stack)
{
    visited[node] = true;
    for(int x : adj_list[node])
    {
        if(!visited[x])
            topSort(x, adj_list, visited, top_sort_stack);
    }
    top_sort_stack.push(node);
    return;
}

int main()
{
    unordered_map<int, bool> visited;
    stack<int> top_sort_stack;
    for(int i = 1; i < adj_list.size(); i++)
    {
        if(!visited[i])
            topSort(i, adj_list, visited, top_sort_stack);
    }
    while(!top_sort_stack.empty())
    {
        cout << top_sort_stack.top() << " ";
        top_sort_stack.pop();
    }
    cout << endl;
    return 0;
}
