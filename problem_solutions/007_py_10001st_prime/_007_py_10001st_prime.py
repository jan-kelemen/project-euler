def find_n_primes(n=10001):
    #First 100 numbers
    list = [False, False, True] + 49*[True, False]
    primes = [2]
    last_added = 0 #keeps index of last added group of 100
    while len(primes) < n:
        for index in range(3, len(list), 2):
            if list[index] == True:
                if primes[-1] < index:
                    primes.append(index)
                if index < len(list) // 2 + 1:
                    for number in range (last_added, last_added + 101):
                        if number % index == 0 and number > index + 1:
                            list[number] = False

        if len(primes) < n:
            list += 50*[True, False] #next 100 numbers
            last_added += 100

    return primes

def get_nth_prime(n=10001):
    return find_n_primes(n)[n-1]

def main():
    print(get_nth_prime(10001))

main()
