#include "creature.h"

creature::creature(vector<bitset<16>> g)
{
	//m_neighbour.x = -1;
	//m_neighbour.y = -1;
	//m_position = p;
	m_genome = g;
}

creature::creature(creature* p1, creature* p2)
{
	//m_position = p;
	vector<bitset<16>> g1 = p1->getGenome();
	vector<bitset<16>> g2 = p2->getGenome();
	int h = 0;
	while (h < g1.size() && h < g2.size())
	{
		bitset<16> gene;
		for (int i = 0; i < 16; ++i)
		{
			gene.set(i, ((rand() % 2) ? g1[h][i] : g2[h][i]));
		}
		m_genome.push_back(gene);
		++h;
	}
	while (h < g1.size() || h < g2.size())
	{
		m_genome.push_back(((h < g1.size()) ? g1[h] : g2[h]));
		++h;
	}
}

creature::~creature()
{
}

void creature::mutate()
{
	m_genome[rand() % m_genome.size()].set(rand() % 16, rand() % 2);
}

coord creature::getPosition()
{
	return coord(0, 0);
}

void creature::setSurroundings(vector<int> s)
{
	//m_surroundings = s;
}

void creature::setNeighbour(coord n)
{
	//m_neighbour = n;
}

void creature::behaviour()
{
}

vector<bitset<16>> creature::getGenome()
{
	return m_genome;
}

string creature::getGenomeString()
{
	stringstream ss;
	for (int i = 0; i < m_genome.size(); ++i)
	{
		ss << "g" << i + 1 << " | ";
		for (int j = 0; j < 16; ++j)
		{
			ss << m_genome[i][j];
			if (j == 0 || j == 3 || j == 4 || j == 7)
				ss << " | ";
		}
		ss << endl;
	}
	return ss.str();
}

bool creature::eat()
{
	return false;
}

bool creature::mate()
{
	return false;
}

bool creature::attack()
{
	return false;
}
