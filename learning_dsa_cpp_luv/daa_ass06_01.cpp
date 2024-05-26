// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9; // set infinity to a large value

int tsp(vector<vector<int>>& dist, int start, int mask, vector<vector<int>>& memo) {
    if (mask == (1 << dist.size()) - 1) { // base case: all cities have been visited
        return dist[start][0];
    }
    if (memo[start][mask] != -1) { // memoization: check if subproblem has already been solved
        return memo[start][mask];
    }
    int ans = INF;
    for (int i = 0; i < dist.size(); i++) {
        if (i != start && !(mask & (1 << i))) { // if city i has not been visited
            int cost = dist[start][i] + tsp(dist, i, mask | (1 << i), memo); // recursive call
            ans = min(ans, cost);
        }
    }
    memo[start][mask] = ans; // memoization: store optimal solution for subproblem
    return ans;
}

int main() {
    int n; // number of cities
    cin >> n;
    vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
    vector<vector<int>> memo(n, vector<int>(1 << n, -1)); // initialize memoization array
    int start = 0; // start at city 0
    int mask = 1 << start; // mark city 0 as visited
    int ans = tsp(dist, start, mask, memo); // solve TSP using dynamic programming
    cout << ans << endl;
    return 0;
}
