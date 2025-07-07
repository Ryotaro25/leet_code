Here's how I approach checking for a tree:

There are two main properties a graph must satisfy to be considered a tree:

* **Connectivity**: All nodes must be connected, meaning the graph should form a single connected component.
* **Acyclicity**: There should be no cycles within the graph.

To implement this, I use the following:

* An **adjacency map** (`map<int, vector<int>>`) to store each node and its neighbors for graph traversal.
* Another **map** (`map<int, int>`) to keep track of visited nodes and their respective **parent nodes**. This is crucial for correctly identifying cycles.
set

During traversal, if a neighbor node has already been visited, it might indicate a cycle. However, we must be careful: if the visited neighbor is simply the **parent node** of the current node, it's not a cycle; it's just the edge we came from. Therefore, I **skip** checking for a cycle when the `next_node` is the `parent_node`.

I start the traversal from node 0. After the traversal is complete, I compare the total number of nodes visited (the size of my `visited` map) with the given `n` (the total number of nodes). If they are equal, it confirms that all nodes are connected.
