#pragma once

#include "../sorts.hpp"
#include "io-arr.hpp"
#include "example-configuration.hpp"

#include <stdio.h>
#include <vector>
#include <functional>
#include <iostream>


namespace options_list {
    namespace info {
        void get_help() {
            printf(
                "Эта программа является сборником сортировок\n\n"

                "Посмотреть информацию о программе:\n"
                    "\t--help(-h) — Вызывает меню помощи\n"
                    "\t--version(-v) — показывает версию\n"
                    "\t--type-list(-TL) — выводит список поддерживаемых сортировок\n"
                "Основные функции:\n"
                    "\t--type(-t) выбирает режим сортировки указанный после\n"
                    "\t--sort(-s) сортирует массив\n"
                    "\tВвод(поддерживает только один за раз):\n"
                        "\t\t--input(-i) \"...\" — копирует числа в кавычках\n"
                        "\t\t--input-file(-IF) — копирует числа в файле указанном после\n"
                        "\t\t--import-file(-ImF) — копирует числа в файле указанном после\n"
                        "\t\t--input-random(-IR) — заполняет массив случайными цифрами,\n"
                        "\t\t                      |сначало пишите количество, затем min.val. и max.val."
                        ""\
                    "\tВывод:\n"
                        "\t\t--output(-o) — выводит массив\n"
                        "\t\t--output-file(-OF) — сохроняет массив в файл\n"
                        "\t\t--export-file(-EF) — сохроняет массив в файл в более компактном виде,\n"
                        "\t\t                     |где первые 8 byte это длина чисел,\n"
                        "\t\t                     |а дальше идут сами числа со смещением\n"
            );
        }

        void get_version() {
            printf("Версия — 0.12\n");
        }

        void get_type_list() {
            printf(
                "Сортировки:\n"
                    "\tO(n + K):\n"
                        "\t\tcounting-sort — (https://en.wikipedia.org/wiki/Counting_sort)\n"
                    "\tO(n * log n):\n"
                        "\t\tmerge-sort — (https://en.wikipedia.org/wiki/Merge_sort)\n"
                    "\tO(n ^ 2):\n"
                        "\t\tquick-sort — (https://en.wikipedia.org/wiki/Quicksort)\n"
                        "\t\tbubble-sort — (https://en.wikipedia.org/wiki/Bubble_sort)"
                        "\t\tinsertion-sort — (https://en.wikipedia.org/wiki/Insertion_sort)"
                        "\t\tcocktail-sort — (https://en.wikipedia.org/wiki/Cocktail_shaker_sort)\n"
            );
        }
    }
    namespace func {
        void set_type(std::string type) {
            auto type_search = sort_list.find(type);
            if (type_search != sort_list.end()) {
                type_sort = type_search->second;
            } else {
                printf("Нет такой сортировки %s в базе данных!\n", type.c_str());
                throw ;
            }
        }

        void sort() {
            arr = type_sort(arr);
        }

        void export_file(const std::string& file_name) {
            std::string str_tmp;
            char type_size = sizeof(type_num);
            str_tmp.reserve(1 + sizeof(type_num) * arr.size());

            str_tmp.append(reinterpret_cast<const char*>(&type_size), sizeof(type_size));
            
            for (type_num i : arr) {
                str_tmp.append(reinterpret_cast<const char*>(&i), sizeof(i));
            }
            
            string_to_file(str_tmp, file_name);
        }

        void output() {
            print(arr); putchar('\n');
        }

        void output_file(std::string file_name) {
            std::string str_tmp = "";
            
            for (type_num i : arr) {
                str_tmp.append(std::to_string(i) + '\n');
            }
            string_to_file(str_tmp, file_name);
        }

        void input(std::string argv) {
            arr = string_to_num<type_num>(argv);
        }

        void input_random(std::string argv) {
            std::vector<int64_t> arr_tmp = string_to_num<int64_t>(argv);
            size_t count = static_cast<size_t>(arr_tmp[0]);
            type_num min_num = arr_tmp[1];
            type_num max_num = arr_tmp[2];

            std::srand(static_cast<unsigned>(std::time(nullptr)));
            arr.clear();
            arr.reserve(count);
            for (size_t i = 0; i < count; ++i) {
                arr.push_back((rand()%(max_num+1-min_num))+min_num);
            }
        }

        void input_file(std::string file_name) {
            std::string str = file_name.c_str();
            str = file_to_string(str);
            arr = string_to_num<type_num>(str);
        }

        void import_file(std::string file_name) {
            arr = {};
            u_int8_t num_byte_size;

            FILE *fp = fopen(file_name.c_str(), "r");
            if (fread(&num_byte_size, 1, 1, fp) == 1) {
                u_int8_t buffer[8];  // поддержка до 8 байт на число

                while (fread(buffer, 1, num_byte_size, fp) == num_byte_size) {
                    type_num value = 0;
                    std::memcpy(&value, buffer, num_byte_size);
                    arr.push_back(value);
                }   
            }
        }
    }
}