/******************************************************
 * EasyX Library for C++ (Ver:20100825)
 * http://www.easyx.cn
 *
 * graphics.h
 * �� VC ��ģ�� Borland BGI ��ͼ�⣬ʵ�ּ򵥵Ļ�ͼ
 ******************************************************/

#pragma once

#ifndef WINVER
#define WINVER 0x0400			// Specifies that the minimum required platform is Windows 95/NT4.
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400		// Specifies that the minimum required platform is Windows 95/NT4.
#endif

#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS 0x0410	// Specifies that the minimum required platform is Windows 98.
#endif

#if defined(_UNICODE) && (_MSC_VER > 1200)
	#pragma comment(lib,"graphicswu.lib")
#elif !defined(_UNICODE) && (_MSC_VER > 1200)
	#pragma comment(lib,"graphicsw.lib")
#elif defined(_UNICODE)
	#pragma comment(lib,"graphicsu.lib")
#elif !defined(_UNICODE)
	#pragma comment(lib,"graphics.lib")
#endif


#include "windows.h"
#include "tchar.h"

#define PI 3.1415926535

// Ϊ�˼��� Borland C++ 3.1 �����������嶨��
#define DETECT 0
#define VGA	0
#define VGAHI 0

// ��ͼ������ʼ������
#define SHOWCONSOLE		1		// ����ͼ��ģʽʱ����������̨����ʾ

// ��ɫ
#define	BLACK			0
#define	BLUE			0xA80000
#define	GREEN			0x00A800
#define	CYAN			0xA8A800
#define	RED				0x0000A8
#define	MAGENTA			0xA800A8
#define	BROWN			0x0054A8
#define	LIGHTGRAY		0xA8A8A8
#define	DARKGRAY		0x545454
#define	LIGHTBLUE		0xFC5454
#define	LIGHTGREEN		0x54FC54
#define	LIGHTCYAN		0xFCFC54
#define	LIGHTRED		0x5454FC
#define	LIGHTMAGENTA	0xFC54FC
#define	YELLOW			0x54FCFC
#define	WHITE			0xFCFCFC

// ���ģʽ
#define	NULL_FILL			1		// �����
#define	SOLID_FILL			2		// ��ָ����ɫ��ȫ���
#define	BDIAGONAL_FILL		3		// /// ��� (��ͨһ��)
#define	CROSS_FILL			4		// +++ ���
#define	DIAGCROSS_FILL		5		// xxx ���
#define	DOT_FILL			6		// ... ���
#define	FDIAGONAL_FILL		7		// \\\ ���
#define	HORIZONTAL_FILL		8		// --- ���
#define	VERTICAL_FILL		9		// ||| ���
#define	BDIAGONAL2_FILL		10		// /// ��� (�ܼ�һ��)
#define	CROSS2_FILL			11		// +++ ���
#define	DIAGCROSS2_FILL		12		// xxx ���
#define	DOT2_FILL			13		// ... ���
#define	FDIAGONAL2_FILL		14		// \\\ ���
#define	HORIZONTAL2_FILL	15		// --- ���
#define	VERTICAL2_FILL		16		// ||| ���
#define	BDIAGONAL3_FILL		17		// /// ��� (����һ��)
#define	CROSS3_FILL			18		// +++ ���
#define	DIAGCROSS3_FILL		19		// xxx ���
#define	DOT3_FILL			20		// ... ���
#define	FDIAGONAL3_FILL		21		// \\\ ���
#define	HORIZONTAL3_FILL	22		// --- ���
#define	VERTICAL3_FILL		23		// ||| ���
#define	INTERLEAVE_FILL		24		// xxx ��� (ʮ����)
#define	PATTERN_FILL		25		// ��ָ��ͼ�����



// ��ͼģʽ��غ���

void initgraph(int Width, int Height, int Flag = NULL);	// ��ʼ��ͼ�λ���
void initgraph(int* gdriver, int* gmode, char* path);	// ���� Borland C++ 3.1 �����أ�Ĭ�� 640x480@24bit
void closegraph();										// �ر�ͼ�λ���



// ��ͼ��������

void cleardevice();					// ����

void getviewport(int *pleft, int *ptop, int *pright, int *pbottom, bool *pclip = NULL);	// ��ȡ��ͼ��Ϣ
void setviewport(int left, int top, int right, int bottom, bool clip = true);			// ������ͼ
void clearviewport();															// �����ͼ

void getlinestyle(int *plinestyle, WORD *pupattern = NULL, int *pthickness = NULL);	// ��ȡ��ǰ����
void setlinestyle(int linestyle, WORD upattern = NULL, int thickness = 1);			// ���õ�ǰ����
void getfillstyle(COLORREF *pcolor, int *ppattern = NULL, char *pupattern = NULL);			// ��ȡ�������
void setfillstyle(COLORREF color, int pattern = SOLID_FILL, const char *pupattern = NULL);	// �����������

void getaspectratio(float *pxasp, float *pyasp);		// ��ȡ��ǰ��������
void setaspectratio(float xasp = 1, float yasp = 1);	// ���õ�ǰ��������

void setwritemode(int mode);				// ���û�ͼλ����ģʽ

void graphdefaults();						// �������л�ͼ����ΪĬ��ֵ

COLORREF getcolor();				// ��ȡ��ǰ��ͼǰ��ɫ
void setcolor(COLORREF color);		// ���õ�ǰ��ͼǰ��ɫ
COLORREF getbkcolor();				// ��ȡ��ǰ��ͼ����ɫ
void setbkcolor(COLORREF color);	// ���õ�ǰ��ͼ����ɫ
void setbkmode(int iBkMode);		// ���ñ������ģʽ

// ��ɫģ��ת������
COLORREF RGBtoGRAY(COLORREF rgb);
void RGBtoHSL(COLORREF rgb, float *H, float *S, float *L);
void RGBtoHSV(COLORREF rgb, float *H, float *S, float *V);
COLORREF HSLtoRGB(float H, float S, float L);
COLORREF HSVtoRGB(float H, float S, float V);


// ��ͼ����

COLORREF getpixel(int x, int y);				// ��ȡ�����ɫ
void putpixel(int x, int y, COLORREF color);	// ����

void moveto(int x, int y);						// �ƶ���ǰ��(��������)
void moverel(int dx, int dy);					// �ƶ���ǰ��(�������)

void line(int x1, int y1, int x2, int y2);		// ����
void linerel(int dx, int dy);					// ����(���������)
void lineto(int x, int y);						// ����(����������)

void rectangle(int left, int top, int right, int bottom);	// ������

void getarccoords(int *px, int *py, int *pxstart, int *pystart, int *pxend, int *pyend);	// ��ȡԲ��������Ϣ
void arc(int x, int y, int stangle, int endangle, int radius);					// ��Բ��
void circle(int x, int y, int radius);											// ��Բ
void pieslice(int x, int y, int stangle, int endangle, int radius);				// �����Բ����
void ellipse(int x, int y, int stangle, int endangle, int xradius, int yradius);// ����Բ����
void fillellipse(int x, int y, int xradius, int yradius);						// �������Բ
void sector(int x, int y, int stangle, int endangle, int xradius, int yradius);	// �������Բ����

void bar(int left, int top, int right, int bottom);								// ���ޱ߿�������
void bar3d(int left, int top, int right, int bottom, int depth, bool topflag);	// ���б߿���ά������

void drawpoly(int numpoints, const int *polypoints);	// �������
void fillpoly(int numpoints, const int *polypoints);	// �����Ķ����
void floodfill(int x, int y, int border);				// �������



// ������غ���

void outtext(LPCTSTR textstring);					// �ڵ�ǰλ���������
void outtext(TCHAR c);								// �ڵ�ǰλ������ַ�
void outtextxy(int x, int y, LPCTSTR textstring);	// ��ָ��λ���������
void outtextxy(int x, int y, TCHAR c);				// �ڵ�ǰλ������ַ�
int textwidth(LPCTSTR textstring);					// ��ȡ�ַ���ռ�õ����ؿ�
int textheight(LPCTSTR textstring);					// ��ȡ�ַ���ռ�õ����ظ�

// ���õ�ǰ������ʽ(�������)
//		nHeight: �ַ���ƽ���߶ȣ�
//		nWidth: �ַ���ƽ�����(0 ��ʾ����Ӧ)��
//		lpszFace: �������ƣ�
//		nEscapement: �ַ�������д�Ƕ�(��λ 0.1 ��)��
//		nOrientation: ÿ���ַ�����д�Ƕ�(��λ 0.1 ��)��
//		nWeight: �ַ��ıʻ���ϸ(0 ��ʾĬ�ϴ�ϸ)��
//		bItalic: �Ƿ�б�壻
//		bUnderline: �Ƿ��»��ߣ�
//		bStrikeOut: �Ƿ�ɾ���ߣ�
//		fbCharSet: ָ���ַ�����
//		fbOutPrecision: ָ�����ֵ�������ȣ�
//		fbClipPrecision: ָ�����ֵļ������ȣ�
//		fbQuality: ָ�����ֵ����������
//		fbPitchAndFamily: ָ���Գ��淽ʽ�������������ϵ�С�
void setfont(int nHeight, int nWidth, LPCTSTR lpszFace);
void setfont(int nHeight, int nWidth, LPCTSTR lpszFace, int nEscapement, int nOrientation, int nWeight, bool bItalic, bool bUnderline, bool bStrikeOut);
void setfont(int nHeight, int nWidth, LPCTSTR lpszFace, int nEscapement, int nOrientation, int nWeight, bool bItalic, bool bUnderline, bool bStrikeOut, BYTE fbCharSet, BYTE fbOutPrecision, BYTE fbClipPrecision, BYTE fbQuality, BYTE fbPitchAndFamily);
void setfont(const LOGFONT *font);	// ���õ�ǰ������ʽ
void getfont(LOGFONT *font);		// ��ȡ��ǰ������ʽ



// ͼ������

// ����ͼ�����
class IMAGE
{
private:
	HBITMAP m_hBmp;
	HDC m_hDC;
	int m_width, m_height;
public:
	IMAGE();
	IMAGE(IMAGE &img);				// �������캯��
	IMAGE& operator = (IMAGE &img);	// ��ֵ��������غ���
	~IMAGE();
	void getimage(int srcX, int srcY, int srcWidth, int srcHeight);
	void getimage(LPCTSTR pImgFile, int zoomWidth = 0, int zoomHeight = 0);
	void getimage(LPCTSTR pResType, LPCTSTR pResName, int zoomWidth = 0, int zoomHeight = 0);
	void getimage(const IMAGE *pSrcImg, int srcX, int srcY, int srcWidth, int srcHeight);
	void putimage(int dstX, int dstY, DWORD dwRop = SRCCOPY) const;
	void putimage(int dstX, int dstY, int dstWidth, int dstHeight, int srcX, int srcY, DWORD dwRop = SRCCOPY) const;
	void putimage(IMAGE *pDstImg, int dstX, int dstY, DWORD dwRop = SRCCOPY) const;
	void putimage(IMAGE *pDstImg, int dstX, int dstY, int dstWidth, int dstHeight, int srcX, int srcY, DWORD dwRop = SRCCOPY) const;
};

void getimage(IMAGE *pDstImg, int srcX, int srcY, int srcWidth, int srcHeight);				// ����Ļ��ȡͼ��
void getimage(IMAGE *pDstImg, LPCTSTR pImgFile, int zoomWidth = 0, int zoomHeight = 0);		// ��ͼƬ�ļ���ȡͼ��(bmp/jpg/gif/emf/wmf)
void getimage(IMAGE *pDstImg, LPCTSTR pResType, LPCTSTR pResName, int zoomWidth = 0, int zoomHeight = 0);	// ����Դ�ļ���ȡͼ��(bmp/jpg/gif/emf/wmf)
void getimage(IMAGE *pDstImg, const IMAGE *pSrcImg, int srcX, int srcY, int srcWidth, int srcHeight);	// ����һ�� IMAGE �����л�ȡͼ��
void putimage(int dstX, int dstY, const IMAGE *pSrcImg, DWORD dwRop = SRCCOPY);							// ����ͼ����Ļ
void putimage(int dstX, int dstY, int dstWidth, int dstHeight, const IMAGE *pSrcImg, int srcX, int srcY, DWORD dwRop = SRCCOPY);	// ����ͼ����Ļ(ָ�����)
void putimage(IMAGE *pDstImg, int dstX, int dstY, const IMAGE *pSrcImg, DWORD dwRop = SRCCOPY);			// ����ͼ����һͼ����
void putimage(IMAGE *pDstImg, int dstX, int dstY, int dstWidth, int dstHeight, const IMAGE *pSrcImg, int srcX, int srcY, DWORD dwRop = SRCCOPY);	// ����ͼ����һͼ����(ָ�����)



// ��������

int	getwidth();			// ��ȡ��ͼ�����
int	getheight();		// ��ȡ��ͼ���߶�
int	getx();				// ��ȡ��ǰ x ����
int	gety();				// ��ȡ��ǰ y ����

void BeginBatchDraw();	// ��ʼ��������
void FlushBatchDraw();	// ִ��δ��ɵĻ�������
void FlushBatchDraw(int left, int top, int right, int bottom);	// ִ��ָ��������δ��ɵĻ�������
void EndBatchDraw();	// �����������ƣ���ִ��δ��ɵĻ�������
void EndBatchDraw(int left, int top, int right, int bottom);	// �����������ƣ���ִ��ָ��������δ��ɵĻ�������

HWND GetHWnd();			// ��ȡ��ͼ���ھ��
int GetGraphicsVer();	// ��ȡ��ǰ�汾



// �����Ϣ
// ֧��������Ϣ��
//		WM_MOUSEMOVE		����ƶ�
//		WM_MOUSEWHEEL		�����ֲ���
//		WM_LBUTTONDOWN		�������
//		WM_LBUTTONUP		�������
//		WM_LBUTTONDBLCLK	���˫��
//		WM_MBUTTONDOWN		�м�����
//		WM_MBUTTONUP		�м�����
//		WM_MBUTTONDBLCLK	�м�˫��
//		WM_RBUTTONDOWN		�Ҽ�����
//		WM_RBUTTONUP		�Ҽ�����
//		WM_RBUTTONDBLCLK	�Ҽ�˫��
struct MOUSEMSG
{
	UINT uMsg;			// ��ǰ�����Ϣ
	bool mkCtrl;		// Ctrl ���Ƿ���
	bool mkShift;		// Shift ���Ƿ���
	bool mkLButton;		// �������Ƿ���
	bool mkMButton;		// ����м��Ƿ���
	bool mkRButton;		// ����Ҽ��Ƿ���
	short x;				// ��ǰ��� x ����
	short y;				// ��ǰ��� y ����
	short wheel;			// �����ֹ���ֵ(120�ı���)
};

bool MouseHit();				// ����Ƿ���������Ϣ
MOUSEMSG GetMouseMsg();			// ��ȡһ�������Ϣ�����û�У��͵ȴ�
void FlushMouseMsgBuffer();		// ��������Ϣ������
