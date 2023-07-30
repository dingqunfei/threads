/**
 * @file 2_1.cpp
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

#include<iostream>
#include<thread>

struct func{
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

int main()
{
    int loacl_state = 0;
    func my_func(loacl_state);
    std::thread my_thread(my_func);
    my_thread.join();
    return 0;
}