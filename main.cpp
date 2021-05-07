#include "Headers/read_files.h"
#include "Headers/aho_corasick.h"
#include <iostream>

using namespace std;

int main(int ac, char * av[]) {
    if (ac != 3) {
        perror("Bad input");
    }
    string dir_path = av[1];
    string file_in_dir_path = dir_path;
    if (dir_path[dir_path.length()] == '/') {
        file_in_dir_path += av[2];
    } else {
        file_in_dir_path += "/";
        file_in_dir_path += av[2];
    }

    string dir;
    string file_in_dir;
    Read_bytes reader;
    dir = reader.read(dir_path);
    file_in_dir = reader.read(file_in_dir_path);

    AhoKorasik *alg = new AhoKorasik(file_in_dir);
    alg->algorithmRealization(dir);
}
