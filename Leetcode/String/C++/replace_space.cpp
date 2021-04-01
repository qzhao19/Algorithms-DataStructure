class Solution {
public:
	void replaceSpace(char *str,int length) {
        
        int j; 
        int cur_length = length;
        
        for (int i = length - 1; i >= 0; i--){
            
            if (str[i] == ' '){
                
                cur_length += 2;
                
                for (j = cur_length - 1; j > i + 2; j--){
                    str[j] = str[j-2];
                }
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '\%';
            }
            str[cur_length] = '\0';
        }
        return str;
	}
};
