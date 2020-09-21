#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Node
{
    Node(int to,int weight):to(to),weight(weight){};
public:
    int to;
    int weight;
};

int main()
{
    ios::sync_with_stdio(false);
    int nodes, edges, source, dest;
    cin >> nodes >> edges >> source >> dest;
    vector<list<Node>> graph(nodes);
    for (int i = 0; i < edges; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
    }
}