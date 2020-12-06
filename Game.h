#pragma once

#include "BaseScene.h"
#include "ISceneChanger.h"

#include"Map.h"
#include"BackGround.h"

//ƒQ[ƒ€‰æ–ÊƒNƒ‰ƒX
class Game : public BaseScene, MapChipData {

public:
	Game(ISceneChanger *changer);
	void Initialize() override;
	//void Finalize() override;
	void Update() override;
	void Draw() override;

};