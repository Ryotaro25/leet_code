### Step 1: Initial Brute-Force Approach
My initial thought was to use a **brute-force approach** by iterating through every cell in the grid.
I planned to use nested loops: one for the rows and one for the columns.
For each `(row, col)` cell, I would then try to **traverse** from that specific point to see if it could reach both the Pacific and Atlantic oceans.

However, I quickly realized a limitation with this strategy.
My `TraverseIsland` function attempts to detect reachability to both oceans simultaneously.
This can lead to issues, particularly with **cycles** or repeated visits to cells, making it difficult to correctly track paths and potentially causing **infinite recursion** or incorrect results if not carefully managed.

---

### Step 2: Optimizing with Edge-Based Traversal
Instead of starting from every cell and trying to reach the oceans,
I decided to **start from the oceans themselves** and see which cells they could reach.

I introduced two separate 2D boolean arrays,
`is_reachable_to_pacific` and `is_reachable_to_atlantic`,　both the same size as the input `grid`.
These arrays will store whether a cell can be reached from the Pacific or Atlantic, respectively.

The key insight here is that the **Pacific Ocean borders the top row and left column**,
and the **Atlantic Ocean borders the bottom row and right column**.
Therefore, any water starting from these border cells can definitely reach their respective oceans.

So, I selected a **Depth-First Search (DFS)** from all cells along these borders:
* For the Pacific: I start a DFS from all cells in the first column (`col = 0`) and the first row (`row = 0`).
* For the Atlantic: I start a DFS from all cells in the last column (`col = width - 1`) and the last row (`row = height - 1`).

During these DFS traversals, the conditions for moving from one cell to an adjacent cell are crucial:
1.  The next cell must be **within the grid boundaries**.

2.  The next cell must **not have been visited yet** (i.e., `is_reachable[next_row][next_col]` must be `false`). This prevents redundant work and infinite loops.

3.  **Crucially, the height of the next cell must be greater than or equal to the current cell's height (`grid[next_row][next_col] >= current_height`)**. 
This is because we are simulating water flowing *uphill* from the ocean to the land,
which is equivalent to water flowing *downhill* from the land to the ocean.

After populating both `is_reachable_to_pacific` and `is_reachable_to_atlantic` arrays, I then iterate through the entire grid one last time. If a cell `(row, col)` is marked as reachable by **both** oceans (`is_reachable_to_pacific[row][col]` is `true` AND `is_reachable_to_atlantic[row][col]` is `true`), then that cell is added to our `flowable_islands` result."

---

### Step 3: Improving Code Readability
In Step 3, the core logic remains the same as in Step 2. 
My focus here was primarily on **improving code readability and maintainability**.

Instead of writing out four separate `if` conditions for checking the four cardinal directions (up, right, down, left),
I introduced a `directions` vector of pairs.
This vector neatly encapsulates the `(-1, 0)`, `(0, 1)`, `(1, 0)`, and `(0, -1)` offsets for row and column changes.

By iterating through this `directions` vector, the code becomes much **cleaner and more concise**.
It centralizes the logic for exploring neighbors, making it easier to understand at a glance and simpler to modify if,
for example, diagonal movements were ever introduced. 
