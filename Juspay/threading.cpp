#include <bits/stdc++.h> 
#include <thread>
using namespace std;
using namespace std::chrono;
int even = 0;
int odd = 0;

void eve(int st, int en){
    for(int i=st;i<=en;i++){
        if(i%2==0)even++;
    }
}
void od(int st, int en){
    for(int i=st;i<=en;i++){
        if(i%2)odd++;
    }
}

int main(){
    int st = 1;
    int en = 19000000000;
    auto starttime = high_resolution_clock::now();
     thread t1(eve,st,en);
     thread t2(od,st,en);
     t1.join();
     t2.join();
    //  eve(st,en);
    //  od(st,en);
    auto endtime = high_resolution_clock::now();
     auto dur = duration_cast<microseconds> (endtime-starttime);
     cout<<dur.count()/1000000<<endl;
     cout<<odd<<endl;
     cout<<even<<endl;
    
    
}