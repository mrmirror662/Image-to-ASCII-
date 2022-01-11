#include <stdint.h>
#include<iostream>
#include<string>
#include<fstream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
char as[10]{
'#'
,'#'
,'*'
,'*'
,'*'
,'*'
,'*'
,'.'
,'.'
,'.'
    };
int main() {
    int width, height, bpp;
    using namespace std;
    string filename;
    cout << "enter img name:";
    getline(cin, filename);
    auto rgb_image = stbi_load(filename.c_str(), &width, &height, &bpp, 3);
    char* arr = new char[width * height];
    int counter = 0;
    for (int i = 0;i < width * height * 3;i += 3) {
        int r = (int)rgb_image[i], g = (int)rgb_image[i + 1], b = (int)rgb_image[i + 2];
        r /= 25;
        g /= 25;
        b /= 25;
        int avg = (r + b + g) / 3;
        if (avg == 0)avg++;

        arr[counter] = as[avg];
        counter++;
        }
    ofstream write("img.txt");
    int w = 0;
    for (int i = 0;i < width * height;i++) {
        if (i % 64 == 0) {
            cout << "\n";
            write << "\n";
            w++;
            };
        cout << arr[i] << " ";
        write << arr[i] << "";

        }
    write.close();
    stbi_image_free(rgb_image);
	cin.get();
    return 0;
    }
