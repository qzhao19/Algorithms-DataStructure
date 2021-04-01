def select_sort(array):
    """
    """
    for i in range(len(array)-1):
        pivot = i
        for j in range(i+1, len(array)):
                if array[pivot] < array[j]:
                    pivot = j

        array[pivot], array[i] = array[i], array[pivot]
    return array

select_sort([4,8,2,5,624,5,26,9])
