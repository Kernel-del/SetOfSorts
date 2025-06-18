#pragma once


#include <vector>

namespace sorts {
    template <typename T>
    std::vector<T> BubbleSort(const std::vector<T>& arr_orig) {
        std::vector<T> arr = arr_orig;
        bool sorted = false;

        while (!sorted) {
            sorted = true;
            for (size_t i = 1; i < arr.size(); ++i) {
                if (arr[i-1] > arr[i]) {
                    T tmp = arr[i];
                    arr[i] = arr[i-1];
                    arr[i-1] = tmp;
                    sorted = false;
                }
            }
        }

        return arr;
    }
}