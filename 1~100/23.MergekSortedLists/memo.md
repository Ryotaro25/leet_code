### Map Structure Explanation
Before reconnecting the linked list, I construct a **map** structure.
The **value of a node** serves as the **key** for the map,
and the **nodes themselves** become the **value** of the map.

I use a **vector**, which is like an array in C++, to store the nodes for the map's value.
This allows me to collect every node that has the same key (i.e., the same value).

### Reconnecting the List
After constructing the map, I traverse the map from the beginning,
connecting every node until I reach the end.
Inside the map, the keys are aligned in **increasing order**.

It takes O(n log n) when constructing the map.
The codes visits every node in all lists. It takes O(log n) when inserting the key into map.