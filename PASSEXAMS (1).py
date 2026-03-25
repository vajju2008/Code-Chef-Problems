import sys
input_data = sys.stdin.read().split()
if input_data:
    T = int(input_data[0])
    pointer = 1
    for _ in range(T):
        scores = [int(input_data[pointer]), int(input_data[pointer+1]), int(input_data[pointer+2])]
        pointer += 3
        scores.sort()
        print("Yes" if scores[1] >= 50 else "No")