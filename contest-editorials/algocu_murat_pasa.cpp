// including all libraries (not necessary, can only include <vector> and <iostream>)
#include <bits/stdc++.h>
// long long is required (10^18) since our numbers are in range of 10^9 and we have up to 10^6 numbers
// defining it as a macro so it is easier to write
#define ll long long
using namespace std;

// solve algorithm, O(n) complexity
int solve(vector<ll> &recruits, vector<ll> &losses)
{
    // to save total for checking soldiers - losses
    ll total = 0;
    // to save current index
    ll index = 0;
    // to save how many soldiers do murat pasa has right now
    ll current_soldiers = 0;

    for (int i = 0; i < recruits.size(); i++)
    {
        // taking the difference since murat pasa will arrive here, take recruits and will lose soldiers
        ll differance = recruits[i] - losses[i];
        // increasing the total and current_soldiers with difference
        total += differance;
        current_soldiers += differance;
        // if we reach zero, we can't start from the index
        if (current_soldiers < 0)
        {
            // so sry again starting from the next index
            index = i + 1;
            current_soldiers = 0;
        }
    }
    // if number of losses > recruits, this task is impossible
    if (total < 0)
    {
        return -1;
    }
    // othervise this task is possible since we didn't have problems starting from the index
    // and previously false conditions would be true since recruits >= losses
    return index;
}

int main()
{
    // taking the inputs, remember ll = long long
    int n;
    scanf("%d", &n);
    vector<ll> recruits(n);
    vector<ll> losses(n);
    for (int i = 0; i < n; i++)
    {
        int read;
        scanf("%d", &read);
        recruits[i] = read;
    }
    for (int i = 0; i < n; i++)
    {
        int read;
        scanf("%d", &read);
        losses[i] = read;
    }
    // calling the solve function
    int result = solve(recruits, losses);
    printf("%d\n", result);

    return 0;
}
