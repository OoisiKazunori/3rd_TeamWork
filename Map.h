#pragma once
#include<stdio.h>
#include"Vector2.h"
#include"Global.h"

using namespace std;

#pragma warning(disable: 4996)

enum { s1, s2, s3, s4, s5, s6 };

class MapChipData {
public:
	MapChipData();
	void LoadMap(int stage);

	int chip[MAP_Y][MAP_X];
};
