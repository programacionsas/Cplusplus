#include <iostream>
#include <queue>
#include <stack>

int main()
{
    std::stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    std::cout << "Stack top: " << s.top() << "\n";

    s.pop();

    std::cout << "Stack top: " << s.top() << "\n";

    while (!s.empty())
    {
        std::cout << "Stack top: " << s.top() << "\n";
        s.pop();
    }

    std::queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    std::cout << "Queue front: " << q.front() << "\n";
    std::cout << "Queue back: " << q.back() << "\n";

    q.pop();

    std::cout << "Queue front: " << q.front() << "\n";

    while (!q.empty())
    {
        std::cout << "Queue front: " << q.front() << "\n";
        q.pop();
    }

    return 0;
}