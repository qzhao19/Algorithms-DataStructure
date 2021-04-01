def three_sum(array):
    """Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
    Find all unique triplets in the array which gives the sum of zero.

    Note:
        Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
        The solution set must not contain duplicate triplets.
        For example, given array S = {-1 0 1 2 -1 -4},
    A solution set is:
        (-1, 0, 1)
        (-1, -1, 2)
    """
    # sort array
    array.sort()

    # define vars
    solutions = set()
    unique_set = set(array)

    # check array length and other cases
    # if len(unique_set) == 1 and len(array) > 2 and 0 in unique_set:
    #     return [0, 0, 0]
    if len(array) < 2:
        return [-1]
    
    for i, v in enumerate(array[:-2]):
        j = i + 1
        k = len(array) - 1
        while j < k:
            current = v + array[j] + array[k]
            if current == 0:
                solutions.add(tuple([array[j], v, array[k]]))
                j += 1
                k -= 1
            elif current < 0:
                j += 1
            else:
                k -= 1
    return list(solutions)

            
three_sum(([-1, 0, 1, 2, -1, -4]))
