/*You have to create a graph with 5 vertices:

0, 1, 2, 3, 4

Then connect these vertices using edges:

0 — 1
1 — 2
1 — 3
2 — 3
2 — 4

2. Graph represented visually
        0
        |
        1
       / \
      2---3
      |
      4
      

3. What is an Adjacency List?
An adjacency list stores the neighbors of every vertex.

For this graph:

Vertex    Neighbors
  0   →   1
  1   →   0  2  3
  2   →   1  3  4
  3   →   1  2
  4   →   2

So the program prints approximately:

0 : 1
1 : 0 2 3
2 : 1 3 4
3 : 1 2
4 : 2





4. What does addEdge() do?

This is the most important part:

void addEdge(int u, int v) {
    l[u].push_back(v);
    l[v].push_back(u);
}

Suppose we call:

g.addEdge(0, 1);

Because the graph is undirected, we need both:

0 → 1
1 → 0

Therefore:

l[0].push_back(1);
l[1].push_back(0);

If it were a directed graph, we would only need:

l[u].push_back(v);



*/





