pythonのstackを使って入れていく
open側であれば常にPushして、Close側であればOpen側を取り出してCloseとマッチするか確認する
最初に、mapを作っておく
PythonってMapはあるんだっけ？
https://docs.python.org/3/tutorial/datastructures.html#dictionaries

格納は、stackを使う
using list as stack
apend + pop()

これで時間計算量は、n
空間計算量もn
n = the number op parenthes

")"
"]"
"}"
"])"
"))"
が初手で入ってくるケースを考えられていなかった

(
[
{

のどれかだけです。

これが invariant であると理解しておく