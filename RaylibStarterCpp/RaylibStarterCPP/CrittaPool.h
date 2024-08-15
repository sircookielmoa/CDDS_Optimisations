#pragma once
#include "Critta.h"
#include "vector"
class CrittaPool
{
public:
	
	CrittaPool();
	CrittaPool(std::vector<Critta*> _objects);

	void Allocate();
	void Deallocate();
	//critter[1].isDead
	void IsActive(bool _isDead);
	//{
	//	if(_isDead == true)
	//	{
	//		//do stuff
	//	}
	//	else
	//	{
	//		//
	//	}
	//}

	std::vector<Critta*> ActiveCrittas();

private:

	std::vector<Critta*> crittaPoolList;
	int activeCount;
	int poolSize;

};

