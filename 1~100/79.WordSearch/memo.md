## Explaining My Approach to the Word Search Problem
This problem can be seen as finding a path in a **graph**,
where each cell on the board is a node and we can move to adjacent cells.
My solution uses **Depth-First Search (DFS)**, a common graph traversal algorithm.

First, I **iterate** through every cell on the board using two loops,
one for rows and one for columns.
I'm looking for a starting point for our search.

If a cell's letter matches the **first letter of the word** we're trying to find,
then that's a potential starting point for our DFS.

Next, let's talk about the `IsWordExist` function, which performs the DFS.

### Initial Approach and Challenges (and how I fixed them)
My first idea was to simply count how many letters matched the word.
I defined the **four possible directions** (left, top, right, down) to check neighboring cells.
I would then check if a neighbor had the **next letter** in the word.

To **avoid visiting the same cell twice** in a single path,
I used a **hash set** to keep track of visited cells.
I also added checks to make sure the `row` and `col` were within the board's boundaries
and that we hadn't already found all the letters in the word.

However, my first solution didn't work correctly.
It couldn't handle situations where there were **multiple possible paths** to form the word.
For example, if the word "APPLE" could be formed in two different ways starting from the same "A",
my program might get stuck on the first path and fail if that path didn't lead to the full word.

This is where **backtracking** comes in.
Backtracking helps us "go back" to a previous state if a chosen path doesn't lead to a solution.
Before visiting a neighbor, I **add the current cell to the `visited` hash set**.
If that path doesn't lead to the full word, I then **remove the cell from the `visited` set**.
This lets the algorithm explore other paths from the previous state.

### Optimizations

I made a couple of changes to make the solution more efficient:

* **Marking visited cells on the board:**
Instead of using a hash set, which takes a little longer to add and remove items (around O(log N) time),
I directly **mark the visited cell on the board itself**.
I change the letter to a special character, like `'@'`, to indicate it's been visited.
This takes **constant time** (O(1)).
After exploring all paths from that cell,
I change the character back to its original value.
This is a common trick in these types of problems.

* **Using fixed arrays for directions:**
I also changed the `vector<vector<int>>` for directions to fixed-size arrays like `int row_directions[4]` and `int col_directions[4]`.
This is a small optimization that can sometimes be slightly faster.

### Time and Space Complexity

* **Time Complexity:**
The time complexity is approximately O(N * 3^m), where N is the number of cells on the board (rows * columns) and M is the length of the word.
For each cell on the board, we might start a DFS.
In the worst case, from each cell, we can explore up to 3 directions (since we can't go back to the cell we just came from).

* **Space Complexity:** 
The space complexity is O(M) (excluding the input arguments from LeetCode).
This is because of the recursion stack in the DFS, which can go as deep as the length of the word.
