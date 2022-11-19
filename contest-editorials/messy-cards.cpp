/*
 * Question Link: https://www.hackerrank.com/contests/itu-acm-algo-101-contest-22-23/challenges/messy-cards
 *
 * Before diving into the solution, let's look at the constraints:
 * 0 <= N, card numbers, Q <= 10^6
 *
 * This should tell us that if we used an algorithm that runs in O(N * Q), it would exceed the time limit.
 * Hence, using linear search for every query is out of the question.
 *
 * What are the alternatives though?
 * We know for sure that our deck consists of two sorted arrays. This fact should remind us of binary search.
 * If we used binary search for each query, time complexity would be O(Q * logN) which is quite efficient.
 */

#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& arr, int target) {
    /*
     * This function utilizes the logic of binary search with a little twist:
     * 
     * Let's assume that the rotation index is i, i.e. arr[i] > arr[high] and arr[i] > arr[low], i.e. maximum element of the array.
     * 
     * If i >= mid index, left half of the array is sorted. This means that arr[mid] >= arr[low].
     * If our target value is somewhere in between arr[mid] and arr[low], we can perform regular binary search.
     * If not, we can continue searching in the interval (mid+1, high).
     * 
     * If arr[mid] < arr[low], it means that the right half is sorted.
     * In this case, if target value is less than arr[high], we can perform regular binary search in the interval (mid+1, high).
     * If not, we can set high value to mid-1.
     */

    int n = arr.size();

    int low = 0, high = n-1;

    long int mid = -1;

    while(low <= high){

        mid = (high+low)/2;

        if(arr[mid] == target) {
            return  mid;
        }

        if(arr[mid] >= arr[low]){
            /* left half sorted */
            if(target >= arr[low] && target < arr[mid]) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }

        else{
            /* right half is sorted */
            
            if (target > arr[mid] && target <= arr[high]) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
    }
    return -1;
}


int main() {
    int N, Q;

    cin >> N;

    vector<int> nums(N);

    for (int i=0; i<N; i++) {
        cin >> nums[i];
    }

    cin >> Q;

    vector<int> queries(Q);

    for (int i=0; i<Q; i++) {
        cin >> queries[i];
    }

    for (int i: queries) {
        cout << search(nums, i) << "\n";
    }

    return 0;
}