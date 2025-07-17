// constraints
// the ansdwer should be consist of unique word ["o", "o", "ooa"] => ["o", "ooa"]
// The same letter cell may not be used more than once in a word.


### Understanding the Problem & Initial Approach
"Okay, so for this problem, the goal is to find all the words from a given list within this character `board`.
A couple of key constraints are:

We need unique words in our final answer.
So, if we find 'o' multiple times, we only add it once.
And importantly, each letter cell can only be used once per word.

My initial thought for solving this was to use Depth-First Search, or DFS, combined with backtracking.

Let me walk you through my thought process for this first approach:
1.**Outer Loops**:
I'd start with a few nested loops.
The outermost loop would iterate through every word in our `words` list.
Then, inside that, I'd have two more loops to go through every single cell (row, col) on the `board`.

2.**Starting DFS**:
If the letter at the current `(row, col)` on the board matches the first letter of the word we're currently looking for,
that's our cue to kick off a **DFS traversal** from that position.

### Diving into the DFS Traversal (`SearchWord` Function)

Inside this DFS function, which I've called `SearchWord`,
I've set up a few **base cases** to handle different scenarios:

* **Boundary Check**:
First, we check if our current `(row, col)` is within the board's boundaries.
If it's outside, we can't continue, so we just `return false`.

* **Visited Check**:
Next, we need to ensure we don't use the same cell twice for the *same word*.
So, I use an `'@'` character to mark a cell as visited during the current DFS path.
If we encounter an `'@'`, it means we've already been here, so we `return false`. 
I chose `'@'` directly on the board for simplicity and to make backtracking easier,
which I'll explain in a moment.

* **Character Match**:
We also check if the letter at `board[row][col]` actually matches the character we're expecting from our `word` at the current `word_index`.
If it doesn't match, this path is wrong, and we `return false`.

* **Word Found!**:
Finally, if `word_index` points to the **very last character of our word**,
and we've passed all the previous checks, it means we've successfully found the entire word!
In this case, we `return true`.

### Backtracking in Action

Now, about **backtracking**:

Before we start exploring the adjacent positions (up, down, left, right),
I **mark the current cell** `board[row][col]` with `'@'`.
This tells our subsequent recursive calls that this cell is currently "in use."

If the recursive calls successfully find the rest of the word (meaning `SearchWord` returns `true`),
then great, we've found our word!
The found word would then be added to a `set` (to ensure uniqueness) outside of this DFS function.

After we've explored all four directions from the current cell,
or if none of the paths lead to the full word, it's crucial to "un-mark" the current cell.
That means we change `board[row][col]` **back to its original character**.
This is vital because other words or other paths for the *same* word might need to use this cell later.

### The Performance Problem & Why I Switched

However, after thinking about the **time complexity**,
I realized this initial approach would likely be too slow,
leading to a **Time Limit Exceeded (TLE)** error.

Let's consider the constraints:
* Board size: `row = 12`, `col = 12` (so `12 * 12 = 144` cells)
* Number of words: `words.length = 10^4`
* Maximum word length: `word.length = 10`

For each of the `10^4` words, we're iterating through all `144` cells on the board.
And for each starting cell, we're running a DFS that, in the worst case, could explore many paths. A single DFS for a word of length `L` could be roughly `O(4^L)`. Plus, **we're making a copy of the board** (`cloned_board`) for *every single starting position* of *every single word*, which is `O(R * C)` for each copy.

So, the overall complexity would be roughly `O(WordsCount * BoardCells * (BoardCopyCost + 4^WordLength))`.
That's `10^4 * 144 * (144 + 4^10)`, which is an enormous number, easily exceeding `10^7`.
It's just too inefficient because we're **re-searching the board repeatedly for each word**,
even if they share common prefixes.

This is why I decided to **introduce a Trie (prefix tree)**.
It's a much more optimized way to handle multiple word searches on a grid."

---

### The Optimized Approach: Using a Trie

"Given the performance issues with the previous approach,
I decided to use a **Trie, also known as a prefix tree**.

A Trie is a specialized tree structure used to store a dynamic set of strings where each node represents a character,
and paths from the root to a node represent prefixes or complete words.
This allows us to **efficiently search for multiple words simultaneously** by traversing common prefixes only once.

Here's how I incorporated the Trie:

1.  **Trie Construction**:
    * First, I build a **Trie** using all the words from our input `words` list.
    * I start with a `root` Trie node.
    * For each `word` in `words`, I iterate through its `letter`s.
    If a `letter` doesn't exist as a child of the current Trie node,
    I **create a new `TrieNode`** for it.
    Then, I move to that child node.
    * Once I've added all letters of a word, at the very last node representing the end of that word,
    I **store the complete `word` string** itself in `node->word`. 
    This marks that node as the end of a valid word.

2.  **Optimized DFS Traversal (`SearchWords` function with Trie)**:
    * Now, instead of iterating through each word individually like before,
    I only iterate through **each cell `(row, col)` on the `board` once**.

    * For each starting cell,
    I check if the character `board[row][col]` exists as a child of the **Trie's `root` node**.
    If it doesn't, it means no word in our list starts with that character,
    so we can skip this cell.

    * If it does exist, I start my **DFS traversal** using the `SearchWords` function. 
    he key difference here is that I pass the **current `TrieNode`** (which represents the prefix found so far) into the recursive calls, not the original `word` string and `word_index`.

3.  **Inside `SearchWords` (with Trie logic)**:
    * The **base cases** are very similar to before: check for **out-of-bounds**, **already visited** cells (`@`).
    * The crucial new check is `if (!node->letter_to_child.contains(board[row][col]))`.
    This immediately prunes our search.
    If the current character on the board **doesn't form a valid prefix** (i.e., it's not a child of our current `TrieNode`), we stop this path.
    This is incredibly efficient as it eliminates unproductive searches early.

    * If all checks pass, we've found a valid character in our current path.
    We then update our `current_node` in the Trie to move deeper.

    * Now, we check `if (current_node->word != "")`.
    If this condition is true, it means we've successfully reached the end of a complete word that exists in our original `words` list
     We add this `current_node->word` to our `found_words` list.

    * **Important optimization for uniqueness**: After adding a word, I set `current_node->word = "";`. This ensures that even if we find the same word multiple times (e.g., if 'apple' appears in two different places on the board), we only add it to our `found_words` list once. We don't need a `set` for uniqueness in the `findWords` function anymore.
  
    * Just like before, we **mark the current `board` cell as visited** (`@`) and recursively explore its four neighbors.
 
    * Finally, **backtracking** remains essential: after exploring all paths from the current cell, we **restore its original character** (`current_letter`) so it can be part of other potential word paths starting from different initial cells.

### Why is this better?

This Trie-based approach is far more efficient. 
nstead of searching for `N` words independently (each costing `O(R*C*4^L)`), we build the Trie once (`O(TotalWordLength)`).
Then, we perform a single DFS traversal on the board. During this DFS, **we explore common prefixes only once**. When we hit a character on the board, we're essentially asking: "Does this character continue a prefix for *any* of the words in my Trie?" This drastically reduces redundant computations and helps us avoid TLE.
