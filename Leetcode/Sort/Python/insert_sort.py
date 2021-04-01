def insert_sort(array):
    """
    """
    for i in range(1, len(array)):
        key = array[i]
        j = i - 1
        while j>=0 and array[j] < key:
            array[j+1] = array[j]
            j-=1
        array[j+1] = key
    return array

insert_sort([4,8,2,5,624,5,26,9])
