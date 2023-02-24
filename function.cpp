#include "function.h"

//print the puzzle
void print_state(array<int,9> arr)
{
    for(int i = 0; i < 9; i++)
    {
        cout << arr[i];
        if(!((i+1)%3))
            cout << endl;
    }
}

//postion - 1 
//0 1 2
//3 4 5
//6 7 8
//row = (position - 1) / 3;
//col = (position - 1) % 3;
array<int, 9> new_state(array<int, 9> arr, int position)
{   
    array<int, 9> result = arr;
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    //row + 1
    for(int i = row * 3; i < (row + 1) * 3; i++)
    {   
        result[i] = (result[i] + 1) % 4;
    }
    //column + 1
    for(int i = 0; i <= 2; i++)
    {
        if((i * 3 + col) != (position - 1))
            result[i * 3 + col] = (result[i * 3 + col] + 1) % 4;
    }
    return result;
}


//compare with the target
bool is_match(array<int, 9> arr, int result)
{
    for(int i = 0; i < 9; i++)
    {
        if(arr[i] != result)
            return false;
    }
    return true;
}
