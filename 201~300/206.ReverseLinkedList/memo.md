dummy_head を作る
与えられたnodeをstackに全て詰め込む
全て詰め込み終わったら、stackの1番上から空になるまで順番に取り出してdummy_head に繋げていく
時間計算量と空間計算量はともにO(n)


空間計算量O(1)も数珠つなぎをすることでできそう
[1,2,3,4,5]

node 1 2 3 4 5
dummy none <- 1 <- 2 <- 3

dummy = none

temp = 1.next
1.next = dummy
node = temp

temp = 2
2.next = 1
dummy = temp
node = temp.next

while node: 
temp = node
node.next = dummy
node = temp.next
dummy = temp

while node: 1 :
temp = node: 1
node.next = dummy: none
node = temp.next: 2
dummy = temp: 1 

while node: 2 :
temp = node: 2
node.next = dummy: 1
node = temp.next: 3
dummy = temp: 2

