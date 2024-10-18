#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX], queue[MAX], front = -1, rear = -1;
int V;

void enqueue(int vertex)
{
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = vertex;
}

int dequeue()
{
    if (front == -1)
        return -1;
    int vertex = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return vertex;
}

void bfs(int startVertex)
{
    for (int i = 0; i < V; i++)
        visited[i] = 0;
    enqueue(startVertex);
    visited[startVertex] = 1;

    while (front != -1)
    {
        int vertex = dequeue();
        printf("%d ", vertex);

        for (int i = 0; i < V; i++)
        {
            if (graph[vertex][i] == 1 && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

void dfs(int vertex)
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < V; i++)
    {
        if (graph[vertex][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    int startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);
    printf("BFS Traversal: ");
    bfs(startVertex);
    printf("\n");

    for (int i = 0; i < V; i++)
        visited[i] = 0;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);
    printf("DFS Traversal: ");
    dfs(startVertex);
    printf("\n");

    return 0;
}
