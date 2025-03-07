#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int a, b, c;

    int u, v;
    
    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter b: ";
    std::cin >> b;
    std::cout << "Enter c: ";
    std::cin >> c;
    std::cout << "Your equation: " << a << "x + " << b << "y = " << c << endl;
    vector<int> list;
    int i = 1;
    int gcd, l, m;
    if(a > b)
    {
        m = a;
        gcd = b;
    }
    else
    {
        m = b;
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
    std::cout << "gcd = " << gcd << endl;
    
    string matrix[3][i+2];
    if(c % gcd == 0)
    {
        std::cout << c << "⋮" << gcd << " => There is solution" << endl;
        std::cout << a/gcd << "x + " << b/gcd << "y = " << c/gcd << endl;
        
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
        if(a > b)
        {
            std::cout << gcd << " = " << a << "*" << u << " + " << b << "*" << v << std::endl;
            std::cout << "1 = " << a/gcd << "*" << u << " + " << b/gcd << "*" << v << std::endl;
            std::cout << "x0 = " << c/gcd << "*" << u << " = " << (c/gcd)*u << std::endl;
            std::cout << "y0 = " << c/gcd << "*" << v << " = " << (c/gcd)*v << std::endl;
            std::cout << "x = " << (c/gcd)*u << " + " << b/gcd << "t" << std::endl;
            std::cout << "y = " << (c/gcd)*v << " - " << a/gcd << "t" << std::endl;
        }
        else
        {
            std::cout << gcd << " = " << a << "*" << v << " + " << b << "*" << u << std::endl;
            std::cout << "1 = " << a/gcd << "*" << v << " + " << b/gcd << "*" << u << std::endl;
            std::cout << "x0 = " << c/gcd << "*" << v << " = " << (c/gcd)*v << std::endl;
            std::cout << "y0 = " << c/gcd << "*" << u << " = " << (c/gcd)*u << std::endl;
            std::cout << "x = " << (c/gcd)*v << " + " << b/gcd << "t" << std::endl;
            std::cout << "y = " << (c/gcd)*u << " - " << a/gcd << "t" << std::endl;
        }
    }
    else
    {
        std::cout << c << "⋮" << gcd << " => There is no solution" << endl;
    }
    return 0;
}
