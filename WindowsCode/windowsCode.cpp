#include <tchar.h>
#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    PSTR szCmdLine,
    int iCmdShow)
{
    static TCHAR szClassName[] = TEXT("HelloWin"); //窗口类名
    HWND hwnd;                                     //窗口句柄
    MSG msg;                                       //消息
    WNDCLASS wndclass;                             //窗口类

    /************注册窗口类***************/
    wndclass.style = CS_HREDRAW | CS_VREDRAW; //窗口风格
    wndclass.lpfnWndProc = WndProc;           //窗口过程
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;                                 //当前窗口句柄
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);               //窗口图标
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);                 //鼠标样式
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //窗口背景画刷
    wndclass.lpszMenuName = NULL;                                   //窗口菜单
    wndclass.lpszClassName = szClassName;                           //窗口类名

    //注册窗口
    RegisterClass(&wndclass);

    /**************创建窗口******************/
    hwnd = CreateWindow(
        szClassName,         //窗口类名
        TEXT("Welcome"),     //窗口标题
        WS_OVERLAPPEDWINDOW, //窗口风格
        CW_USEDEFAULT,       //初始化时x轴的位置
        CW_USEDEFAULT,       //初始化时y轴的位置
        500,                 //窗口高度
        300,                 //窗口宽度
        NULL,                //父窗口句柄
        NULL,                //窗口菜单句柄
        hInstance,           //当前窗口的句柄
        NULL                 //不适用该值
    );

    //显示窗口
    ShowWindow(hwnd, iCmdShow);

    //更新(绘制)窗口
    UpdateWindow(hwnd);

    /*********消息循环***********/
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg); //翻译消息
        DispatchMessage(&msg);  //分派消息
    }

    return msg.wParam;
}

/***************窗口过程*********************/

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc; //设备环境句柄
    PAINTSTRUCT ps;
    RECT rect;

    switch (message)
    {
    //窗口绘制消息
    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        GetClientRect(hwnd, &rect);
        DrawText(
            hdc,
            TEXT("你好，欢迎来到这儿"),
            -1,
            &rect,
            DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        EndPaint(hwnd, &ps);
        return 0;

    //窗口销毁消息
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}
