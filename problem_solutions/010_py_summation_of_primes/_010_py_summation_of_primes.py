def sieve():
    numbers = [False, False, True] + 999999*[True, False]
    for odd in range(3, len(numbers)//2 + 1, 2):
        if numbers[odd] == True:
            for multiple in range(2*odd, len(numbers), odd):
                numbers[multiple] = False

    return [x for x in range(len(numbers)) if numbers[x] == True]

def sum_primes():
    return sum(sieve())

print(sum_primes())