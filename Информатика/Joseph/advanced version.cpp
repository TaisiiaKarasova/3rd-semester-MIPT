#include <iostream>
int Joseph(int people, int words, int number)
{
    if (people == 1) return 0;
    else if (people == number) return (words - 1) % people;
    else return (Joseph(people - 1, words, number) + words) % people;
}

int main()
{
    int P; int W;
    std::cin >> P >> W;
    std::cout << 1 + Joseph(P, W, 3) << ' ' << 1 + Joseph(P, W, 2) << ' ' << 1 + Joseph(P, W, 1) << std::endl;
}