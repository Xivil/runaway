#pragma once
#include "DxLib.h"
#include "Model.h"
class Object{
private:
	VECTOR *position;
	VECTOR *unit;
	VECTOR *vector;
	VECTOR *direction;
	Model *model;
public:
	Object();
	~Object(){};
};