import re

triangle = []

with open('triangle.txt') as file:
    for line in file.readlines():
        new_line = []
        for number in line.split():
            if re.match('0\d+', number):
                new_line.append(int(number[1:]))
            else:
                new_line.append(int(number))
        triangle.append(new_line)

def max_sum():
    for i in range(len(triangle) - 2, -1, -1):
        for j in range(len(triangle[i])):
            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1])
    return triangle[0][0]

print(max_sum())