#pragma once

#include <vector>
#include <stdexcept>

namespace sorts {
    template <typename T>
    std::vector<T> CountingSort(const std::vector<T>& arr_orig) {
        // К сожалению только целые
        static_assert(std::is_integral<T>::value,
                    "CountingSort only supports integral types.");
        
        // Нужно ли вообще его сортировать
        if (arr_orig.size() <= 1) {
            return arr_orig;
        }

        //Смотрим на разброс
        T max = arr_orig[0];
        T min = arr_orig[0];
        for (size_t i = 1; i < arr_orig.size(); ++i) {
            if (arr_orig[i] < min) { min = arr_orig[i];} 
            else if (arr_orig[i] > max) { max = arr_orig[i];}
        };
        std::vector<size_t> count(max-min+1, 0);

        // Подсчёт количества каждого значения
        for (const T& val : arr_orig) {
            ++count[val-min];
        }

        // Формирование отсортированного результата
        std::vector<T> sorted;
        sorted.reserve(arr_orig.size());

        for (size_t i = 0; i < count.size(); ++i) {
            for (size_t j = 0; j < count[i]; ++j) {
                sorted.push_back(static_cast<T>(i+min));
            }
        }

        return sorted;
    }
}