#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

vector<int> result;
bool visited[100000] = {false};

void dfs(const vector<vector<int>> &g, int start, int end)
{
    if (start == end)
    {
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << "->";
        }
        cout << end;

        cout << endl;

        return;
    }

    visited[start] = true;

    result.push_back(start);
    for (int next : g[start])
    {
        if (visited[next] == true)
        {
            continue;
        }
        dfs(g, next, end);
    }

    visited[start] = false;
    result.pop_back();
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

    int f, e;
    cout << "Input first vertex of path: ";
    cin >> f;
    cout << "Input end vertex of path: ";
    cin >> e;

    dfs(graph, f, e);

    return 0;
}