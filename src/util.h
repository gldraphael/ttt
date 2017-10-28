#pragma once

template<typename T>
bool is_equal(T t1, T t2, T t3)
{
    return t1 == t2 && t2 == t3;
}