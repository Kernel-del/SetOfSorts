#pragma once

#include <vector>
#include <utility>


namespace sorts {
    namespace _default_ {
        template <typename T> 
        size_t medianOfThree(const std::vector<T>& arr_orig) {
            size_t min = 0;
            size_t mid = arr_orig.size()/2;
            size_t max = arr_orig.size()-1;

            if (arr_orig[min] > arr_orig[mid]) { std::swap(min, mid); }
            if (arr_orig[min] > arr_orig[max]) { std::swap(min, max); }
            if (arr_orig[mid] > arr_orig[max]) { std::swap(mid, max); }

            return mid;
        }
    }
    template <typename T>
    std::vector<T> QuickSort(const std::vector<T>& arr_orig) {
        if (arr_orig.size() <= 1) {
            return arr_orig;
        }

        std::vector<T> less;
        std::vector<T> greater;
        size_t pivot_index = _default_::medianOfThree<T>(arr_orig);
        T pivot = arr_orig[_default_::medianOfThree<T>(arr_orig)];

        for (size_t i = 0; i < arr_orig.size(); ++i) {
            if (i == pivot_index) continue; // пропускаем сам pivot только один раз
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