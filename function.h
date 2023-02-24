#include <iostream>
#include <algorithm>
#include <deque>
#include <array>

using namespace std;

//print puzzle
void print_state(array<int,9> arr);

//puzzle changed according to the position
array<int, 9> new_state(array<int, 9>, int position);

//compare with the target
bool is_match(array<int, 9> arr, int res);


struct pattern
{
    array<int, 9> current;//current state
    int move;//position
    pattern *prev;//last state
};