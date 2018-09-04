#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Toast
{
public:
   int bread;
   int butter;

   Toast(int brd, int bur): bread(brd), butter(bur)
   {

   }      
};

//
// We need to offer C++ a way to compare Toast instances.
// This is done by creating a structure implementing an operator ()
// and effectively doing a less-than comparision.
//
struct ToastCompare
{
    bool operator()(const Toast &t1, const Toast &t2) const
    {
        int t1Value = t1.bread * 1000 + t1.butter;
        int t2Value = t2.bread * 1000 + t2.butter;
        return t1Value < t2Value; 
    }
};

int main()
{
    priority_queue<Toast, vector<Toast>, ToastCompare> queue;
    queue.push(Toast(2, 200));
    queue.push(Toast(1, 30));
    queue.push(Toast(1, 10));
    queue.push(Toast(3, 1));

    while(queue.empty() == false)
    {
        Toast t = queue.top();
        cout << "bread " << t.bread << " butter " << t.butter << endl;
        queue.pop();
    }

    return 0;
}

 
