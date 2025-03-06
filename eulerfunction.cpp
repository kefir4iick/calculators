#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long с = b;
        b = a % b;
        a = с;
    }
    return a;
}
long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    return (a * b) / gcd(a, b);
}
int main() {
    int n, temp;
    std::cout << "Enter n: ";
    std::cin >> n;
    temp = n;
    
    std::vector<int> factors;
    std::vector<int> mult;
    std::vector<long long> result;
    
    while (n % 2 == 0) {
        factors.push_back(2);
        mult.push_back(0);
        while (n % 2 == 0)
        {
            n = n / 2;
            mult.back()++;
        }
    }

    for (int i = 3; i <= n; i += 2) {
        if(n % i == 0)
        {
            factors.push_back(i);
            mult.push_back(0);
        }
        while (n % i == 0) {
            n = n / i;
            mult.back()++;
        }
    }
    
    
    std::cout << "n = " << temp << " = ";
    for(int i = 0; i < factors.size(); i++)
    {
        if(mult[i] > 1)
        {
            if(i == factors.size() - 1)
            {
                std::cout << factors[i] << "^" << mult[i];
            }
            else
            {
                std::cout << factors[i] << "^" << mult[i] << " * ";
            }
        }
        else 
        {
            if(i == factors.size() - 1)
            {
                std::cout << factors[i];
            }
            else
            {
            std::cout << factors[i] << " * ";
            }
        }
    }
    std::cout << std::endl;
    
    for(int i = 0; i < factors.size(); i++)
    {
        std::cout << "n" << i + 1 << " = " << factors[i] << "^" << mult[i] << " - " << factors[i] << "^" << mult[i] - 1 << " = " << pow(factors[i], mult[i]) << " - " << pow(factors[i], mult[i] - 1) << " = " << pow(factors[i], mult[i]) - pow(factors[i], mult[i] - 1) << std::endl;
        result.push_back(pow(factors[i], mult[i]) - pow(factors[i], mult[i] - 1));
    }
    int phi = result[0];
    std::cout << "phi(n) = phi(" << temp << ") = " << result[0];
    for(int i = 1; i < result.size(); i++)
    {
        std::cout << " * " << result[i];
        phi = phi * result[i];
    }
    std::cout << " = " << phi << std::endl;
    
    long long psy = result[0];
    for (size_t i = 1; i < result.size(); ++i) {
        psy = lcm(psy, result[i]);
    }
    
    std::cout << "psy(n) = psy(" << temp << ") = lcm(" << result[0];
    for(int i = 1; i < result.size(); i++)
    {
        std::cout << ", " << result[i];
    }
    std::cout << ") = " << psy;

    return 0;
}
