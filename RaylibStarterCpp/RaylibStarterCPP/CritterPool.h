#pragma once
#include "Critter.h"
#include "vector"
class CritterPool
{
public:
	
	//CrittaPool();
	CritterPool(const std::vector<Critter*>& _objects);
	~CritterPool();


	Critter* Activate();
	void Deactivate(Critter*);


private:
	std::vector<Critter*> crittersInPool;
	unsigned int inactiveIndex;
	//int poolSize;
};
