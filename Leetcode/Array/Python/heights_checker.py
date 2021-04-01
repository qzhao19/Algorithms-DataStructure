def heights_checker(array):
    """Students are asked to stand in non-decreasing order of heights for an annual photo. Return the minimum 
    number of students not standing in the right positions.  (This is the number of students 
    that must move in order for all students to be standing in non-decreasing order of height.)
    
    Example 1:
    
    Input: [1,1,4,2,1,3]
    Output: 3
    Explanation: 
    Students with heights 4, 3 and the last 1 are not standing in the right positions.
    """
    sorted_array = sorted(array)
    return sum(x != y for x, y in zip(array, sorted_array))
    
if __name__ == '__main__':
    print(heights_checker([1, 1, 4, 2, 1, 3])
