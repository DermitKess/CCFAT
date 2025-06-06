#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file>\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "Error: can't open file " << argv[1] << "\n";
        return 1;
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    std::string tmpfile = "/tmp/ccfat_tmp_" + std::to_string(getpid());
    std::ofstream tmp(tmpfile);
    tmp << content;
    tmp.close();

    const char* waylandDisplay = std::getenv("WAYLAND_DISPLAY");
    int result;
    if (waylandDisplay) {
        result = system(("wl-copy < " + tmpfile).c_str());
        if (result != 0) {
            std::cerr << "Error: wl-copy isn't working. Install wl-clipboard.\n";
            remove(tmpfile.c_str());
            return 1;
        }
    } else {
        // X11 (xclip)
        result = system(("xclip -selection clipboard < " + tmpfile).c_str());
        if (result != 0) {
            std::cerr << "Error: xclip isn't working. Install xclip.\n";
            remove(tmpfile.c_str());
            return 1;
        }
    }

    remove(tmpfile.c_str());
    std::cout << "Copied successfully!\n";
    return 0;
}
