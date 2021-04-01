class Solution {
public:
	void replaceSpace(char *str,int length) {
        int space_counter = 0;
        int cur_length;
        
        for(int i = length - 1; i >= 0; i--){
            if (str[i] == ' '){
                space_counter++;
            }
        }
        
        cur_length = length + space_counter * 2;
        
        for (int i = length - 1, j = cur_length - 1; (i >=0 && j >= 0);){
            if (str[i] == ' '){
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '\%';
                i--;
            }else{
                str[j--] = str[i--];
            }
        }
        str[cur_length] = '0';
	}
};
