#include <iostream>
#include <vector>
using namespace std;
int main() {
    int b1, b2, n1, n2;
    int u, v;
    std::cout << "Enter b1: ";
    std::cin >> b1;
    std::cout << "Enter b2: ";
    std::cin >> b2;
    std::cout << "Enter n1: ";
    std::cin >> n1;
    std::cout << "Enter n2: ";
    std::cin >> n2;
    std::cout << "x ≡ " << b1 << "(mod " << n1 << ")" << std::endl;
    std::cout << "x ≡ " << b2 << "(mod " << n2 << ")" << std::endl;
    std::cout << "gcd(" << n1 << ", " << n2 << "):" << std::endl;
    vector<int> list;
    int i = 1;
    int gcd, l, m;
    if(n1 > n2)
    {
        m = n1;
        gcd = n2;
    }
    else
    {
        m = n2;
        gcd = n1;
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
    int d;
    if(n1 > n2)
    {
        d = u*n1*b2 + v*n2*b1;
        std::cout << gcd << " = " << n1 << "*" << u << " + " << n2 << "*" << v << std::endl;
        std::cout << "x0 = (" << u << "*" << n1 << "*" << b2 << "+" << v << "*" << n2 << "*" << b1 << ")(mod " << n1 << "*" << n2 << ") = " << d << "mod " << n1*n2 << " = ";
        if(d > 0)
        {
            std::cout << d % (n1*n2) << std::endl;
            std::cout << "x = " << d % (n1*n2) << " + " << n1*n2 << "k" << std::endl;
        }
        else
        {
            std::cout << (n1*n2) + (d % (n1*n2)) << std::endl;
            std::cout << "x = " << (n1*n2) + (d % (n1*n2)) << " + " << n1*n2 << "k" << std::endl;
        }
    }
    else
    {
        d = v*n1*b2 + u*n2*b1;
        std::cout << gcd << " = " << n1 << "*" << v << " + " << n2 << "*" << u << std::endl;
        std::cout << "x0 = (" << v << "*" << n1 << "*" << b2 << "+" << u << "*" << n2 << "*" << b1 << ")(mod " << n1 << "*" << n2 << ") = " << d << "mod " << n1*n2 << " = ";
        if(d > 0)
        {
            std::cout << d % (n1*n2) << std::endl;
            std::cout << "x = " << d % (n1*n2) << " + " << n1*n2 << "k" << std::endl;
        }
        else
        {
            std::cout << (n1*n2) + (d % (n1*n2)) << std::endl;
            std::cout << "x = " << (n1*n2) + (d % (n1*n2)) << " + " << n1*n2 << "k" << std::endl;
        }
    }


    return 0;
} 
