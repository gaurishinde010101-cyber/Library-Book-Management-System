#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(vector<int>& parent, int v) {
    if (parent[v] == v)
        return v;

    return parent[v] = findParent(parent, parent[v]);
}

void kruskal(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(V);
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int totalCost = 0;
    int edgeCount = 0;

    cout << "\nMinimum Cost Renewable Energy Network:\n";

    for (const Edge& e : edges) {
        int p1 = findParent(parent, e.src);
        int p2 = findParent(parent, e.dest);

        if (p1 != p2) {
            cout << e.src << " - " << e.dest
                 << " : Cost = " << e.weight << endl;

            parent[p1] = p2;
            totalCost += e.weight;
            edgeCount++;
        }

        if (edgeCount == V - 1) {
            break;
        }
    }

    if (edgeCount == V - 1) {
        cout << "Total Minimum Cost = " << totalCost << endl;
    } else {
        cout << "Error: Network is disconnected.\n";
        cout << "A minimum spanning tree cannot be formed.\n";
    }
}

int main() {
    int V = 5;

    // 0: Solar Power Plant
    // 1: Wind Power Plant
    // 2: Substation A
    // 3: Substation B
    // 4: Distribution Center

    vector<Edge> edges = {
        {0, 2, 4},
        {0, 3, 2},
        {1, 2, 3},
        {1, 3, 6},
        {2, 3, 5},
        {2, 4, 7},
        {3, 4, 4}
    };

    kruskal(edges, V);

    return 0;
}