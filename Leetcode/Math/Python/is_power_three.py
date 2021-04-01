def is_power_three(x):
    """Given an integer, we determine if it is a power of 3
    Args:
        x: integer
    """
    if x < 1:
        return -1
        
    while(x%3 == 0):
        x /= 3
        
    return x == 1


is_power_three(27)
