#include "Model.h"
#include <stdio.h>
Model::Model(const char *modelname){
	model = new int;
	*model = MV1LoadModel(modelname);
	if ( *model == -1 ){
		char buf[256];
		sprintf_s(buf, "%sモデル読み込みエラー", modelname);
		MessageBox(NULL, buf, modelname, MB_ICONERROR);
	}
}

Model::~Model(){
	MV1DeleteModel(*model);
	delete model;
	model = NULL;
}

void Model::Draw(){
	MV1DrawModel(*model);
}