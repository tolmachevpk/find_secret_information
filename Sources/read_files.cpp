#include "../Headers/read_files.h"
#include <iostream>

std::string Read_bytes::read(const std::string &name) {
    std::string res = ""s;
    std::ifstream fin;

    if (std::filesystem::is_directory(name)) {
        for (const auto & entry: std::filesystem::directory_iterator(name)) {
            if (std::filesystem::is_directory(entry.path())) {
                perror("directory in directory");
            }

            fin.open(entry.path(), std::ios::binary | std::ios::in);
            if (!fin.is_open()) {
                char status;
                std::cout << "file open failed: "  << entry.path() <<
                          "\nPress [c] to continue or [e] to exit program: ";
                std::cin >> status;
                if (status == 'e') {
                    exit(0);
                } else {
                    if (status == 'c'){
                        continue;
                    } else {
                        perror("You made mistake");
                    }
                }
            } else {
                Read_bytes::read_file(fin, res);
            }
            fin.close();
        }
        return res;
    } else {
        fin.open(name, std::ios::binary | std::ios::in);
        if (!fin.is_open()) {
            perror("file open failed");
        } else {
            Read_bytes::read_file(fin, res);
        }
        fin.close();
    }

    return res;
}

void Read_bytes::read_file(std::ifstream &fin, std::string &res) {
    for (;;) {
        char c;
        if (fin.get(c)) {
            res.push_back(c);
        } else {
            break;
        }
    }
}
