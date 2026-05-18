#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

const int INF = 1e9;

int main()
{
    int n;
    cout << "Input count of vertex: ";
    cin >> n;
    cin.ignore();
    vector<vector<pair<int, int>>>
        graph(n + 1);

    for (int i = 0; i < n; i++)
    {
        int u = i + 1;
        cout << "Vertex " << u << ": ";
        string line;
        getline(cin, line);
        stringstream ss(line);
        int v, w;
        while (ss >> v >> w)
        {
            if (u < v)
            {
                graph[u].push_back(make_pair(v, w));
                graph[v].push_back(make_pair(u, w));
            }
        }
    }

    vector<int> dist(n + 1, INF);
    vector<int> prev(n + 1, 0);

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    int start = 1;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cur_cost = pq.top().first;
        pq.pop();

        // it is very important
        if (cur_cost > dist[cur])
            continue;

        for (auto next : graph[cur])
        {
            int next_node = next.first;
            int weight = next.second;
            int new_cost = cur_cost + weight;

            // it is also important
            if (new_cost < dist[next_node])
            {
                dist[next_node] = new_cost;
                prev[next_node] = cur;
                pq.push({new_cost, next_node});
            }
        }
    }

    cout << endl;
    cout << "=== Shortest distance form vertex 1 ===" << endl;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
            cout << i << ": unreachable" << endl;
        else
            cout << i << ": " << dist[i] << endl;
    }

    int target;
    cout << "Which vertex should we look at the path to? " << endl;
    cin >> target;

    if (dist[target] == INF)
    {
        cout << "unreachable" << endl;
    }
    else
    {
        vector<int> path;

        int cur = target;
        path.push_back(target);
        while (prev[cur])
        {
            cur = prev[cur];
            path.push_back(cur);
        }

        cout << "Path: ";
        for (int i = path.size() - 1; i >= 0; i--)
        {
            cout << path[i];
            if (i > 0)
                cout << " -> ";
        }

        cout << "\nDistance: " << dist[target] << endl;
    }

    return 0;
}