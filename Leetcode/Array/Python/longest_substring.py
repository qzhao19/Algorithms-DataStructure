class LongestSubstring(object):
    def __init__(self):
        pass
    
    def lengthOfLongestSubstring(self, string):
        # check string 
        if not string:
            return 0
        # check the length of string
        if len(string)<1:
            return len(string)
        # create a list contains index position about a char
        locations=[-1 for i in range(256)]
        index=-1
        max_index=0
        for i, v in enumerate(string):
#             print(locations[ord(v)])
            if (locations[ord(v)]>index):
                index=locations[ord(v)]
#                 print(index)
            max_index=max(max_index, i-index)
#             print(max_index)
            locations[ord(v)]=i
        return max_index
if __name__=='__main__':
    print(LongestSubstring().lengthOfLongestSubstring('abceabcbbe'))
