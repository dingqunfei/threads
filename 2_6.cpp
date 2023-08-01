#include<thread>
#include<iostream>
#include<utility>

class scoped_thread
{
public:
    explicit scoped_thread(std::thread t_):
        t(std::move(t_))
    {
        if(!t.joinable())
        {
            throw std::logic_error("No thread!");
        }
    }

    ~scoped_thread()
    {
        t.join();
    }

    scoped_thread(scoped_thread const&) = delete;
    scoped_thread& operator=(scoped_thread const &) = delete;

private:
    std::thread t;
};

void do_something(int& i)
{
    ++i;
    std::cout << i << std::endl;
}

struct func
{
    int& i;

    func(int& i_):i(i_){}

    void operator()()
    {
        for(unsigned j=0;j<1000000;++j)
        {
            do_something(i);
        }
    }
};

void do_something_in_current_thread()
{}

int main()
{
    int some_local_state = -1000;
    scoped_thread t((std::thread(func(some_local_state))));
    do_something_in_current_thread();
    
    return 0;
}