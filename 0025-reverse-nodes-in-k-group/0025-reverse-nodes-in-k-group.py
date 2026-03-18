class Solution:
    def reverseKGroup(self, head, k):
        dummy = ListNode(0, head)
        prev  = dummy

        while True:
            check = prev
            for _ in range(k):
                check = check.next
                if not check:
                    return dummy.next

            curr        = prev.next
            tail        = curr
            node_before = None

            for _ in range(k):
                nxt         = curr.next
                curr.next   = node_before
                node_before = curr
                curr        = nxt

            prev.next = node_before
            tail.next = curr
            prev      = tail