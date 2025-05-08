//
// Created by 王强 on 25-5-8.
//

#include "threadpool.h"
#include <future>
#include <thread>
#include <functional>
#include <chrono>

int sum1(int a, int b){
    std::this_thread::sleep_for(std::chrono::seconds(3));
    return a + b;

}

int sum2(int a, int b, int c){

    std::this_thread::sleep_for(std::chrono::seconds(3));
    return a + b + c;
 }

int main(){

    ThreadPool pool;
    //pool.setMode(PoolMode::MODE_CACHED);
    pool.start(2);
    std::future<int> r1=pool.submitTask(sum2,1,2,3);
    std::future<int> r2=pool.submitTask(sum1,2,3);
    std::future<int> r3=pool.submitTask([](int a,int b)->int {
        int sum=0;
        for(int i=a;i<=b;i++) {
            sum+=i;
        }
        return sum;
    },1,100);
    std::future<int> r4=pool.submitTask([](int a,int b)->int {
        int sum=0;
        for(int i=a;i<=b;i++) {
            sum+=i;
        }
        return sum;
    },1,100);
    std::future<int> r5=pool.submitTask([](int a,int b)->int {
        int sum=0;
        for(int i=a;i<=b;i++) {
            sum+=i;
        }
        return sum;
    },1,100);


    std::cout << r1.get() << std::endl;
    std::cout << r2.get() << std::endl;
    std::cout << r3.get() << std::endl;
    std::cout << r4.get() << std::endl;
    std::cout << r5.get() << std::endl;

    // std::packaged_task<int(int,int)> task(sum1);
    //
    // std::future<int> res = task.get_future();
    //
    // std::thread t(std::move(task),10,20);
    //
    // std::cout << res.get() << std::endl;

 }