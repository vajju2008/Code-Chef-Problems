import sys
input_data = sys.stdin.read().split()
T = int(input_data[0])
idx = 1

for _ in range(T):
    X, Y, Z = map(int, input_data[idx:idx+3])
    idx += 3
    pass_count = sum([X >= 50, Y >= 50, Z >= 50])
    
    print("Yes" if pass_count >= 2 else "No")