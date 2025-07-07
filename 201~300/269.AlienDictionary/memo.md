## Explanation of the Alien Order Solution

I've tried to implement a solution for the alien dictionary problem.
Here's how I understand the logic.

### 1\. Initializing Letter Information

First, I create a map called `letter_to_cnt` to store **in-degrees** for each character.
The in-degree represents how many other characters come *before* a specific character in the alien alphabet. Initially, all letters are set to 0.

```cpp
map<char, int> letter_to_cnt;
for (string word : words) {
  for (char letter : word) {
    letter_to_cnt[letter] = 0; // Initialize in-degree for all unique characters
  }
}
```

I also declare another map, `letter_to_adjacents`,
which will store the **dependencies** between characters.
For example, if 'a' comes before 'b', then 'b' will be an adjacent character to 'a'.
This forms a directed graph.

### 2\. Building the Graph (Dependencies and In-degrees)

Next, I iterate through the `words` list,
comparing **adjacent words** to find the character order.

#### Handling Invalid Orders

There's a special condition to check: if a `word` has `next_word` as its prefix,
but `word` is longer than `next_word`,
this means the `next_word` should have appeared *before* the current `word`.
This violates the lexicographical rule,
so I return an empty string.
For example, if `words` contains ["abc", "ab"], this is invalid.

#### Finding the First Different Character

Then, I compare characters of the current `word` and `next_word` one by one, up to the length of the shorter word.
The **first character that is different** tells us the order. For example, if "apple" and "apply" are compared, 'e' comes before 'y'.

Here, `letter_to_adjacents[word[j]].push_back(next_word[j]);` means that `word[j]` must come before `next_word[j]`. 
So, `next_word[j]` is a neighbor (or adjacent) character to `word[j]` in the directed graph.
And `letter_to_cnt[next_word[j]]++;` is crucial. It **increments the in-degree** of `next_word[j]`.
This means that `next_word[j]` now has one more character (`word[j]`) that must appear before it in the alien alphabet.

### 3\. Topological Sort (Building the Alien Order)

After building the graph (represented by `letter_to_adjacents` and `letter_to_cnt`),
I use a **topological sort** algorithm to find the alien order.

```cpp
string alien_orderd = "";
queue<char> traversing_letters;
```

#### Initializing the Queue

I add all characters with an **in-degree of zero** to a queue called `traversing_letters`.
These characters have no preceding characters, so they can be the **first ones** in our alien alphabet.

```cpp
for (auto [letter, cnt] : letter_to_cnt) {
  if (cnt == 0) {
    traversing_letters.push(letter);
  }
}
```

#### Processing Characters in Order

While the queue is not empty, I do the following:

1.  **Dequeue a character:** This character is one that can now be placed in the alien alphabet.
    ```cpp
    char letter = traversing_letters.front();
    traversing_letters.pop();
    ```
2.  **Add to result:** Append this character to our `alien_orderd` string.
    ```cpp
    alien_orderd += letter;
    ```
3.  **Process its neighbors:** For each `next_letter` that `letter` points to (its adjacent characters):
    ```cpp
    for (char next_letter : letter_to_adjacents[letter]) {
      letter_to_cnt[next_letter]--; // Decrement the in-degree of the neighbor
    ```
    Decrementing the in-degree means that one of its dependencies (`letter`) has now been processed and added to the `alien_orderd`.
    ```cpp
      if (letter_to_cnt[next_letter] == 0) {
        traversing_letters.push(next_letter); // If in-degree becomes zero, add to queue
      }
    }
    ```
    If `next_letter`'s in-degree becomes zero, it means all characters that should come before it have now been processed. So, `next_letter` can now be added to the `traversing_letters` queue to be processed next.

### 4\. Final Check

Finally, after the loop finishes, I check if the `alien_orderd` string contains **all unique characters**.
If its size is less than the total number of unique characters initially found (`letter_to_cnt.size()`), it means there was a **cycle** in the graph (e.g., 'a' comes before 'b', and 'b' comes before 'a').
In such a case, a valid alien order cannot be formed, so I return an empty string.
Otherwise, I return the constructed `alien_orderd`.

```cpp
if (alien_orderd.size() < letter_to_cnt.size()) {
  return ""; // Cycle detected, impossible to form a valid order
}
return alien_orderd;
```