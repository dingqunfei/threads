/**
 * @file 1_1.cpp
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

void hello(int i)
{
    std::cout << "hello " << i << ", concurrency world." << std::endl;
}

int main(int argc, char** argv)
{
    for(int i = 0; i < 10; ++i)
    {
        std::thread t(hello, i);
        t.join();
    }
    return 0;
}