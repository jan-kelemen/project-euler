def sum_digits(number):
    sum = 0
    while number > 0:
        sum += number % 10
        number //= 10
    return sum

print(sum_digits(2 ** 1000))