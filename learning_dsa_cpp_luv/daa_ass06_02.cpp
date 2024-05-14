#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9; // Infinity value for initializing the minimum cost

int n; // number of cities
vector<vector<int>> dist; // matrix of distances between cities
vector<int> best_path; // best tour found so far
int best_cost = INF; // minimum cost of a tour found so far

void tsp_bt(int curr, int visited, int path_cost, vector<int>& path) {
    if (visited == (1 << n) - 1) { // All cities have been visited
        path_cost += dist[curr][0]; // Add the cost of returning to the starting city
        if (path_cost < best_cost) { // Update the best tour found so far
            best_cost = path_cost;
            best_path = path;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!(visited & (1 << i))) { // City i has not been visited yet
            path.push_back(i);
            tsp_bt(i, visited | (1 << i), path_cost + dist[curr][i], path);
            path.pop_back();
        }
    }
}

int main() {
    cin >> n; // input the number of cities
    dist.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j]; // input the distance between cities i and j
        }
    }

    // Start the backtracking algorithm from city 0
    vector<int> path{ 0 };
    tsp_bt(0, 1, 0, path);

    // Output the best tour found and its cost
    cout << "The minimum cost of a tour that starts and ends at city 0 and visits all the cities exactly once is " << best_cost << "." << endl;
    cout << "The tour is: ";
    for (int i = 0; i < n; i++) {
        cout << best_path[i] << " ";
    }
    cout << "0" << endl; // add the starting city at the end of the tour

    return 0;
}
