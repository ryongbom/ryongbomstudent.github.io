#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

bool visited[100000] = {false};

bool hascycle(const vector<vector<int>> &g, int cur, int parent)
{
    visited[cur] = true;

    for (int next : g[cur])
    {
        if (!visited[next])
        {
            if (hascycle(g, next, cur))
            {
                return true;
            }
        }
        else if (visited[next] && next != parent)
            return true;
    }

    return false;
}

int main()
{
    int n;
    cout << "Input count of vertexs: ";
    cin >> n;

    cin.ignore();

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < n; i++)
    {
        int u = i + 1;
        cout << "vertex " << u << ": ";
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

    bool result = false;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (hascycle(graph, i, 0))
            {
                result = true;
                break;
            }
        }
    }

    cout << (result ? "Cycle found" : "Cycle not found") << endl;

    return 0;
}