/**************************************************************
** 程序名称：BadApple动画演示
** 程序功能：图像模式下，ASCII字符动画
** 编译环境：VC++6.0 EGE 12.06
** 作者信息：Geodesic <Geodesicwl-cpro@yahoo.cn> 
** 最后修改：2012-07-23
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


	/*初始化*/
	initgraph(960, 720, ege::INIT_ANIMATION);
	setbkcolor(EGERGB(0xF5, 0xF5, 0xDC));


	/*打开文件*/
	if((fp = fopen("AscPic.txt", "r")) == NULL)
	{
		outtextxy(0, 0, "文件打开失败");
		Sleep(2000);
		exit(EXIT_FAILURE);
	}

	/*添加音乐*/
	mciSendString("open BadApple.mp3 alias BadApple", NULL, 0, NULL);
	mciSendString("play BAdApple", NULL, 0, NULL);


	/*动画演示*/
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


	/*善后处理*/
	fclose(fp);
	closegraph();

	return 0;
}
