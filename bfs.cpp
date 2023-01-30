#include <iostream>
#include <list>
using namespace std;

class Graph {
    int nodeNum;
    list<int>* adjacent;
    bool* visited;

public:
    Graph(int vertices) {
        nodeNum = vertices;
        adjacent = new list<int>[vertices];
    }

    void addEdge(int start, int end) {
        adjacent[start].push_back(end);
        adjacent[end].push_back(start);
    }

    void BFS(int source) {
        visited = new bool[nodeNum];
        for (int i = 0; i < nodeNum; i++)
            visited[i] = false;

        list<int> queue;

        visited[source] = true;
        queue.push_back(source);

        list<int>::iterator i;
        cout<<"The search direction through : "<<endl;
        while (queue.empty()!=true) {
            int currVertex = queue.front();
            cout << currVertex << ", ";
            queue.pop_front();
            
            for (i = adjacent[currVertex].begin(); i != adjacent[currVertex].end(); ++i) {
                int adjVertex = *i;
                if (visited[adjVertex]!=true) {
                    visited[adjVertex] = true;
                    queue.push_back(adjVertex);
                }
            }
        }
    }
};
int main() {
    Graph graph1(6);
    graph1.addEdge(0,1);
    graph1.addEdge(0,2);
    graph1.addEdge(1,2);
    graph1.addEdge(2,0);
    graph1.addEdge(2,3);
    graph1.addEdge(3,3);
    graph1.addEdge(4,5);
    graph1.addEdge(1,5);
    graph1.addEdge(2,5);
    graph1.addEdge(3,4);

    graph1.BFS(2);
    return 0;
}