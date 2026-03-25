# cook your dish here
import sys

input_data = sys.stdin.read().split()
if input_data:
    T = int(input_data[0])
    pointer = 1
    for _ in range(T):
        N = int(input_data[pointer])
        K = int(input_data[pointer + 1])
        pointer += 2
        
        A = []
        for i in range(N):
            A.append(int(input_data[pointer]))
            pointer += 1
            
        A.sort(reverse=True)
        
        total_profit = 0
        for i in range(N):
            cost = 5 if i < K else 10
            profit = A[i] - cost
            if profit > 0:
                total_profit += profit
                
        print(total_profit)