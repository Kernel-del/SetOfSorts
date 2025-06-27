#pragma once

#include <stdio.h>
#include <fstream>
#include <cstring>
#include <ctime>
#include <vector>
#include <stdexcept>
#include <math.h>


template<typename T>
void print(std::vector<T> arr) {
    for (T i : arr) {
        printf("%i ", i);
    }
}

template <typename T>
std::vector<T> string_to_num(std::string& argv) {
    std::vector<T> arr_tmp;
    T tmp = 0;
    T e = 0;
    bool minus = false;
    bool e_minus = false;
    bool is_e=false;
    bool num_writing = false;

    for (size_t i = 0; i < argv.length(); ++i) {
        char ch = argv[i];

        if (std::isdigit(ch)) {
            num_writing = true;
            if (is_e)
                e = e * 10 + (ch - '0');
            else
                tmp = tmp * 10 + (ch - '0');

        } else if (ch == ' ' || ch == '\n') {
            if (num_writing) {
                T value = tmp * std::pow(10, (e_minus ? -e : e));
                arr_tmp.push_back(minus ? -value : value);
                tmp = 0; e = 0; minus = false; e_minus = false; is_e = false; num_writing = false;
            }
        } else if (ch == '-') {
            is_e ? e_minus=true : minus=true;
        } else if (ch == '\''|| ch == '\t') {
            continue;
        } else if (ch == 'e' || ch == 'E') {
            is_e = true;
            e=0;
        } else {
            printf("'%c' is not a supported value!\n", argv[i]);
            throw std::invalid_argument("Unsupported character");
        }
    }
    if (num_writing) arr_tmp.push_back(minus ? -tmp * pow(10, e) : tmp * pow(10, e));
    return arr_tmp;
}

std::string file_to_string(const std::string& file_name) {
    std::ifstream file(file_name, std::ios::binary | std::ios::ate);
    if (!file) throw std::invalid_argument("No such file (" + file_name + ")");

    std::streamsize size = file.tellg();
    std::string str(size, '\0');
    file.seekg(0);
    file.read(&str[0], size);
    
    return str;
}

void string_to_file(const std::string& data, const std::string& file_name) {
    std::ofstream out(file_name, std::ios::binary);
    if (out) {
        out.write(data.data(), data.size());
        out.close();
    }
}