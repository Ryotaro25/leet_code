inserting value into map in CPP takes O(log n).
https://stackoverflow.com/questions/21740893/what-is-the-time-complexity-of-stdmap

iterator class
https://en.cppreference.com/w/cpp/iterator/iterator.html
https://stackoverflow.com/questions/10364050/what-is-the-type-of-an-iterator-in-stl

auto vs auto&
https://stackoverflow.com/questions/29859796/c-auto-vs-auto


["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

[4, 5, 8, 2] => [8, 5, 4, 2]
[3] [8, 5, 4, 3, 2] => 4
[5] [8, 5, 5, 4, 3, 2] => 5
[10] [10, 8, 5, 5, 4, 3, 2] => 5
[9] [10, 9, 8, 5, 5, 4, 3, 2] => 8
[4] [10, 9, 8, 5, 5, 4, 4, 3, 2] => 8
