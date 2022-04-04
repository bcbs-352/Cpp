#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
template <typename T>
class SharedPtr
{
    size_t *m_count; //为了多个智能指针共享引用数据
    T *m_ptr;

public:
    SharedPtr() : m_count(0), m_ptr(nullptr) {}
    SharedPtr(T *ptr) : m_ptr(ptr), m_count(new size_t) { *m_count = 1; }
    ~SharedPtr()
    {
        --(*m_count);
        if (m_count == 0)
        {
            delete m_count;
            delete m_ptr;
            m_count = nullptr;
            m_ptr = nullptr;
        }
    }
    SharedPtr(const SharedPtr &ptr)
    {
        if (this == &ptr)
            return;
        m_count = ptr.m_count;
        m_ptr = ptr.m_ptr;
        ++(*m_count);
    }
    SharedPtr &operator=(const SharedPtr &ptr)
    {
        // SharedPtr(std::move(ptr)); //只是移动过去赋个值
        if (this->m_ptr == ptr.m_ptr)
            return *this;
        if (this->m_ptr)
        {
            (*this->m_count)--; //原来指向的T计数就要-1
            if (*this->m_count == 0)
            {
                delete m_count;
                delete m_ptr;
            }
        }
        //然后再去指向新的T
        this->m_ptr = ptr.m_ptr;
        this->m_count = ptr.m_count;
        *m_count += 1;
        // SharedPtr(&ptr);
        return *this;
    }
    SharedPtr(SharedPtr &&ptr) : m_count(new size_t), m_ptr(ptr.m_ptr)
    {
        m_count = ptr.m_count;
        ++(*m_count);
    }
    void operator=(SharedPtr &&ptr)
    {
        SharedPtr(std::move(ptr));
    }
    T &operator*() { return this->*m_ptr; }
    T &operator->() { return this->*m_ptr; }
    T *get()
    {
        return this->m_ptr;
    }
    bool unique() { return *m_count == 1; }
    int use_count() { return *m_count; }
    void swap(SharedPtr &ptr) { std::swap(*this, ptr); }
};

int main()
{
    int *rp = new int;
    *rp = 1;
    // printf("%d\n", *rp);
    SharedPtr<int> p1(rp);
    std::cout << "p1" << p1.use_count() << std::endl;
    SharedPtr<int> p2;
    p2 = p1;
    std::cout << "p1" << p1.use_count() << std::endl;
    p2.~SharedPtr();
    std::cout << "p1" << p1.use_count() << std::endl;
    std::cout << "p2" << p2.use_count() << std::endl;
    return 0;
}