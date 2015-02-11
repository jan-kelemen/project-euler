import math

def sum_squares_of_first(limit):
    sum = 0
    for i in range(1, limit + 1):
        sum += math.pow(i,2)
    return sum

def squared_sum_of_first(limit):
    return math.pow(limit*(limit+1)/2, 2)

def main():
    print(int(squared_sum_of_first(100) - sum_squares_of_first(100)))

main()