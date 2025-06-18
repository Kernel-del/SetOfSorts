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
    std::vector<T> arr_tmp = {};
    T tmp = 0;
    T e = 0;
    bool minus = false;
    bool is_e=false;
    bool num_writing = false;

    for (size_t i = 0; i < argv.length(); ++i) {
        if (argv[i]>=48 && argv[i]<=57) {
            num_writing = true;
            is_e ? e = e * 10 + argv[i] - 48 :
                   tmp = tmp * 10 + argv[i] - 48;
        } else if (argv[i] == ' ' || argv[i] == '\n') {
            arr_tmp.push_back(minus ? -tmp * pow(10, e) : tmp * pow(10, e));
            tmp = 0; e = 0; minus = false; num_writing = false; is_e = false;
        } else if (argv[i] == '-') {
            minus=true;
        } else if (argv[i] == ',') {

        } else if (argv[i] == 'e') {
            is_e = true;
            e=0;
        } else {
            printf("\"%c\" не является поддерживаемым значением!\n", argv[i]);
            throw ;
        }
    }
    if (num_writing) arr_tmp.push_back(minus ? -tmp * pow(10, e) : tmp * pow(10, e));
    return arr_tmp;
}

std::string file_to_string(const std::string& file_name) {
    char buffer[256];
    std::string str;

    FILE *fp = fopen(file_name.c_str(), "r");
    if (fp) {
        while ((fgets(buffer, 245, fp))!=NULL) {
            str.append(buffer);
        }
        fclose(fp);
    }

    return str;
}

void string_to_file(const std::string& data, const std::string& file_name) {
    std::ofstream out(file_name, std::ios::binary);
    if (out) {
        out.write(data.data(), data.size());
        out.close();
    }
}