0 1 2 3 4 5 6

fast 0 2 4 6 nullptr
slow 0 1 2 3 
slow->prev = slow->next

ListNode *slow = head, *fast = head -> next -> next;
初期値であらかじめ進めておく方法があるが、
個人的には初期値は同じでループの中で差をつける方が素直な気がする