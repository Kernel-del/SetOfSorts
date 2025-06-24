#pragma once

#include <vector>
#include <utility>
#include "../example/io-arr.hpp"

namespace sorts {
    template <typename T>
    std::vector<T> CocktailSort(const std::vector<T>& arr_orig) {
        std::vector<T> arr = arr_orig;
        bool sorted = false;
        bool is_left_to_right = true;

        size_t il = 0;
        size_t ir = arr.size() - 1;
        while (!sorted) {
            sorted = true;
            // Проход слева направо
            for (size_t i = il; i < ir; ++i) {
                if (arr[i] > arr[i + 1]) {
                    std::swap(arr[i], arr[i + 1]);
                    sorted = false;
                }
            }
            --ir;
            if (sorted) break;

            sorted = true;
            // Проход справа налево
            for (size_t i = ir; i > il; --i) {
                if (arr[i] < arr[i - 1]) {
                    std::swap(arr[i], arr[i - 1]);
                    sorted = false;
                }
            }
            ++il;
        }
        return arr;
    }
}