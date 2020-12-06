#include "Map.h"
#include"DxLib.h"
#include<vector>

MapChipData::MapChipData() {
}

void MapChipData::LoadMap(int stage) {
	FILE *fp = nullptr;

	switch (stage) {
	case s1:fopen_s(&fp, "Resouce/csv/stage1.csv", "r");
		break;

	case s2:fopen_s(&fp, "Resouce/csv/stage2.csv", "r");
		break;

	case s3:fopen_s(&fp, "Resouce/csv/stage3.csv", "r");
		break;

	case s4:fopen_s(&fp, "Resouce/csv/stage4.csv", "r");
		break;
	
	case s5:fopen_s(&fp, "Resouce/csv/stage5.csv", "r");
		break;

	default:
		break;
	}


	//fp = FileRead_open("sample_map.csv");
	if (fp == NULL)DebugBreak();
	int c;
	int retu = 0;
	int gyou = 0;
	char buf[10];
	memset(buf, 0, sizeof(buf));
	bool eofFlag = false;
	while (1) {
		while (1) {
			c = fgetc(fp);//文字読んでcに格納
			if (c == EOF) {
				eofFlag = true;//EndOfFileの時にループを抜ける
				break;
			}
			if (c != ',' && c != '\n') {
				strcat(buf, (const char *)&c);//cがセルの区切りか改行でなければ、bufに連結する
			}
			else {
				int num = atoi(buf);//bufをint型に直して、即席のローカル変数numに代入
				chip[gyou][retu] = num;//num番目のチップ画像のハンドルを取得
				memset(buf, 0, sizeof(buf));//bufをリセット
				break;//区切りか改行ならループを抜ける
			}
		}
		//1セル分のループを抜けたら
		if (eofFlag)break;
		if (c == ',')retu++;
		if (c == '\n') {//改行だったら行を増やす
			gyou++;
			retu = 0;
		}
	}

	fclose(fp);
}