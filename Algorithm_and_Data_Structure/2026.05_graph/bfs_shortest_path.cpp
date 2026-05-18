#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int n = 0;

    cout << "Input count of points: ";
    cin >> n;

    cin.ignore();

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < n; i++)
    {
        int u = i + 1;
        cout << "point " << u << ": ";
        string line;
        getline(cin, line);

        stringstream ss(line);

        int v;
        while (ss >> v)
        {
            if (u < v)
            {
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
    }

    vector<int> dist(n + 1, -1);
    vector<int> prev(n + 1, 0);

    queue<int> q;

    dist[1] = 0;
    q.push(1);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur])
        {
            if (dist[next] == -1)
            {
                dist[next] = dist[cur] + 1;
                prev[next] = cur;
                q.push(next);
            }
        }
    }

    cout << endl;
    cout << "=== shortest distance form vertex 1 ===" << endl;

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == -1)
            cout << i << ": Unreachable" << endl;
        else
            cout << i << ": distance " << dist[i] << " form vertex 1" << endl;
    }

    int target;
    cout << "Which vertex should we look at the path to? " << endl;
    cin >> target;

    if (dist[target] == -1)
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