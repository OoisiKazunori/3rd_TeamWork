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
			c = fgetc(fp);//�����ǂ��c�Ɋi�[
			if (c == EOF) {
				eofFlag = true;//EndOfFile�̎��Ƀ��[�v�𔲂���
				break;
			}
			if (c != ',' && c != '\n') {
				strcat(buf, (const char *)&c);//c���Z���̋�؂肩���s�łȂ���΁Abuf�ɘA������
			}
			else {
				int num = atoi(buf);//buf��int�^�ɒ����āA���Ȃ̃��[�J���ϐ�num�ɑ��
				chip[gyou][retu] = num;//num�Ԗڂ̃`�b�v�摜�̃n���h�����擾
				memset(buf, 0, sizeof(buf));//buf�����Z�b�g
				break;//��؂肩���s�Ȃ烋�[�v�𔲂���
			}
		}
		//1�Z�����̃��[�v�𔲂�����
		if (eofFlag)break;
		if (c == ',')retu++;
		if (c == '\n') {//���s��������s�𑝂₷
			gyou++;
			retu = 0;
		}
	}

	fclose(fp);
}