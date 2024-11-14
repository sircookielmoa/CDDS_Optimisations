#pragma once
#include <string>

#include "raylib.h"
#include "Critter.h"



template<typename k, typename v>
struct Pair
{
	k first;
	v second;
};

template<typename key, typename content>
struct UnorderedMap
{
	using pair = Pair<key, content>;

public:
	UnorderedMap()
	{
		size = 0;
		mapContent = new pair[0];
	}
	~UnorderedMap() {};

	content& operator[](key k)
	{
		size_t ind = this->Find(k);

		if(ind != -1)
		{
			return mapContent[ind].second;
		}
		else
		{
			Insert(k, content());
			return mapContent[size - 1].second;
		}
	}

	void Insert(const key& k, const content& c)
	{

		size_t newSize = size + 1;

		//setting the size of the NEW map array to be one larger
		pair* nMap = new pair[newSize];

		for(int i = 0; i < size; i++)
		{
			nMap[i] = mapContent[i];
		}

		nMap[size].first = k;
		nMap[size].second = c;
		delete[] mapContent;

		mapContent = nMap;
		size++;

	}

	size_t Find(const key& k) {
		for (int i = 0; i < size; i++)
		{
			if (this->mapContent[i].first == k) 
				return i;
		}
		return -1;

	}

	pair* begin() {
		return &mapContent[0];
	}

	pair* end() {
		return &mapContent[size];
	}


	pair* mapContent;
	size_t size;
};
//OrderedMap Alphabet
//pair<a, A>
//pair<b, B>
//pair<d, D>


//thing<int x, int y>
//thing<type x, type y>
//thing<float x, vector3 y>


//take string x, where x is path of a texture asset to be loaded
//when loading asset, instead of performing the load and texture generation process,
//check if the texture exists already within the map
//if it does, use the already loaded texture

//input a key k, and it will grab value v
class AssetManager
{

public:
static UnorderedMap<std::string, Texture2D*> loadedTextures;



	static Texture2D* loadTexture(std::string path)
	{
		if (loadedTextures.Find(path) !=  -1) { return loadedTextures[path]; }
		
		Texture2D* texture = new Texture2D(LoadTexture(path.c_str()));
		loadedTextures[path] = texture;
		return texture;

		delete texture;
	};

	

};