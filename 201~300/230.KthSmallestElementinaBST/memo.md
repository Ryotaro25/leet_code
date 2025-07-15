### Finding the K-th Smallest Element in a BST

The goal is to efficiently find the $k$-th smallest element in a BST.

#### Approach 1: Inorder Traversal and Storage

My initial thought is to leverage the fundamental property of a BST:
an **inorder traversal** (Left, Root, Right) visits nodes in ascending order.

We can perform a full inorder traversal of the tree and store the values in a data structure,
such as a **vector** or a sorted **map**.

**How it works:**
* Traverse the entire tree.
* Store the values in a vector.
* The $k$-th smallest element will be at index $k-1$ in the vector.

**Evaluation:**
This approach is straightforward and guaranteed to work.
However, it requires traversing the entire tree and storing all N nodes.
The time complexity is $O(N)$ and the space complexity is $O(N)$.

---

#### Approach 2: Optimized Iterative Inorder Traversal

For a more efficient solution, particularly if $k$ is small, we should avoid traversing the entire tree.
We can stop the traversal as soon as we find the $k$-th element.

We achieve this using an **iterative inorder traversal** with a **stack**.

**How it works:**
1.  **Initialize:** Use a `stack` to manage the traversal path and a counter initialized to k.
2.  **Traverse Left:** Start from the root and continuously move to the left child, pushing each node onto the stack until we reach `nullptr`.
This prepares the stack with the smallest elements first.

3.  **Process Node:** Pop a node from the stack.
This is the smallest element in the BST.

4.  **Check Counter:** Decrement the counter. If the counter reaches zero, we have found the k-th smallest element and can return its value immediately.

5.  **Traverse Right:** If the counter is not zero, move to the popped node's right child and repeat the process from step 2 for the right subtree.

**Evaluation:**
This optimized approach maintains the inorder sequence but only performs work until the $k$-th element is reached.
The time complexity is $O(H + K)$, where $H$ is the height of the tree (for the initial push to the leftmost node) and $K$ is the target rank.
The space complexity is $O(H)$ for the stack.