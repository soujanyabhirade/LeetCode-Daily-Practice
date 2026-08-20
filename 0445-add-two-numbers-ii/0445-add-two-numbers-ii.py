class Solution:
    def addTwoNumbers(self, l1, l2):
        stack1 = []
        stack2 = []

        while l1:
            stack1.append(l1.val)
            l1 = l1.next

        while l2:
            stack2.append(l2.val)
            l2 = l2.next

        carry = 0
        head = None

        while stack1 or stack2 or carry:
            a = stack1.pop() if stack1 else 0
            b = stack2.pop() if stack2 else 0

            total = a + b + carry
            carry = total // 10

            node = ListNode(total % 10)
            node.next = head
            head = node

        return head