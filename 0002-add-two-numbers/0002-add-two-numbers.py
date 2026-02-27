class Solution:
    def addTwoNumbers(self, l1, l2):

        # Convert linked list to number
        n1 = 0
        place = 1
        while l1:
            n1 += l1.val * place
            place *= 10
            l1 = l1.next

        n2 = 0
        place = 1
        while l2:
            n2 += l2.val * place
            place *= 10
            l2 = l2.next

        total = n1 + n2

        # Convert number back to linked list
        dummy = ListNode(0)
        curr = dummy

        if total == 0:
            return ListNode(0)

        while total > 0:
            curr.next = ListNode(total % 10)
            total //= 10
            curr = curr.next

        return dummy.next