def bubble_sort(array):
    """
    """
    for i in range(0, len(array)):
        for j in range(1, len(array)-i):
            if array[j-1] < array[j]:
                array[j-1], array[j] = array[j], array[j-1]
    return array

bubble_sort([4,8,2,5,624,5,26,9])
