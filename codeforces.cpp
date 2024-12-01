#include <bits/stdc++.h>
using namespace std;


std::mutex m;
std::condition_variable cv;
deque<int> buffer;

int max_capacity = 100;

void producer(int val)
{
    while(val)
    {
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock , []() {return buffer.size() <= max_capacity;});
        buffer.push_back(val);
        cout<<"Produced : "<<val<<endl;
        val--;
        lock.unlock();
        cv.notify_one();
    }

}

void consumer()
{
    while(true)
    {
    std::unique_lock<std::mutex> lock(m);
    cv.wait(lock, []() {return buffer.size() > 0;});
    int val = buffer.back();
    buffer.pop_back();
    cout<<"Consumed : "<<val<<endl;
    lock.unlock();
    cv.notify_one();
}

}



int main()
{
    std::thread t1(producer, 100);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}