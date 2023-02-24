#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <deque>
#include <array>
#include <set>

#include "function.h"
using namespace std;

//have to be global
set<string> record;

bool is_recorded(pattern pt)
{
    stringstream puzzle_stream;
    for(int i = 0; i < 9; i++)
    {
        puzzle_stream << pt.current[i];
    }
    string state_str = puzzle_stream.str();
    if(record.find(state_str)!= record.end())
        return true;
    record.insert(state_str);
    return false;
}

int main()
{
    //初始矩阵 目标矩阵
    array<int, 9> init = {4,1,4,2,1,2,1,3,1};
    int target = 3;
    bool solved = false;
    
    std::deque<pattern> puzzle_deque;
    pattern *puzzle = new pattern;
    puzzle->current = init;
    puzzle->move = 0;
    puzzle->prev = NULL;

    puzzle_deque.push_back(*puzzle);
    
    while(!solved && (!puzzle_deque.empty()))
    {
        pattern *puzzle_last = new pattern;
        *puzzle_last = puzzle_deque.front();
        puzzle_deque.pop_front();
        if(is_recorded(*puzzle_last))
            continue;
        if(is_match(puzzle_last->current,target))
        {
            //输出结果
            stringstream result;
            while(puzzle_last->prev!= NULL)
            {
                
                result << puzzle_last->move;
                puzzle_last = puzzle_last->prev;

            }
            string solution = result.str();
            reverse(solution.begin(),solution.end());
            cout << "Solution:" << solution << endl;
            solved = true;
        }
        else
        {       
            for(int i = 1; i <= 9; i++)
            {
                pattern *puzzle_next = new pattern;
                puzzle_next->move = i;
                puzzle_next->current = new_state(puzzle_last->current, i);
                //note:reverse storage
                puzzle_next->prev = puzzle_last;
                puzzle_deque.push_back(*puzzle_next);
            }
        }
    }
    if(!solved)
        cout << "There is no solution:(";
    return 0;
}