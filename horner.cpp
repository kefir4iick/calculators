#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a, n, mod;
    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter pow: ";
    std::cin >> n;
    std::cout << "Enter mod: ";
    std::cin >> mod;
    int t = n;
    int p = 0;
    string ter = std::to_string(n) + " = (";
    std::vector<int> vec;
    std::vector<char> formula;
    std::vector<char> formula_new;

    while (n > 0) {
        vec.push_back(n % 2); 
        n = n/2;               
    }

    for (int i = vec.size() - 1; i >= 0; i--) {
        ter += std::to_string(vec[i]);
    }
    ter += ")_2";
    reverse(vec.begin(), vec.end());
    std::cout << ter << std::endl;

    for(int i = 1; i < vec.size(); i++)
    {
        if(vec[i] == 0){
            formula.push_back('2');
        }
        else{
            formula.push_back('2');
            formula.push_back('*');
        }
        p = p+1;
    }

    for(int i = 1; i < p; i++)
    {
        formula_new.push_back('(');
    }
    formula_new.push_back('0'+ a);
    formula_new.push_back('^');
    formula_new.push_back('2');
    for(int i = 1; i < formula.size(); i++)
    {
        if(formula[i] == '2')
        {
            formula_new.push_back(')');
            formula_new.push_back('^');
            formula_new.push_back('2');
        }
        else if(formula[i] == '*')
        {
            formula_new.push_back('*');
            formula_new.push_back('0'+ a);
        }
    }
    for(int i = 0; i < formula_new.size(); i++)
    {
        std::cout << formula_new[i];
    }
    std::cout << '\n';
    
    int u = a;
    for(int i = 0; i < formula.size(); i++)
    {
        if(formula[i] == '2')
        {
            std::cout << u << "^2 mod " << mod << " = " << u*u << " mod " << mod << " = " << (u*u) % mod << std::endl;
            u = (u*u) % mod;
        }
        else if(formula[i] == '*')
        {
            std::cout << u << "*" << a << " mod " << mod << " = " << u*a << " mod " << mod << " = "<< (u*a) % mod << std::endl;
            u = (u*a) % mod;
        }
    }
    std::cout << a << "^" << t << " mod " << mod << " = " << u << std::endl;
    
    
    return 0;
}
