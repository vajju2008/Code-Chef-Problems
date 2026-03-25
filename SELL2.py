# cook your dish here
import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    iterator = iter(input_data)
    
    try:
        num_test_cases = int(next(iterator))
    except StopIteration:
        return

    for _ in range(num_test_cases):
        try:
            n = int(next(iterator))
            prices = []
            
            for _ in range(n):
                prices.append(int(next(iterator)))
        except StopIteration:
            break

        slots = []
        for i in range(n):
                
            day = i + 1
            price = prices[i]
            slots.append((price, day))
            slots.append((price, day))

        slots.sort(key=lambda x: x[0], reverse=True) #sorting 

        used_watches = [False] * (n + 1)
        total_profit = 0 # starts from scrtach 
        sold_count = 0 # sold from scrtch 

        for price, day_limit in slots:
            watch_to_sell = -1
            
            for w in range(day_limit, 0, -1):
                    
                if not used_watches[w]:
                        
                    watch_to_sell = w
                    break
            
            if watch_to_sell != -1:
                    
                used_watches[watch_to_sell] = True
                total_profit += price
                sold_count += 1
            
            if sold_count == n:
                break

        print(total_profit)

if __name__ == '__main__':
    solve()