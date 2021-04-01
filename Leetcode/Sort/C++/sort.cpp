#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertionSort(vector<int> &array){
    for (int i = 1; i < array.size(); i++){
        int tmp = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > tmp){
            array[j + 1] = array[j];
            j--;
        }
        // update tmp
        array[j + 1] = tmp;
    }

}


int main(){

    vector<int> array;
	array.push_back(1);
	array.push_back(5);
	array.push_back(9);
	array.push_back(2);
	array.push_back(5);
	array.push_back(7);
	array.push_back(8);

    insertionSort(array);

    for (int i=0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    return 0;

}

