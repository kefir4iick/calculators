#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a, b, n;
    int a1, b1, n1;
    int a2, b2, c;
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
        c = btemp;
        btemp = atemp % btemp;
        atemp = c;
    }
    while (ntemp != 0) {
        c = ntemp;
        ntemp = atemp % ntemp;
        atemp = c;
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
    std::cout << "gcd(" << a1 << ", " << b1 << ") = ";
    atemp = a1;
    btemp = b1;
    while (btemp != 0) {
        c = btemp;
        btemp = atemp % btemp;
        atemp = c;
    }
    gcd = atemp;
    std::cout << gcd;
    if(gcd > 1)
    {
        std::cout << " ( >1) => " << a1 / gcd << "x ≡ " << b1 / gcd << " mod " << n1 << std::endl;
        a2 = a1 / gcd;
        b2 = b1 / gcd;
    }
    else
    {
        a2 = a1;
        b2 = b1;
    }
    std::cout << "gcd(" << a2 << ", " << n1 << ") = ";
    atemp = a2;
    ntemp = n1;
    while (ntemp != 0) {
        c = ntemp;
        ntemp = atemp % ntemp;
        atemp = c;
    }
    gcd = atemp;
    std::cout << gcd << std::endl;
    if(gcd > 1)
    {
        std::cout << " ( >1) => there is no solution" << std::endl;
    }
    else
    {
        std::cout << a2 << "^(-1) mod " << n1 << std::endl;
        std::cout << "gcd(" << a2 << ", " << n1 << "):" << std::endl;
        vector<int> list;
        int i = 1;
        int l, m;
        int u, v;
        if(a2 > n1)
        {
            m = a2;
            gcd = n1;
        }
        else
        {
            m = n1;
            gcd = a2;
        }
        while(true)
        {
            l = m % gcd;
            if(l == 0)
            {
                break;
            }
            else {
                list.push_back((m - l)/gcd);
                std::cout << m << " = "<< gcd << "*" << (m - l)/gcd << "+" << l << " q" << i << " = " << (m - l)/gcd << endl;
                m = gcd;
                gcd = l;
                i = i + 1;
            }
        }
        std::cout << m << " = "<< gcd << "*" << (m - l)/gcd << " q" << i << " = " << (m - l)/gcd << endl;
        std::cout << "gcd = " << gcd << std::endl;

        string matrix[3][i+2];
        matrix[1][0] = 'u';
        matrix[2][0] = 'v';
        matrix[1][1] = '1';
        matrix[2][1] = '0';
        matrix[1][2] = '0';
        matrix[2][2] = '1';
        for(int j = 0; j < list.size(); j++)
        {
            matrix[0][j+2] = to_string(list[j]);
            matrix[1][j+3] = to_string(stoi(matrix[1][j+1])-stoi(matrix[0][j+2])*stoi(matrix[1][j+2]));
            matrix[2][j+3] = to_string(stoi(matrix[2][j+1])-stoi(matrix[0][j+2])*stoi(matrix[2][j+2]));
        }
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < i+2; k++)
            {
                std::cout << matrix[j][k] << "\t\t";
            }
            std::cout << endl;
        }
        
        u = stoi(matrix[1][i+1]);
        v = stoi(matrix[2][i+1]);
        if(a2 > n1)
        {
            std::cout << gcd << " = " << a2 << "*" << u << " + " << n1 << "*" << v << std::endl;
            if(u > 0)
            {
                std::cout << a2 << "^(-1) mod " << n1 << " = " << u << " mod " << n1 << " = " << u % n1 << std::endl;
                std::cout << "x0 = (" << u % n1 << " * " << b2 << ") mod " << n1 << " = " << ((u % n1) * b2) % n1 << std::endl;
                std::cout << "x = " << ((u % n1) * b2) % n1 << " + " << n1 << "k" << std::endl;
            }
            else
            {
                std::cout << a2 << "^(-1) mod " << n1 << " = " << u << " mod " << n1 << " = " << n1 + (u % n1) << std::endl;
                std::cout << "x0 = (" << n1 + (u % n1) << " * " << b2 << ") mod " << n1 << " = " << ((n1 + (u % n1)) * b2) % n1 << std::endl;
                std::cout << "x = " << ((n1 + (u % n1)) * b2) % n1 << " + " << n1 << "k" << std::endl;
            }
        }
        else
        {
            std::cout << gcd << " = " << a2 << "*" << v << " + " << n1 << "*" << u << std::endl;
            if(v > 0)
            {
                std::cout << a2 << "^(-1) mod " << n1 << " = " << v << " mod " << n1 << " = " << v % n1 << std::endl;
                std::cout << "x0 = (" << v % n1 << " * " << b2 << ") mod " << n1 << " = " << ((v % n1) * b2) % n1 << std::endl;
                std::cout << "x = " << ((v % n1) * b2) % n1 << " + " << n1 << "k" << std::endl;
            }
            else
            {
                std::cout << a2 << "^(-1) mod " << n1 << " = " << v << " mod " << n1 << " = " << n1 + (v % n1) << std::endl;
                std::cout << "x0 = (" << n1 + (v % n1) << " * " << b2 << ") mod " << n1 << " = " << ((n1 + (v % n1)) * b2) % n1 << std::endl;
                std::cout << "x = " << ((n1 + (v % n1)) * b2) % n1 << " + " << n1 << "k" << std::endl;
            }
        }
    }
}
