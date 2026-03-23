class Solution:
    def reverseBetween(self, head, left, right):
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy

        # Step 1: walk prev to the node just before 'left'
        for _ in range(left - 1):
            prev = prev.next

        # Step 2: reverse (right - left) times
        curr = prev.next
        for _ in range(right - left):
            next_node = curr.next
            curr.next = next_node.next
            next_node.next = prev.next
            prev.next = next_node

        return dummy.next