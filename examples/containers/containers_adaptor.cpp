 #include <iostream>
#include <stack>
#include <queue>
#include <vector>

// Container adaptors are not full container classes, but wrappers that provide a specific interface on top of other containers.

void container_adaptors()
{
    std::cout << "\n--- Container Adaptors ---" << std::endl;

    // std::stack: LIFO
    std::cout << "\n[Stack]" << std::endl;
    std::stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    while (!st.empty())
    {
        std::cout << st.top() << " ";
        st.pop();
    }
    std::cout << std::endl;

    // std::queue: FIFO
    std::cout << "\n[Queue]" << std::endl;
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    while (!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;

    // std::priority_queue: Elements are ordered by priority.
    std::cout << "\n[Priority Queue]" << std::endl;
    std::priority_queue<int> pq;
    pq.push(30);
    pq.push(100);
    pq.push(25);
    while (!pq.empty()) {
        std::cout << pq.top() << " "; // Largest element has highest priority
        pq.pop();
    }
    std::cout << std::endl;
}

int main()
{
    container_adaptors();
    return (0);
}