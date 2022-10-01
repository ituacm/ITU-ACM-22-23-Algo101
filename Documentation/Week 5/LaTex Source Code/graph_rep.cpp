#include <vector>
using namespace std;

vector<vector<bool>> adjacency_matrix = {{},
    {false, true, false, true},
    {true, false, true, false},
    {false, true, false, true},
    {true, false, true, false}};
// You can determine a distinct value for unconnected
vector<vector<int>> adjacency_matrix_w = {{},
    {-1, 2, -1, 8},
    {2, -1, 4, -1},
    {-1, 4, -1, 6},
    {8, -1, 6, -1}};

vector<vector<int>> adjacency_list = {{},
    {2, 4},
    {1, 3},
    {2, 4},
    {1, 3}};
vector<vector<pair<int, int>>> adjacency_list_w = {{},
    {{2,2}, {4,8}},
    {{1,2}, {3,4}},
    {{2,4}, {4,6}},
    {{1,8}, {3,6}}};

int main()
{
    return 0;
}