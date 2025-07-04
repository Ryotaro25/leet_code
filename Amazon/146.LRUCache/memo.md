To implement the get operation efficiently, I'll use a map.
This data structure allows me to store key-value pairs, and if a key exists, I can retrieve its value in constant time (O(1)) on average.

Next, to handle the 'Least Recently Used' aspect, my first thought was to use a queue.
A queue naturally represents order: the first element added would be the 'least recent,' and the last element added would be the 'most recent.'
Adding and removing elements from the ends of a queue typically takes O(1) time.

However, I realized a queue has a limitation: if I need to remove an element from the middle (which happens when an existing item is accessed and becomes 'most recent'), it would take O(N) time in a standard queue. 
This doesn't meet the O(1) requirement for all operations.

So, I decided to use a different data structure to manage the order: a doubly linked list.
I will define a Node struct for this list, where each node has pointers to both the previous and next nodes.
A doubly linked list is perfect because, in addition to adding elements at one end (like the front) and removing elements from the other end (like the tail) in O(1) time, it can also remove an element from the middle in O(1) time—provided you have a pointer to that specific node. 
This is a key difference from an array or a simple queue."

To connect these two, the map will store the key and a pointer (or iterator) to its corresponding Node in the doubly linked list.

Let's start with the implementation of the get function.
First, I'll check if the key exists in my map. If it doesn't, the function will immediately return -1.
If the key does exist, I retrieve the Node using the map.
Then, I remove this node from its current position in the linked list and add it to the most recently used end of the list (which I've decided will be the tail).
This action signifies that the value has just been accessed.
Finally, I return the value stored in that node.

Second, I'll implement the put function.
If the key already exists in the map, it means we are updating an existing entry.
In this case, I will first remove the old node associated with this key from both the map and the linked list.
Then, I will create a new Node with the updated value.
I'll add this new node to the most recently used end of the linked list (the tail) and update the map to point to this new node.

Finally, after adding or updating an item, I check if the current map size (which represents the number of items in the cache) exceeds the capacity.
If it does, I need to evict the Least Recently Used item.
This item is always located at the head of my linked list.
So, I will remove that head node from both the linked list and the map, and then free its memory for avoiding memory leak.
