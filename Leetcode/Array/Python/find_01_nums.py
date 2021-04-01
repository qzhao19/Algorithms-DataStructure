def find_01_nums(string):
    """Sort a 0-1 string (a string containing only 0 and 1), you can swap any two positions, 
    and ask the minimum number of swaps
    """
    # string = '010000011110001111'
    i = 0
    j = len(string) - 1
    count = 0
    while i < j:
        while string[i] == 0 and i < len(string):
            i += 1
        while string[j] == 1 and j >= 0:
            j -= 1
        if i < j:
            count += 1
            string[i] = 0
            string[j] = 1
    
    return count
        
find_01_nums([1,0,0,1,0,0,0,1,0,0,1,1,0,1,1,0])
