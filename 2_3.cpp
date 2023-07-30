/**
 * @file 2_3.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2023-07-23
 * 
 * @copyright Copyright (c) 2023 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2023-07-23
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */

#include<thread>
#include<iostream>

struct func
{
    int& i;
    func(int& _i):
        i(_i)
    {

    }

    void operator()()
    {
        for(int j = 0; j < 1000000; ++j)
        {
            i = j;
            std::cout << i << std::endl;
        }
    }
};

class thread_guard
{
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_):
        t(t_)
    {
    }
    ~thread_guard()
    {
        if(t.joinable())
        {
            t.join();
        }
    }
    thread_guard(thread_guard const&) = delete;
    thread_guard& operator = (thread_guard const&) = delete;
};

int main()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread t(my_func);
    thread_guard g(t);


    return 0;
}