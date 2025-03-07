#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a, n;
    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter n: ";
    std::cin >> n;
    std::cout << a << "^(-1) mod " << n << std::endl;
    std::cout << "gcd(" << a << ", " << n << "):" << std::endl;
    vector<int> list;
    int i = 1;
    int gcd, l, m;
    int u, v;
    if(a > n)
    {
        m = a;
        gcd = n;
    }
    else
    {
        m = n;
        gcd = a;
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
    std::cout << "gcd = " << gcd;
    
    if(gcd > 1)
    {
        std::cout << " ( > 1) => " << a << "^(-1) mod " << n << " does not exist"<< std::endl; 
    }
    else
    {
        std::cout << " ( = 1) => " << a << "^(-1) mod " << n << " exists"<< std::endl;
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
        if(a > n)
        {
            std::cout << gcd << " = " << a << "*" << u << " + " << n << "*" << v << std::endl;
            if(u > 0)
            {
                std::cout << a << "^(-1) mod " << n << " = " << u << " mod " << n << " = " << u % n << std::endl;
            }
            else
            {
                std::cout << a << "^(-1) mod " << n << " = " << u << " mod " << n << " = " << n + (u % n) << std::endl;
            }
        }
        else
        {
            std::cout << gcd << " = " << a << "*" << v << " + " << n << "*" << u << std::endl;
            if(v > 0)
            {
                std::cout << a << "^(-1) mod " << n << " = " << v << " mod " << n << " = " << v % n << std::endl;
            }
            else
            {
                std::cout << a << "^(-1) mod " << n << " = " << v << " mod " << n << " = " << n + (v % n) << std::endl;
            }
        }
    }
}
