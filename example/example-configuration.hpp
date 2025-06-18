#pragma once

#include "../sorts.hpp"

#include <vector>
#include <functional>


using type_num = int32_t;

const std::unordered_map<std::string, std::function<std::vector<type_num>(const std::vector<type_num>&)>> sort_list = {
    {"counting-sort", sorts::CountingSort<type_num>},
    {"quick-sort", sorts::QuickSort<type_num>},
    {"bubble-sort", sorts::BubbleSort<type_num>},
};


std::function<std::vector<type_num>(const std::vector<type_num>&)> type_sort = sorts::QuickSort<type_num>;

std::vector<type_num> arr; 