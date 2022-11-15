/*
Question Link: https://www.hackerrank.com/contests/itu-acm-algo-101-contest-22-23/challenges/the-city-of-g

The problem statement says that both ways should be checked, for this reason, the "compute" function is implemented. 
It is called twice, once with _reverse parameter as true and once as false. Obviously, with it set as true, the input 
is going through a reversion process. Thus we can solve the problem only for one direction.

In the implementation below in the "compute" function boys are running to the right, i.e. from 0 to n-1. "a" is the 
position of the faster one, and "b" is of the slower one. "b" is incremented every two seconds, while for "a" two pointers 
are calculating the next position, updated every second. 

"p1" saves position to the farthest monument "a" boy can jump to, while "p2" linearly searches for possible landing spots. 
When the monument of "p2" has the same altitude as the one at "p1", "p1" is updated to be "p2", since it is desired to go 
as far as possible. Besides jumping over a couple of monuments, "a" boy can simply jump to the next one. To decide which 
one is better the maximum between "p2" and "a+1" is taken and assigned to "a". This is how "a" moves at every iteration.

If after one iteration "b" becomes more than or equal to n, this means that "b" has escaped the street. However if "a" 
becomes more than or equal to "b", "b" is caught. The function returns true and false respectively.

*/


#include <bits/stdc++.h>

using namespace std;

bool compute(int a, int b, vector<int>& m, bool _reverse) {
    int n = m.size();
    if (_reverse) {
        a = n-a-1;
        b = n-b-1;
        swap(a, b);
        reverse(m.begin(), m.end());
    }
    int time = 1, p1, p2;
    
    while (true) {
        if (time % 2 == 0) b++;
        
        p1 = a;
        p2 = a+1;
        while (p2 < n && m[p2] <= m[p1]) {
            if (m[p1] == m[p2]) p1 = p2;
            p2++;
        } 
        a = max(a+1, p1);
        time++;
    
        if (b >= n) return true;
        if (a >= b) return false;
    }
}

int main() {
	int n, x, y;
    cin >> n >> x >> y;
    vector<int> monuments(n);
    
    for (int i = 0; i < n; i++) 
        cin >> monuments[i];

    if (x > y) swap(x, y);
    
    if (compute(x, y, monuments, false) && 
    compute(x, y, monuments, true)) {
        cout << "Yes" << endl;
   	else 
        cout << "No" << endl;
  
    return 0;
}

