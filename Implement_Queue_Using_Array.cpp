#include <bits/stdc++.h>
using namespace std;
class MyQueue{
    private:
        int *arr;
        int maxsize;
        int cursize;
        int front =- 1;
        int back=-1;
    public:
        MyQueue(){
            arr = new int[20];
            cursize = 0;
            maxsize = 20;
        }
        MyQueue(int maxsize){
        this->maxsize = maxsize;
        arr = new int[maxsize];
        cursize = 0;
        }
   void push(int data){
    if(cursize==maxsize) {
        cout << "the size of the queue is full" << endl;
        exit(1);
    }else if(back==-1){
        front = 0;
        back = 0;
    }
    else
        back = (back + 1) % maxsize;
    arr[back] = data;
    cursize++;
    cout << "The new added element is" << data << endl;

   }
   int pop(){
    if(front==-1){
        cout << "the queue is empty" << endl;
        exit(1);
    }
    int popped=arr[front];
    if(cursize==1){
        front = -1;
        back = -1;
    }else {
        front = (front + 1) % maxsize;
    }
    cout << "The popped element is " << popped << endl;
    cursize--;
    return popped;
   }
    bool isempty(){
        return front==-1;
   }
   int top(){
    if(front==-1){
        cout << "The queue is empty" << endl;
        exit(1);
    }
    return arr[front];

   }

   int size(){
       return cursize;
   }
};

int main(){
    MyQueue q(6);

    cout << "\n--- Pushing elements ---" << endl;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "\nFront element (top): " << q.top() << endl;
    cout << "Current size: " << q.size() << endl;

    cout << "\n--- Popping elements ---" << endl;
    cout << "Popped: " << q.pop() << endl;
    cout << "Popped: " << q.pop() << endl;

    cout << "\nFront element now: " << q.top() << endl;
    cout << "Current size: " << q.size() << endl;

    cout << "\nIs queue empty? " << (q.isempty() ? "Yes" : "No") << endl;

    cout << "\n--- Adding more elements ---" << endl;
    q.push(50);
    q.push(60);
    q.push(70);

    cout << "\nFront element: " << q.top() << endl;
    cout << "Final size: " << q.size() << endl;

    return 0;
}