class Solution:
    def evalRPN(self, tokens):
        stack = []

        for token in tokens:
            if token not in "+-*/":
                stack.append(int(token))
            else:
                b = stack.pop()
                a = stack.pop()

                if token == "+":
                    stack.append(a + b)
                elif token == "-":
                    stack.append(a - b)
                elif token == "*":
                    stack.append(a * b)
                else:
                    # division truncating toward zero
                    if a * b < 0:
                        stack.append(-(abs(a) // abs(b)))
                    else:
                        stack.append(abs(a) // abs(b))

        return stack[-1]