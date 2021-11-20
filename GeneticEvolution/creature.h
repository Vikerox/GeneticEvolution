#pragma once
#include <iostream>
#include <bitset>
#include <vector>
#include <random>
#include <sstream>
using namespace std;

struct coord
{
	int x;
	int y;
	coord(int a, int b)
	{
		x = a;
		y = b;
	}
};

struct statistics
{
	// Age of the creature
	int m_age = 0;
	// How long the creature will live
	int m_lifespan;
	// "Mana" used for most actions
	int m_energy;
	// Amount of food in the creatures stomach
	int m_food;
	// Amount of health, before the creature dies
	int m_health;
	// Damage the creature deals to others
	int m_damage;
	// how much energy the creatures gains when it has food
	int m_energy_gain;
	// how much food the creature looses per energy gained
	int m_energy_cost;
	// how quickly the creature regenerates
	int m_regeneration;
	// how much food the creature looses per regeneration
	int m_regeneration_cost;
	// how like they are to pass on their genes during mating
	float m_dominance;
	// movement speed
	int m_speed;

};

class creature
{
private:
	// A | Addr| B | Addr| weight
	// 0 | 111 | 0 | 111 | 11111111 16bit
	// 1 | 111 | 1 | 111 | 11111111 16bit
	vector<bitset<16>> m_genome;
	//coord m_position;
	//vector<int> m_surroundings{0,0,0,0,0,0,0,0};
	//coord m_neighbour;
	//statistics m_stat;
public:
	creature(vector<bitset<16>> g);
	creature(creature* p1, creature* p2);
	~creature();
	void mutate();
	coord getPosition();
	void setSurroundings(vector<int> s);
	void setNeighbour(coord n);
	bool eat();
	bool mate();
	bool attack();
	void behaviour();
	vector<bitset<16>> getGenome();
	string getGenomeString();
};
