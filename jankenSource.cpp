//����񂯂�
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int set, cpu, human = 0, rock = 0, scissors = 0, paper = 0, judge;
	int hist[3] = { 0, 0, 0 };  //���s�J�E���^�[

	for (set = 1; set <= 30; set++)
	{
		printf("���Ȃ��̏o�������͂��Ă�������(�O�[�F0,�`���L�F1,�p�[�F2)\n");   //��̓���
		scanf("%d", &human);


		if (human == 0)    //�l�̎�̃J�E���g
			rock++;
		if (human == 1)
			scissors++;
		if (human == 2)
			paper++;

		if ((set % 3 == 0) || (set % 3 == 1) || (rock == scissors) && (rock == paper))  //CPU�̎�̌���
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
			printf("Com�̓O�[�ł��B\n");
		if (cpu == 1)
			printf("Com�̓`���L�ł��B\n");
		if (cpu == 2)
			printf("Com�̓p�[�ł��B\n");

		judge = (cpu - human + 3) % 3;      //���s����
		switch (judge)
		{
		case 0:printf("���������ł��B\n");
			break;
		case 1:printf("Player�̏����ł��B\n");
			break;
		case 2:printf("Com�̏����ł��B\n");
		}

		hist[judge]++;
		printf("---Player�̐�сE�E�E%d��%d�s%d��---\n\n", hist[1], hist[2], hist[0]);

	}
	return 0;
}