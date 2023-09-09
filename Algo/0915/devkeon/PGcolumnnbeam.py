def build(x, y, a, arr):
    if a == 0:
        if y == 0 or [x, y - 1, 0] in arr or [x, y, 1] in arr or [x - 1, y, 1] in arr:
            return True
    else:
        if ([x - 1, y, 1] in arr and [x + 1, y, 1] in arr) or [x, y - 1, 0] in arr or [x + 1, y - 1, 0] in arr:
            return True
    return False


def solution(n, build_frame):
    answer = []
    for x, y, a, b in build_frame:
        if b == 1:
            if build(x, y, a, answer):
                answer.append([x, y, a])
        else:
            answer.remove([x, y, a])
            for tx, ty, ta in answer:
                if build(tx, ty, ta, answer):
                    continue
                else:
                    answer.append([x, y, a])
                    break
    answer.sort()
    return answer
