#include <iostream>
#include <vector>
using namespace std;
int main() 
{
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;
    
    std::vector<int> factors;
    
    while (n % 2 == 0) 
    {
        factors.push_back(2);
        n = n / 2;
    }

    for (int i = 3; i <= n; i += 2) 
    {
        while (n % i == 0) 
        {
            factors.push_back(i);
            n = n / i;
        }
    }
    
    for(int i = 0; i < factors.size(); i++)
    {
        std::cout << factors[i];
    }

    return 0;
}
