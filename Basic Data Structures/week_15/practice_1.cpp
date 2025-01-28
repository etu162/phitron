#include<bits/stdc++.h>
using namespace std;
class mystack{
    public:
    vector<int>v;
    void push(int val){
        v.push_back(val);
    }
    void pop(){
        v.pop_back();
    }
    int top(){
        return v.back();
    }
    int size(){
        return v.size();
    }
    bool empty(){
        return v.empty();
    }
};
int main(){
    mystack s1,s2;
    int n1,n2;
    cin>>n1;
    for(int i=0;i<n1;i++){
        int x;
        cin>>x;
        s1.push(x);
    }
    cin>>n2;
    for(int i=0;i<n2;i++){
        int x;
        cin>>x;
        s2.push(x);
    }
    if(n1!=n2){
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=0;i<n1;i++){
        if(s1.top()!=s2.top()){
            cout<<"NO"<<endl;
            return 0;
        }
        s1.pop();
        s2.pop();
    }
    cout<<"YES"<<endl;
    return 0;
}