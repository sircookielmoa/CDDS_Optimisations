#pragma once
#include "Critta.h"
#include "vector"
class CrittaPool
{
public:
	
	//CrittaPool();
	CrittaPool(const std::vector<Critta*> _objects);

	Critta* Activate();
	void Deactivate(Critta*);

	std::vector<Critta*> crittasInPool;

private:
	unsigned int inactiveIndex;
	//int poolSize;
};
