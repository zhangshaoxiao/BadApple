/**************************************************************
** �������ƣ�BadApple������ʾ
** �����ܣ�ͼ��ģʽ�£�ASCII�ַ�����
** ���뻷����VC++6.0 EGE 12.06
** ������Ϣ��Geodesic <Geodesicwl-cpro@yahoo.cn> 
** ����޸ģ�2012-07-23
**************************************************************/
#include <graphics.h>
#include <ege/fps.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
	char Line[162];
	FILE *fp;
	int loop;


	/*��ʼ��*/
	initgraph(960, 720, ege::INIT_ANIMATION);
	setbkcolor(EGERGB(0xF5, 0xF5, 0xDC));


	/*���ļ�*/
	if((fp = fopen("AscPic.txt", "r")) == NULL)
	{
		outtextxy(0, 0, "�ļ���ʧ��");
		Sleep(2000);
		exit(EXIT_FAILURE);
	}

	/*�������*/
	mciSendString("open BadApple.mp3 alias BadApple", NULL, 0, NULL);
	mciSendString("play BAdApple", NULL, 0, NULL);


	/*������ʾ*/
	fps f;
	setcolor(EGERGB(0xFF, 0x0, 0x0));
    for ( ; !feof(fp) && is_run(); delay_fps(30))
	{

		for(loop = 0; loop < 61; loop++)
		{
			if(fgets(Line, 162, fp) == NULL)
				break;
			setcolor(EGERGB(0x0, 0xFF, 0x0));
			outtextxy(0, loop * 12, Line);
		}

	}


	/*�ƺ���*/
	fclose(fp);
	closegraph();

	return 0;
}
