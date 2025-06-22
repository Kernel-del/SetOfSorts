#pragma once

#include <vector>
#include <utility>

namespace sorts {
    template <typename T>
    std::vector<T> InsertionSort(const std::vector<T>& arr_orig) {
        std::vector<T> arr = arr_orig;

        for (size_t i = 1; i < arr.size(); ++i) {
            for (size_t j = i; j > 0; --j) {
                if (arr[j-1] > arr[j]) {
                    std::swap(arr[j-1], arr[j]);
                } else {
                    break;
                }
            }
        }

        return arr;
    }
}