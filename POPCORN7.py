X = int(input())

ticket_cost = 100 # cost of the tickey 
popcorn_cost = 50 # cost of popcorns but not relayy

remaining_money = X - ticket_cost
num_buckets = remaining_money // popcorn_cost

print(num_buckets)