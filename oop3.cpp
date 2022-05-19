#pragma once

#include <iterator>
#include <functional>

//all_of - возвращает true, если все элементы диапазона удовлетворяют
//некоторому предикату. Иначе false
template<typename InputIterator, typename T>
bool allOf(InputIterator first, InputIterator last, T value) {
    for (first; first != last; ++first)
        if (value(*first) == 0)
            return false;
    return true;
}

//any_of - возвращает true, если хотя бы один из элементов диапазона
//удовлетворяет некоторому предикату. Иначе false
template<typename InputIterator, typename T>
bool anyOf(InputIterator first, InputIterator last, T value) {
    for (first; first != last; ++first)
        if (value(*first) == 1)
            return true;
    return false;
}

//none_of - возвращает true, если все элементы диапазона не удовлетворяют
//некоторому предикату. Иначе false
template<typename InputIterator, typename T>
bool noneOf(InputIterator first, InputIterator last, T value) {
    for (first; first != last; ++first)
        if (value(*first) == 1)
            return false;
    return true;
}

//one_of - возвращает true, если ровно один элемент диапазона удовлетворяет
//некоторому предикату. Иначе false
template<typename InputIterator, typename T>
bool oneOf(InputIterator first, InputIterator last, T value) {
    bool flag = false;

    for (first; first != last; ++first) {
        if (value(*first) == 1) {
            if (!flag)
                flag = true;
            else
                return false;
        }
    }
    return flag;
}

//is_sorted - возвращает true, если все элементы диапазона находятся в
//отсортированном порядке относительно некоторого критерия
template<typename inp, typename T = std::less<>>
bool isSorted(inp first, inp last, T value = T()) {
    inp one = first;
    inp two = ++first;

    while (two != last) {
        if (value(*one, *two) == 0)
            return false;
        ++one;
        ++two;
    }
    return true;
}

//is_partitioned - возвращает true, если в диапазоне есть элемент, делящий все
//элементы на удовлетворяющие и не удовлетворяющие некоторому предикату.
//Иначе false.
template<typename InputIterator, typename T>
bool isPartitioned(InputIterator first, InputIterator last, T value) {
    bool tempValue = value(*first);
    bool flag = false;
    ++first;

    for (first; first != last; ++first) {
        if (value(*first) != tempValue) {
            if (flag)
                return false;
            flag = true;
            tempValue = !tempValue;
        }
    }
    return true;
}

//find_not - находит первый элемент, не равный заданному
template<typename ForwardIt, typename T>
ForwardIt findNot(ForwardIt first, ForwardIt last, T value) {
    for (first; first != last; ++first)
        if (*first != value)
            return first;
    return last;
}

//find_backward - находит первый элемент, равный заданному, с конца
template<typename ForwardIt, typename T>
ForwardIt findBackward(ForwardIt first, ForwardIt last, T value) {
    ForwardIt resultLast = last;

    for (first; first != last; ++first)
        if (*first == value)
            resultLast = first;
    return resultLast;
}

// is_palindrome - возвращает true, если заданная последовательность является
//палиндромом относительно некоторого условия. Иначе false.
template<typename InputIterator, typename T>
bool isPalindrome(InputIterator first, InputIterator last, T value) {
    InputIterator right = first;
    --last;

    while (first != last && right != last) {
        if (value(*first, *last) == 0)
            return false;
        right = first;
        ++first;
        --last;
    }
    return true;
}
