#pragma once
#include "Critter.h"
#include "vector"
class CritterPool
{
public:
	
	//CrittaPool();
	CritterPool(const std::vector<Critter*> _objects);

	Critter* Activate();
	void Deactivate(Critter*);

	std::vector<Critter*> crittersInPool;

private:
	unsigned int inactiveIndex;
	//int poolSize;
};
