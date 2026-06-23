class TextEditor(object):

    def __init__(self):
        self.left = []   # Text to the left of cursor
        self.right = []  # Text to the right of cursor

    def addText(self, text):
        for ch in text:
            self.left.append(ch)

    def deleteText(self, k):
        deleted = min(k, len(self.left))

        for _ in range(deleted):
            self.left.pop()

        return deleted

    def cursorLeft(self, k):
        moves = min(k, len(self.left))

        for _ in range(moves):
            self.right.append(self.left.pop())

        return ''.join(self.left[-10:])

    def cursorRight(self, k):
        moves = min(k, len(self.right))

        for _ in range(moves):
            self.left.append(self.right.pop())

        return ''.join(self.left[-10:])


# Your TextEditor object will be instantiated and called as such:
# obj = TextEditor()
# obj.addText(text)
# param_2 = obj.deleteText(k)
# param_3 = obj.cursorLeft(k)
# param_4 = obj.cursorRight(k)