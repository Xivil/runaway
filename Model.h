#pragma once
#include <DxLib.h>

class Model{
	int *model;
	char *filelname;
public:
	Model(const char *modelname);
	~Model();
	void Draw();
};