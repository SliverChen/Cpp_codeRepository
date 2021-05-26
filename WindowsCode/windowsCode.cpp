#include <tchar.h>
#include <windows.h>

//this code is using format GBK

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    PSTR szCmdLine,
    int iCmdShow)
{
    static TCHAR szClassName[] = TEXT("HelloWin"); //��������
    HWND hwnd;                                     //���ھ��
    MSG msg;                                       //��Ϣ
    WNDCLASS wndclass;                             //������

    /************ע�ᴰ����***************/
    wndclass.style = CS_HREDRAW | CS_VREDRAW; //���ڷ��
    wndclass.lpfnWndProc = WndProc;           //���ڹ���
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;                               //��ǰ���ھ��
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);             //����ͼ��
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);               //�����ʽ
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //���ڱ�����ˢ
    wndclass.lpszMenuName = NULL;                                 //���ڲ˵�
    wndclass.lpszClassName = szClassName;                         //��������

    //ע�ᴰ��
    RegisterClass(&wndclass);

    /**************��������******************/
    hwnd = CreateWindow(
        szClassName,         //��������
        TEXT("Welcome"),     //���ڱ���
        WS_OVERLAPPEDWINDOW, //���ڷ��
        CW_USEDEFAULT,       //��ʼ��ʱx���λ��
        CW_USEDEFAULT,       //��ʼ��ʱy���λ��
        500,                 //���ڸ߶�
        300,                 //���ڿ���
        NULL,                //�����ھ��
        NULL,                //���ڲ˵����
        hInstance,           //��ǰ���ڵľ��
        NULL                 //�����ø�ֵ
    );

    //��ʾ����
    ShowWindow(hwnd, iCmdShow);

    //����(����)����
    UpdateWindow(hwnd);

    /*********��Ϣѭ��***********/
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg); //������Ϣ
        DispatchMessage(&msg);  //������Ϣ
    }

    return msg.wParam;
}

/***************���ڹ���*********************/

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc; //�豸�������
    PAINTSTRUCT ps;
    RECT rect;

    switch (message)
    {
    //���ڻ�����Ϣ
    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        GetClientRect(hwnd, &rect);
        DrawText(
            hdc,
            TEXT("��ã���ӭ�������"),
            -1,
            &rect,
            DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        EndPaint(hwnd, &ps);
        return 0;

    //����������Ϣ
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}
