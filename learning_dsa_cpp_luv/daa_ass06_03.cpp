#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9; // set infinity to a large value

int tsp(vector<vector<int>>& dist, int start, vector<int>& tour, vector<bool>& visited, int depth, int bound) {
    if (depth == dist.size()) { // base case: all cities have been visited
        return dist[start][0];
    }
    int ans = INF;
    for (int i = 0; i < dist.size(); i++) {
        if (!visited[i]) { // if city i has not been visited
            visited[i] = true;
            tour[depth] = i;
            int cost = dist[start][i] + tsp(dist, i, tour, visited, depth + 1, bound);
            if (cost < bound) { // prune if cost exceeds current bound
                ans = min(ans, cost);
            }
            visited[i] = false;
        }
    }
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
    vector<int> tour(n);
    vector<bool> visited(n);
    visited[0] = true; // start at city 0
    int bound = tsp(dist, 0, tour, visited, 1, INF); // solve TSP using backtracking with dynamic tree formulation
    cout <<"the minimum ost of a tour that starts and ends at city 0 and visits all the cities exactly once is "<< bound << endl;
    return 0;
}
