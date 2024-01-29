// Author : Shubham Chaudhari
// Date : 29/01/2024
// Problem : 232. Implement Queue using Stacks
// Difficulty : Easy
// Problem Link : https://leetcode.com/problems/implement-queue-using-stacks/description/?envType=daily-question&envId=2024-01-29
// Video Solution : 
// Code:

class MyQueue {
public:
    stack<int> first, second;
    MyQueue() {
    }
    
    void push(int x) {
        while(!first.empty()){
            second.push(first.top());
            first.pop();
        }
        first.push(x);
        while(!second.empty()){
            first.push(second.top());
            second.pop();
        }
    }
    
    int pop() {
        int n = first.top();
        first.pop();
        return n;
    }
    
    int peek() {
        return first.top();
    }
    
    bool empty() {
        return first.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
