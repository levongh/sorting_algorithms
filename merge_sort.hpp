#pragma once

/**
 * @file   quick_sort.hpp
 * @author Levon Ghukasyan
 * @date   16 Nov 2015
 */

template<typename T, typename Iter>
void merge(T *array, Iter first, Iter mid, Iter last)
{
    int * temp = new int[last+1-first];

    Iter low_up = first;
    Iter i=0;
    Iter mid_up=mid+1;
    Iter cur;

    while (low_up <= mid && mid_up <= last) {
        if (array[low_up] <= array[mid_up]) {
            temp[i]=array[low_up];
            ++low_up;
        } else {
            temp[i]=array[mid_up];
            ++mid_up;
        }
        ++i;
    }

    if (low_up > mid) {
        for (cur = mid_up; cur <= last; ++cur) {
            temp[i]=array[cur];
            ++i;
        }
    } else {
        for (cur = low_up; cur <= mid; ++cur) {
            temp[i] = array[cur];
            ++i;
        }
    }
    for (cur = 0; cur <= last-first; ++cur) {
        array[cur+first] = temp[cur];
    }
    delete[] temp;
}


template<typename T, typename Iter>
void merge_sort(T *array, Iter first, Iter last)
{
    if (first < last) {
        Iter mid = (last + first) / 2;
        merge_sort(array, first, mid);
        merge_sort(array, mid + 1, last);
        merge(array, first, mid, last);
    }
    return;
}
