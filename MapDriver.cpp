/**
 * A driver for demonstrate how to use the Map class 
 * (which is acutally a typedef of map<unsigned int, double>)
 * Use iterator, [] operator, find method and more
 */
#include "Map.h"
#include <iostream>
using namespace std;

void checkKey(Map map, Pair k)
{
	Map::const_iterator fit = map.find(k);
	if (fit != map.end())
	{
		cout << "Key (" << k.first << "," << k.second << ") is found, and it's value is: " << fit->second << endl;
	}
	else
	{
		cout << "Key (" << k.first << "," << k.second << ") was not found" << endl;
	}
 
}
int main()
{
	Map m; //Initialize a map from pair of usniged int to double
	Pair key(2, 3);
	m[key] = 23.4; //Set an element
	//Accessing an uninitialized key with [] operator automaticlly assign it a default value
	cout << m[key] << ", " << m[Pair(2,5)] << endl;
	//Iterate over the elements in the map
	Map::const_iterator it = m.begin();
	for (; it!=m.end(); ++it)
	{
		//first is the key, and second is it's value
		cout << it->first.first <<"," << it->first.second << "=>" << it->second << endl;
	}
	// Getting the maximal key:
	// The keys are sorted in ascending order
	it = m.end();
	--it; // Need to go back, because end() returns the past-the-end element
	cout << "Maximal Key: (" << it->first.first << "," << it->first.second << "), and it's value: " << it->second << endl;
	//To check if a key was set in the map
	checkKey(m, key);
	checkKey(m, Pair(3,4));
	return 0;
}
