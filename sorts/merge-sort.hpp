#pragma once

#include <vector>
#include <math.h>

namespace sorts
{
    template <typename T>
    std::vector<T> MergeSort(const std::vector<T> &arr_orig)
    {

        if (arr_orig.size() <= 1) {
            return arr_orig;
        }
        else if (arr_orig.size() == 2) {
            if (arr_orig[0] > arr_orig[1]) {
                return { arr_orig[1], arr_orig[0] };
            } else {
                return arr_orig;
            }
        }

        size_t mid = arr_orig.size() / 2;
        std::vector<T> left(arr_orig.begin(), arr_orig.begin() + mid);
        std::vector<T> right(arr_orig.begin() + mid, arr_orig.end());

        left = MergeSort(left);
        right = MergeSort(right);

        std::vector<T> sorted;
        sorted.reserve(arr_orig.size());

        size_t il = 0, ir = 0;
        while (il < left.size() && ir < right.size())
        {
            if (left[il] < right[ir])
                sorted.push_back(left[il++]);
            else
                sorted.push_back(right[ir++]);
        }

        while (il < left.size()) sorted.push_back(left[il++]);
        while (ir < right.size()) sorted.push_back(right[ir++]);

        return sorted;
    }

}