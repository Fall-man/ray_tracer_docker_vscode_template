#include <fstream>
#include <iostream>
#include <string>

int main() {

    std::ofstream out("output.ppm");
    std::streambuf *coutbuf = std::cout.rdbuf();  //save old buf
    std::cout.rdbuf(out.rdbuf());                 //redirect std::cout to out.txt!

    int nx = 200;
    int ny = 100;
    std::cout << "P3\n"
              << nx << " " << ny << "\n255\n";
    for (int j = ny - 1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {
            float r = float(i) / float(nx);
            float g = float(j) / float(ny);
            float b = 0.2;
            int ir = int(255.99 * r);
            int ig = int(255.99 * g);
            int ib = int(255.99 * b);
            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }

    std::cout.rdbuf(coutbuf);  //reset to standard output again

    return 0;
}
