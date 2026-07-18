#include <iostream>
#include <vector>
#include <string>

int add(int a, int b);

int main()
{
    // Inicializando código
    std::cout << "Inicio de código \n";
    int x {};
    std::cout << "Insira um valor numérico: ";
    std::cin >> x;
    
    // Pode ser escrito dessa forma também: int new_x = x*2;
    int new_x {add(x, 45)};

    std::cout << "O dobro do valor inserido foi: " << new_x << '\n';
    return 0;
}
