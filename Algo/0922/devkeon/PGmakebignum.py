def solution(number, k):
    num = list(number)
    stack = [num[0]]
    for n in num[1:]:
        while k > 0 and stack and stack[-1] < n:
            del stack[-1]
            k -= 1
        stack.append(n)
    if k > 0:
        del stack[len(stack) - k:]
    return "".join(stack)
