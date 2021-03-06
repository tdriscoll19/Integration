// NBAfanduel.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <initializer_list>
#include <array>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class NBA
{
protected:
	float rebounds;
	float points;
	float assists;
	float blocks;
	float steals;
	string name;

public:
	void compare(NBA *obj); 
	static void playercount();
	void response(bool x, NBA *obj);
};

class PointGuard : public NBA
{
protected:
	static int players;
	

public:
	PointGuard(float r, float p, float a, float b, float s, string nom)
	{
		rebounds = r;
		points = p;
		assists = a;
		blocks = b;
		steals = s;
		name = nom;
	}
	friend class NBA;
	~PointGuard();
};

int PointGuard::players = 2;

class ShootingGuard : public NBA
{
protected:
	static int players;
	
public:
	ShootingGuard(float r, float p, float a, float b, float s, string nom)
	{
		rebounds = r;
		points = p;
		assists = a;
		blocks = b;
		steals = s;
		name = nom;
	}
	friend class NBA;
	~ShootingGuard();
};

int ShootingGuard::players = 2;

void NBA::compare(NBA *obj)
{
	int x;
	if (rebounds > obj->rebounds)
	{
		x = 1;
		this->NBA::response(x, obj);
	}
	else if (rebounds < obj->rebounds)
	{
		x = 0;
		this->NBA::response(x, obj);
	}
}

void NBA::response(bool x, NBA *obj)
{
	if (x)
	{
		cout << this->name << " is better at rebounding than " << obj->name << "\n";
	}
	else
	{
		cout << this->name << " is worse at reboudning than " << obj->name << "\n";
	}
}

void NBA::playercount()
{
	cout << "There are a total of " << PointGuard::players + ShootingGuard::players << " players listed in the program right now. \n";
}

  ShootingGuard::~ShootingGuard()
{
	cout << "deleting objects! \n";
};

  PointGuard::~PointGuard()
  {
	  cout << "deleting objects! \n";
  };
int main()
{
	ShootingGuard JamesHarden(5.9, 33.7, 8.7, .6, 2, "Harden");
	PointGuard KyrieIrving(4.9, 22.9, 6.6, .4, 1.7, "Irving");
	PointGuard *ptrdrew;
	ptrdrew = &KyrieIrving;
	JamesHarden.compare(ptrdrew);
    return 0;
}

