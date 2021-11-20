#include <iostream>
#include <random>
#include <time.h>
//#include <SDL2/SDL.h>
#include "creature.h"
using namespace std;

int main(int argc, char* argv[])
{
    srand(time(NULL));
    std::cout << "Hello World!\n";
    vector<bitset<16>> g1;
    g1.push_back(0);
    g1.push_back(0);
    g1.push_back(0);
    g1[0].set(), g1[1].set(), g1[2].set();
    vector<bitset<16>> g2{ 0 };
    creature c1(g2);
    creature c2(g1);
    creature c3(&c1, &c2);
    cout << "g  | A | Addr| B | Addr| weight" << endl
        << c1.getGenomeString()
        << c2.getGenomeString()
        << c3.getGenomeString() << endl << endl;
    vector<bitset<16>> g3;
    vector<bitset<16>> g4;
    bitset<16> gene1, gene2;
    for (int i = 0; i < 16; ++i)
    {
        gene1[i] = rand() % 2;
        gene2[i] = rand() % 2;
    }
    g3.push_back(gene1);
    g4.push_back(gene2);
    creature c4(g3);
    creature c5(g4);
    creature c6(&c4, &c5);
    cout << "g  | A | Addr| B | Addr| weight" << endl
        << c4.getGenomeString()
        << c5.getGenomeString()
        << c6.getGenomeString() << endl << endl;
    c6.mutate();
    cout << c6.getGenomeString();
    c6.mutate();
    cout << c6.getGenomeString();
    c6.mutate();
    cout << c6.getGenomeString();
    c6.mutate();
    cout << c6.getGenomeString();
    c6.mutate();
    cout << c6.getGenomeString();
    return 0;
}
