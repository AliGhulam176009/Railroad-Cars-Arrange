// RailRoad.cpp : Defines the entry point for the console application.
#include <iostream>
#include <stack>
using namespace std;
 
 
// move cars from holding track to output track
void result(stack<int> t[],int n, int totalStack,int& min)
{
             //move car from holding track
    for(int x = 0;x < totalStack; ++x)
    {
        if(!t[x].empty() && t[x].top() == min)
        {
            cout << "car " << t[x].top() << " Move from H " << x << " to output" << endl;
            t[x].pop();
            ++min;
            x = -1; // find next car from the first holding track 0
        }
    }
}
 
// move cars from input track to holding track
bool Stack(stack<int> t[],int n , int totalStack)
{
    for(int i = 0;i < totalStack; ++i)
    {
        if(t[i].empty() || (!t[i].empty() && t[i].top() > n))
        {
            cout << "H " << i << " car hold " << n  << endl;
            t[i].push(n);
            return true; // we already find a holding track, so break the loop. 

        }

    }
    return false;
}

template <class T>
void display(T a[], const int & n)
{
    cout<<"pattren: ";
    for(int i = 0; i < n; ++i)
    {
        cout << a[i] << ",";
    }
    cout << "\n"<<endl;
}
 

int main(int argc, char* argv[])
{
    const int NUM = 9;
    const int STACKNUM = 3;
    stack<int> t[STACKNUM];
    int min = 1;
    int a[NUM] = {5,8,1,7,4,2,9,6,3};
    display(a,NUM);
    for(int i = NUM - 1; i >= 0; --i){
        if(a[i] == min)
        {// try to move cars from input track or holding track
            cout << "\ncar " << a[i] << " Move from input to output" << endl;
             ++min;
            result(t,a[i],STACKNUM,min);             
        }

        else
        {// move cars from input track to holding track
 
            if(!Stack(t,a[i],STACKNUM))
            {
                cout << "Not enough holding track" << endl;
                break;
            }       
       }
    }
    return min;
}
 
