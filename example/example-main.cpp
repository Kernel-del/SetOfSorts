#include "example-configuration.hpp"
#include "example-options.hpp"

#include <unordered_map>
#include <functional>
#include <string>


int main(int argc, char** argv) {
    #ifdef DEBUG
        printf("[DEBUG] Program started with the following parameters:\n");
        for (char** i = argv; i < argv+argc-1; ++i) printf("\t\"%s\"\n", *i);
    #endif

    const std::unordered_map<std::string, std::function<void()>> options_noparam = {
        {"--help", options_list::info::get_help},
        {"-h", options_list::info::get_help},
        {"hel", options_list::info::get_help},
        {"h", options_list::info::get_help},

        {"--version", options_list::info::get_version},
        {"-v", options_list::info::get_version},
        {"version", options_list::info::get_version},
        {"v", options_list::info::get_version},

        {"--type-list", options_list::info::get_type_list},
        {"-TL", options_list::info::get_type_list},
        {"type-list", options_list::info::get_type_list},
        {"TL", options_list::info::get_type_list},

        {"--sort", options_list::func::sort},
        {"-s", options_list::func::sort},
        {"sort", options_list::func::sort},
        {"s", options_list::func::sort},

        {"--output", options_list::func::output},
        {"-o", options_list::func::output},
        {"output", options_list::func::output},
        {"o", options_list::func::output},
    };
    const std::unordered_map<std::string, std::function<void(std::string)>> options_oneparam = {
        {"--type", options_list::func::set_type},
        {"-t", options_list::func::set_type},
        {"type", options_list::func::set_type},
        {"t", options_list::func::set_type},
        
        {"--input", options_list::func::input},
        {"-i", options_list::func::input},
        {"input", options_list::func::input},
        {"i", options_list::func::input},
        
        {"--input-random", options_list::func::input_random},
        {"-IR", options_list::func::input_random},
        {"input-random", options_list::func::input_random},
        {"IR", options_list::func::input_random},

        {"--input-file", options_list::func::input_file},
        {"-IF", options_list::func::input_file},
        {"input-file", options_list::func::input_file},
        {"IF", options_list::func::input_file},


        {"--import-file", options_list::func::import_file},
        {"-ImF", options_list::func::import_file},
        {"import-file", options_list::func::import_file},
        {"ImF", options_list::func::import_file},

        {"--output-file", options_list::func::output_file},
        {"-OF", options_list::func::output_file},
        {"output-file", options_list::func::output_file},
        {"OF", options_list::func::output_file},

        {"--export-file", options_list::func::export_file},
        {"-EF", options_list::func::export_file},
        {"export-file", options_list::func::export_file},
        {"EF", options_list::func::export_file},
    };

    if (argc == 1) {
        options_list::info::get_help();
    }
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        auto func = options_noparam.find(arg);
        if (func != options_noparam.end()) {
            func->second();
        } else {
            auto func = options_oneparam.find(arg);
            if (func != options_oneparam.end()) {
                if (++i >= argc) {
                    options_list::info::get_help();
                    printf("Missing parameter in function '%s'!\n", argv[i-1]);
                    return 1;
                }
                
                std::string param_string = std::string(argv[i]);

                if (param_string[0] == '(') {
                    param_string = param_string.substr(1);
                    if (param_string.back() == ')') { param_string = param_string.substr(0, arg.length()-1);}
                    else {
                        ++i;
                        for (; i < argc; ++i) {
                            std::string arg = argv[i];

                            if (!arg.empty() && arg.back() == ')') {
                                param_string = param_string + ' ' + arg.substr(0, arg.length()-1);
                                break;
                            } else if (arg.empty()) {} else {
                                param_string = param_string + ' ' + arg;
                            }
                        }
                    }
                }

                #ifdef DEBUG
                    printf("#[DEBUG] Received parameter for function \"%s\": \"%s\"\n", arg.c_str(), param_string.c_str());
                #endif
                func->second(param_string);
            } else {
                options_list::info::get_help();
                printf("Function '%s' not found!\n", argv[i]);
                return 1;
            }
        }
    }

    
    return 0;
}