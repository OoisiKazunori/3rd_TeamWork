#pragma once
#include"Vector2.h"
#include"Global.h"

class BackGround {
public:
	BackGround();

	void Init(int map[MAP_Y][MAP_X]);
	void Update();
	void Draw()const;

	void SetCameraPos(Vector2<float> CameraPos);
	void SetShakePos(Vector2<int> ShakePos);

private:
	enum mapDate { d1 = 1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15 };
	Vector2<float>_pos, _localPos;
	Vector2<int> shakePos;

	int BlockSize, _graph[36];
	int _map[MAP_Y][MAP_X];
};

