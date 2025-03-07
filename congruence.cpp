#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a, b, n;
    int a1, b1, n1;
    int atemp, btemp, ntemp;
    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter b: ";
    std::cin >> b;
    std::cout << "Enter n: ";
    std::cin >> n;
    atemp = a;
    btemp = b;
    ntemp = n;
    std::cout << a << "x ≡ " << b << " mod " << n << std::endl;
    std::cout << "gcd(" << a << ", " << b << ", " << n << ") = ";
    while (btemp != 0) {
        int с = btemp;
        btemp = atemp % btemp;
        atemp = с;
    }
    while (ntemp != 0) {
        int с = ntemp;
        ntemp = atemp % ntemp;
        atemp = с;
    }
    int gcd = atemp;
    std::cout << gcd;
    if(gcd > 1)
    {
        std::cout << " ( >1) => " << a / gcd << "x ≡ " << b / gcd << " mod " << n / gcd << std::endl;
        a1 = a / gcd;
        b1 = b / gcd;
        n1 = n / gcd;
    }
    else
    {
        a1 = a;
        b1 = b;
        n1 = n;
    }
}
