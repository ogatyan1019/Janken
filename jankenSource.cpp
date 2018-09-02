//じゃんけん
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int set, cpu, human = 0, rock = 0, scissors = 0, paper = 0, judge;
	int hist[3] = { 0, 0, 0 };  //勝敗カウンター

	for (set = 1; set <= 30; set++)
	{
		printf("あなたの出す手を入力してください(グー：0,チョキ：1,パー：2)\n");   //手の入力
		scanf("%d", &human);


		if (human == 0)    //人の手のカウント
			rock++;
		if (human == 1)
			scissors++;
		if (human == 2)
			paper++;

		if ((set % 3 == 0) || (set % 3 == 1) || (rock == scissors) && (rock == paper))  //CPUの手の決定
		{
			srand((unsigned int)time(NULL));
			cpu = rand() % 3;
		}

		else
		{
			if (rock < scissors)
			{
				if (scissors < paper)
					cpu = 2;
				else
					cpu = 1;
			}
			else
			{
				if (rock < paper)
					cpu = 2;
				else
					cpu = 0;
			}
		}

		if (cpu == 0)
			printf("Comはグーです。\n");
		if (cpu == 1)
			printf("Comはチョキです。\n");
		if (cpu == 2)
			printf("Comはパーです。\n");

		judge = (cpu - human + 3) % 3;      //勝敗判定
		switch (judge)
		{
		case 0:printf("引き分けです。\n");
			break;
		case 1:printf("Playerの勝利です。\n");
			break;
		case 2:printf("Comの勝利です。\n");
		}

		hist[judge]++;
		printf("---Playerの戦績・・・%d勝%d敗%d分---\n\n", hist[1], hist[2], hist[0]);

	}
	return 0;
}