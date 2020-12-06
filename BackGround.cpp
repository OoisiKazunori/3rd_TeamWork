#include "BackGround.h"
#include"DxLib.h"
#include"Map.h"

BackGround::BackGround() {

	BlockSize = 32;
	shakePos = { 0,0 };
	_pos = { 0,0 };

	LoadDivGraph("Resouce/mapChip_alpha.png", 36, 4, 9, 32, 32, _graph);

}

void BackGround::Init(int map[MAP_Y][MAP_X])
{
	for (int i = 0; i < MAP_Y; i++) {
		for (int j = 0; j < MAP_X; j++) {
			_map[i][j] = map[i][j];
		}
	}
}

void BackGround::Update() {
}

void BackGround::Draw() const {

	for (int y = 0; y <MAP_Y; y++) {
		for (int x = 0; x < MAP_X; x++) {
			for (int i = 0; i <= d15; i++) {
				if (_map[y][x] == i) {
					DrawGraph(x * BLOCK_SIZE + _pos.x + shakePos.x, y * BLOCK_SIZE + _pos.y + shakePos.y, _graph[i], TRUE);
				}
			}
		}
	}

}

void BackGround::SetCameraPos(Vector2<float>CameraPos) {
	_pos = CameraPos;
}

void BackGround::SetShakePos(Vector2<int> ShakePos) {
	shakePos = ShakePos;
}
