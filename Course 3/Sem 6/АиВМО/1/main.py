from fraction import Fraction

filename = "test_1.txt"

def print_matrix(matrix):
    for i in matrix:
        for j in i:
            print('%11s' % j, end='')
        print()
    print()


def jordan_gauss_method(matrix):
    print("Начальная матрица")
    print_matrix(matrix)
    for c in range(len(matrix)):
        # По столбцам
        index = c
        for i in range(c + 1, len(matrix)):
            # По элементам столбца
            if matrix[index][c].get_abs() < matrix[i][c].get_abs():
                index = i
        if index != c:
            matrix[index], matrix[c] = matrix[c], matrix[index]
            print("Поменяли строки местами")
            print_matrix(matrix)
        if matrix[c][c] == Fraction(0):
            continue
        if matrix[c][c] != Fraction(1):
            matrix[c] = [i / matrix[c][c] for i in matrix[c]]
            print_matrix(matrix)

        for i in range(0, len(matrix)):
            if matrix[i][c] == Fraction(0):
                continue
            if i == c:
                continue
            coeff = matrix[i][c] * Fraction(-1)
            for j in range(c, len(matrix[0])):
                matrix[i][j] = matrix[i][j] + matrix[c][j] * coeff
        print_matrix(matrix)

    no_null_str = 0
    for i in matrix:
        flag = True
        for j in i[:-1]:
            if j != Fraction(0):
                flag = False
                break
        if flag and i[-1] != Fraction(0):
            no_null_str = 0
            break
        elif flag and i[-1] == Fraction(0):
            continue
        no_null_str += 1

    print("Ответ:")
    if not no_null_str:
        print("Нет решения")
    elif no_null_str == len(matrix) and no_null_str == len(matrix[0]) - 1:
        tmp = list()
        for i in range(len(matrix)):
            tmp.append("x" + str(i + 1) + " = " + str(matrix[i][-1]))
        print(*tmp, sep='\n')
    else:
        tmp = list()
        for i in range(len(matrix)):
            str_tmp = ""
            if matrix[i][i] == Fraction(1):
                str_tmp += "x" + str(i + 1) + " = " + str(matrix[i][-1])
                for j in range(len(matrix[0]) - 1):
                    if j == i:
                        continue
                    if matrix[i][j] == Fraction(0):
                        continue
                    str_tmp += " + "
                    str_tmp += "(" + str(matrix[i][j] *
                                         Fraction(-1)) + ")" + "x" + str(j + 1)
            else:
                flag = True
                for j in matrix[i][:-1]:
                    if j != Fraction(0):
                        flag = False
                        break
                if flag and matrix[i][-1] == Fraction(0):
                    continue
                for j in range(len(matrix[0]) - 1):
                    if matrix[i][j] == Fraction(0):
                        continue
                    str_tmp += " + "
                    str_tmp += "(" + str(matrix[i][j] *
                                         Fraction(-1)) + ")" + "x" + str(j + 1)
                str_tmp += " = " + str(matrix[i][-1])
            if str_tmp != "":
                tmp.append(str_tmp)
        print(*tmp, sep='\n')


matrix = []
f = open(filename, 'r')
for line in f:
    a = list(map(int, line.strip().split(' ')))
    matrix.append(list(map(Fraction, a)))
jordan_gauss_method(matrix)
