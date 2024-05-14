#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

const int INF = 1e9;

int n; // number of cities
vector<vector<int>> dist; // matrix of distances between cities
vector<vector<int>> memo; // memoization table
vector<vector<int>> parent; // parent table for reconstructing the best path
int best_cost = INF; // minimum cost of a tour found so far

struct Node {
    int i; // current city
    int mask; // bitmask of visited cities
    int cost; // cost of path so far
    int bound; // lower bound on the cost of any path extending this one
    vector<int> path; // path so far

    bool operator<(const Node& other) const {
        return bound > other.bound; // prioritize nodes with lower bound
    }
};

void compute_lower_bound(Node& node) {
    int curr_city = node.i;
    int visited_cities = node.mask;

    // Compute the lower bound using the nearest neighbor heuristic
    int lb = node.cost;
    for (int j = 0; j < n; j++) {
        if (!(visited_cities & (1 << j))) {
            int nearest_neighbor = INF;
            for (int k = 0; k < n; k++) {
                if (k != curr_city && (visited_cities & (1 << k))) {
                    nearest_neighbor = min(nearest_neighbor, dist[k][j]);
                }
            }
            lb += nearest_neighbor;
        }
    }

    node.bound = lb;
}

void lcbb_tsp() {
    priority_queue<Node> q;

    // Add the starting node to the queue
    Node start_node = { 0, 1, 0, 0, {0} };
    q.push(start_node);

    while (!q.empty()) {
        Node node = q.top();
        q.pop();

        if (node.bound >= best_cost) { // prune the subtree rooted at this node
            continue;
        }

        if (node.mask == (1 << n) - 1) { // found a complete tour
            int path_cost = node.cost + dist[node.i][0];
            if (path_cost < best_cost) { // update the best tour found so far
                best_cost = path_cost;
                parent[node.i][node.mask] = node.path.back(); // update the parent table
            }
            continue;
        }

        for (int j = 0; j < n; j++) {
            if (!(node.mask & (1 << j))) { // city j has not been visited yet
                Node child_node = { j, node.mask | (1 << j), node.cost + dist[node.i][j], 0, node.path };
                child_node.path.push_back(node.i); // add the current city to the path

                if (memo[child_node.i][child_node.mask] > child_node.cost) {
                    memo[child_node.i][child_node.mask] = child_node.cost;
                    compute_lower_bound(child_node);
                    q.push(child_node);
                    parent[child_node.i][child_node.mask] = node.i; // update the parent table
                }
            }
        }
    }
}

int main() {
    cin >> n; // input the number of cities
    dist.resize(n, vector<int>(n));
    memo.resize(n, vector<int>(1 << n, INF));
    parent.resize(n, vector<int>(1 << n, -1));

   // input the distances between cities
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        cin >> dist[i][j];
    }
}

lcbb_tsp(); // solve the TSP problem using LCBB

// Output the minimum cost of a tour and the tour itself
cout << "Minimum cost of a tour: " << best_cost << endl;


return 0;
}