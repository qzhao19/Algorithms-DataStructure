def fibonacci_recursion(n):
    """
    """
    if n == 0:
        return 0
    if n == 1:
        return 1

    return fibonacci(n-1) + fibonacci(n-2) 


def fibonacci(n):
    """
    """
    solution_1 = [0, 1]
    if (n < 2):
        return solution_1

    fib_minus_1 = 1
    fib_minus_2 = 0
    fib_n = 0

    for i in range(2, n+1):
        fib_n = fib_minus_1 + fib_minus_2
        fib_minus_2 = fib_minus_1
        fib_minus_1 = fib_n
    return fib_n

fibonacci(10)
# 55
fibonacci_recursion(10)
# 55
