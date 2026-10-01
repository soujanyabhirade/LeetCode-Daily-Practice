class Solution:
    def rotateRight(self, head, k):

        if not head or not head.next or k == 0:
            return head

        # Find length and last node
        length = 1
        last = head

        while last.next:
            last = last.next
            length += 1

        # Remove unnecessary rotations
        k = k % length

        if k == 0:
            return head

        # Find the new last node
        new_last = head

        for _ in range(length - k - 1):
            new_last = new_last.next

        # New head is next to new_last
        new_head = new_last.next

        # Break the list
        new_last.next = None

        # Connect old last to old head
        last.next = head

        return new_head