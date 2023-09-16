# 双指针
### 经典问题：给定一个链表，判断链表中是否有环。
解决方案：使用双指针，令两个指针移动的速度快慢不同，想象一下，有两个速度不同的跑步者。如果他们在直路上行驶，快跑者将首先到达目的地。但是，如果他们在圆形跑道上跑步，那么快跑者如果继续跑步就会追上慢跑者。这正是我们在链表中使用两个速度不同的指针时会遇到的情况：

* 如果没有环，快指针将停在链表的末尾。
* 如果有环，快指针最终将与慢指针相遇。
所以剩下的问题是：

这两个指针的适当速度应该是多少？

一个安全的选择是每次移动慢指针一步，而移动快指针两步。每一次迭代，快速指针将额外移动一步。如果环的长度为 M，经过 M 次迭代后，快指针肯定会多绕环一周，并赶上慢指针。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/linked-list/jcp57/
来源：力扣（LeetCode）

### 环形链表

给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

不允许修改链表。

![](ldpict/LinkedListCycle.png)

输入：head = [3,2,0,-4], pos = 1

输出：返回索引为 1 的链表节点

解释：链表中有一个环，其尾部连接到第二个节点。

题解：https://leetcode.cn/problems/linked-list-cycle-ii/solutions/12616/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/

### 相交链表
![](ldpict/xjListNode.png)

题目数据 保证 整个链式结构中不存在环。

注意，函数返回结果后，链表必须 保持其原始结构 。

题解：https://leetcode.cn/problems/intersection-of-two-linked-lists/solution/

### 删除链表的第N个节点
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
![](ldpict/deleteListNode.jpg)

题解：https://leetcode.cn/problems/remove-nth-node-from-end-of-list/solution/

### 链表双指针问题解决的模板
```C++
// Initialize slow & fast pointers
ListNode* slow = head;
ListNode* fast = head;
/**
 * Change this condition to fit specific problem.
 * Attention: remember to avoid null-pointer error
 **/
while (slow && fast && fast->next) {
    slow = slow->next;          // move slow pointer one step each time
    fast = fast->next->next;    // move fast pointer two steps each time
    if (slow == fast) {         // change this condition to fit specific problem
        return true;
    }
}
return false;   // change return value to fit specific problem
```
### 注意事项
#### 在调用 next 字段之前，始终检查节点是否为空。

获取空节点的下一个节点将导致空指针错误。例如，在我们运行 fast = fast.next.next 之前，需要检查 fast 和 fast.next 不为空。
#### 仔细定义循环的结束条件。