#include <iostream>
#include <vector>
#include <iterator>
#include "polynom.h"
#include "transfer.h"


template<typename type, typename func>
bool all_of(type start, type end, func pred)
{
    for (; start != end; ++start)
    {
        if (!pred(*start))
            return false;
    }
    return true;
}

template<typename type, typename func>
bool any_of(type start, type end, func pred)
{
    for (; start != end; ++start)
    {
        if (pred(*start))
            return true;
    }
    return false;
}

template<typename type, typename func>
bool none_of(type start, type end, func pred)
{
    for (; start != end; ++start)
    {
        if (pred(*start))
            return false;
    }
    return true;
}

template<typename type, typename func>
bool one_of(type start, type end, func pred)
{
    int cnt = 0;
    for (; start != end; ++start)
    {
        if (pred(*start))
            ++cnt;
        if (cnt > 1)
            return false;
    }
    if(cnt == 1)
        return true;
    return false;
}

template<typename type, typename func>
bool is_sorted(type start, type end, func comp = std::less())
{
    int cnt = 0;
    for (; start != end; ++start)
    {
        if (start + 1 == end)
            break;
        if (!comp(*start, *(start + 1)))
            return false;
    }
    return true;
}

template<typename type, typename func>
bool is_partitioned(type start, type end, func pred)
{
    bool check;
    if (start == end)
        return true;
    check = pred(*start);
    for (; start != end; ++start)
    {
        if (pred(*start) != check)
            break;
    }
    ++start;
    if (start == end)
        return true;
    check = pred(*start);
    for (; start != end; ++start)
    {
        if (pred(*start) != check)
            break;
    }
    if (start == end)
        return true;
    return false;
}

template<typename type, typename value>
type find_not(type start, type end, value ex)
{
    for (; start != end; ++start)
    {
        if (*start != ex)
            return start;
    }
    return end;
}

template<typename type, typename value>
type find_backward(type start, type end, value ex)
{
    type elem = end;
    for (; start != end; ++start)
    {
        if (*start == ex)
            elem = start;
    }
    return elem;
}

template<typename type, typename func>
bool is_palindrome(type start, type end, func pred)
{
    std::vector<bool> val;
    for (; start != end; ++start)
    {
        val.push_back(pred(*start));
    }
    for (int i = 0; i < val.size() / 2 + 1; ++i)
    {
        if (val[i] != val[val.size() - 1 - i])
            return false;
    }
    return true;
}

bool comparator5(int a)
{
    return (a > 5);
}

bool comparator(int a, int b)
{
    return (a < b);
}

bool comparatorCP(CPoint a, CPoint b)
{
    return (a.getX() < b.getX());
}

int main()
{
    std::vector<int> example1{ 1, 4, 2, 7, 88 };
    std::vector<int> example2{ 7, 6, 2, 7, 88 };
    std::vector<int> example3{ 7, 7, 7, 4, 88 };
    std::vector<CPoint> example4{ CPoint(1, 0), CPoint(4, 0), CPoint(2, 0), CPoint(7, 0), CPoint(8, 0) };
    std::cout << all_of(example1.begin(), example1.end(), comparator5) << std::endl;
    std::cout << one_of(example1.begin(), example1.end(), comparator5) << std::endl;
    std::cout << any_of(example1.begin(), example1.end(), comparator5) << std::endl;
    std::cout << *find_not(example3.begin(), example3.end(), 7) << std::endl;
    std::cout << is_sorted(example1.begin(), example1.end(), std::less<>()) << std::endl;
    std::cout << is_palindrome(example2.begin() + 1, example2.end() - 1, comparator5) << std::endl;
    std::cout << is_sorted(example4.begin(), example4.end(), comparatorCP) << std::endl;
    std::cout << is_sorted(example4.begin() + 2, example4.end(), comparatorCP) << std::endl;
}