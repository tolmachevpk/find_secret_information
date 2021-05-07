#ifndef FIND_SECRET_INFORMATION_READ_FILES_H
#define FIND_SECRET_INFORMATION_READ_FILES_H

#include <fstream>

using namespace std::literals::string_literals;

class Read_bytes {
public:
    std::string read(const std::string &name);

private:
    void read_file(std::ifstream &fin, std::string &res);
};

#endif //FIND_SECRET_INFORMATION_READ_FILES_H
