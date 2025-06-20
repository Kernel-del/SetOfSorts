#pragma once

#include <vector>
#include <utility>

namespace sorts {
    template <typename T>
    std::vector<T> BubbleSort(const std::vector<T>& arr_orig) {
        std::vector<T> arr = arr_orig;
        bool sorted = false;

        for (size_t i = 1; i < arr.size() && !sorted; ++i) {
            sorted = true;
            for (size_t j = 1; j < arr.size()-i+1; ++j) {
                if (arr[j-1] > arr[j]) {
                    std::swap(arr[j-1], arr[j]);
                    sorted = false;
                }
            }
        }

        return arr;
    }
}