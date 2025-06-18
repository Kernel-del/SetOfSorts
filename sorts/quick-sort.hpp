#pragma once

#include <vector>

namespace sorts {
    template <typename T>
    std::vector<T> QuickSort(const std::vector<T>& arr_orig) {
        if (arr_orig.size() <= 1) {
            return arr_orig;
        }

        std::vector<T> less;
        std::vector<T> greater;
        T pivot = arr_orig[0];

        for (size_t i = 1; i < arr_orig.size(); ++i) {
            if (arr_orig[i] <= pivot) {
                less.push_back(arr_orig[i]);
            } else {
                greater.push_back(arr_orig[i]);
            }
        }

        std::vector<T> sorted_less = QuickSort(less);
        std::vector<T> sorted_greater = QuickSort(greater);

        sorted_less.push_back(pivot);
        sorted_less.insert(sorted_less.end(), sorted_greater.begin(), sorted_greater.end());
        return sorted_less;
    }
}