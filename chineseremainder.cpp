#include <iostream>
#include <vector>
using namespace std;
int main(){
    int b1, b2, b3, n1, n2, n3;
    int a, b;
    int m1, m2, m3;
    std::cout << "Enter b1: ";
    std::cin >> b1;
    std::cout << "Enter b2: ";
    std::cin >> b2;
    std::cout << "Enter b3: ";
    std::cin >> b3;
    std::cout << "Enter n1: ";
    std::cin >> n1;
    std::cout << "Enter n2: ";
    std::cin >> n2;
    std::cout << "Enter n3: ";
    std::cin >> n3;
    std::cout << "x ≡ " << b1 << "(mod " << n1 << ")" << std::endl;
    std::cout << "x ≡ " << b2 << "(mod " << n2 << ")" << std::endl;
    std::cout << "x ≡ " << b3 << "(mod " << n3 << ")" << std::endl;
    std::cout << "N = " << n1 << "*" << n2 << "*" << n3 << " = " << n1*n2*n3 << std::endl;
    std::cout << "N1 = " << n2 << "*" << n3 << " = " << n2*n3 << std::endl;
    std::cout << "N2 = " << n1 << "*" << n3 << " = " << n1*n3 << std::endl;
    std::cout << "N3 = " << n1 << "*" << n2 << " = " << n1*n2 << std::endl;
    std::cout << "M1 = " << n2*n3 << "^(-1)(mod" << n1 << ")" << std::endl;
    std::cout << "M2 = " << n1*n3 << "^(-1)(mod" << n2 << ")" << std::endl;
    std::cout << "M3 = " << n1*n2 << "^(-1)(mod" << n3 << ")" << std::endl;
    std::cout << "gcd(" << n1 << ", " << n2*n3 << "):" << std::endl;
    vector<int> list;
    int i = 1;
    int gcd, l, m;
    int u, v;
    a = n1;
    b = n2*n3;
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
    
    m1 = stoi(matrix[1][i+1]);
    //v = stoi(matrix[2][i+1]);
    list.clear();
    i = 1;
    std::cout << "gcd(" << n2 << ", " << n1*n3 << "):" << std::endl;
    a = n2;
    b = n1*n3;
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
    
    string matrix2[3][i+2];
    matrix2[1][0] = 'u';
    matrix2[2][0] = 'v';
    matrix2[1][1] = '1';
    matrix2[2][1] = '0';
    matrix2[1][2] = '0';
    matrix2[2][2] = '1';
    for(int j = 0; j < list.size(); j++)
    {
        matrix2[0][j+2] = to_string(list[j]);
        matrix2[1][j+3] = to_string(stoi(matrix2[1][j+1])-stoi(matrix2[0][j+2])*stoi(matrix2[1][j+2]));
        matrix2[2][j+3] = to_string(stoi(matrix2[2][j+1])-stoi(matrix2[0][j+2])*stoi(matrix2[2][j+2]));
    }
    for(int j = 0; j < 3; j++)
    {
        for(int k = 0; k < i+2; k++)
        {
            std::cout << matrix2[j][k] << "\t\t";
        }
        std::cout << endl;
    }
    
    m2 = stoi(matrix2[1][i+1]);
    
    list.clear();
    i = 1;
    std::cout << "gcd(" << n3 << ", " << n1*n2 << "):" << std::endl;
    a = n3;
    b = n1*n2;
    
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
    
    string matrix3[3][i+2];
    matrix3[1][0] = 'u';
    matrix3[2][0] = 'v';
    matrix3[1][1] = '1';
    matrix3[2][1] = '0';
    matrix3[1][2] = '0';
    matrix3[2][2] = '1';
    for(int j = 0; j < list.size(); j++)
    {
        matrix3[0][j+2] = to_string(list[j]);
        matrix3[1][j+3] = to_string(stoi(matrix3[1][j+1])-stoi(matrix3[0][j+2])*stoi(matrix3[1][j+2]));
        matrix3[2][j+3] = to_string(stoi(matrix3[2][j+1])-stoi(matrix3[0][j+2])*stoi(matrix3[2][j+2]));
    }
    for(int j = 0; j < 3; j++)
    {
        for(int k = 0; k < i+2; k++)
        {
            std::cout << matrix3[j][k] << "\t\t";
        }
        std::cout << endl;
    }
    
    m3 = stoi(matrix3[1][i+1]);
    std::cout << "M1 = " << m1 << std::endl;
    std::cout << "M2 = " << m2 << std::endl;
    std::cout << "M3 = " << m3 << std::endl;
    int d, x;
    d = b1*n2*n3*m1 + b2*n1*n3*m2 + b3*n1*n2*m3;
    if(d >= 0)
    {
        x = d % (n1*n2*n3);
    }
    else
    {
        x = d+((-d)/(n1*n2*n3) + 1)*n1*n2*n3;
    }
    std::cout << "x0 = (" << b1 << "*" << n2*n3 << "*" << m1 << "+" << b2 << "*" << n1*n3 << "*" << m2 << "+" << b3 << "*" << n1*n2 << "*" << m3 << ")(mod " << n1*n2*n3 << ") " << "≡ " << d << " mod " << n1*n2*n3 << " = " << x << std::endl;
    std::cout << "x = " << x << " + " << n1*n2*n3 << "k" << std::endl;
}
