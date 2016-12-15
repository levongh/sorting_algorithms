#pragma once

/**
 * @file   quick_sort.hpp
 * @author Levon Ghukasyan
 * @date   16 Nov 2015
 */


namespace my
{
    template <class T>
    void swap ( T& first, T& second )
    {
        T c(first);
        first = second;
        second = c;
    }
}

template<typename T, typename Iter>
Iter partition(T array, Iter first, Iter last)
{
    Iter pivot = last;
    Iter firsthigh = first;

    for (Iter i = first; i < last; i++) {
        if (array[i] <= pivot) {
            firsthigh++;
        }
        my::swap(array[i], array[firsthigh]);
    }
    my::swap(array[firsthigh], array[last]);
    return firsthigh;
}

template<typename T, typename Iter>
void quick_sort(T array, Iter first, Iter last)
{
    if(first < last)
    {
        Iter pivot = partition(array, first, last);
        quick_sort(array, first, pivot - 1);
        quick_sort(array, pivot, last);
    }
    return;
}

