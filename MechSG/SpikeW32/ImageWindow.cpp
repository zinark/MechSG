#include "ImageWindow.h"
#include "resource.h"
using namespace SpikeW32;

HBITMAP _HBitmap;
BITMAP _Bitmap;
int _BitmapWidth;
int _BitmapHeight;

ImageWindow::~ImageWindow(void)
{
    DeleteObject (_HBitmap);
}

void ImageWindow::OnWindowCreated()
{
     _HBitmap = LoadBitmap (_HInstance, MAKEINTRESOURCE (IDB_BITMAP1));
    GetObject (_HBitmap, sizeof(_Bitmap), &_Bitmap);
    _BitmapWidth = _Bitmap.bmWidth;
    _BitmapHeight = _Bitmap.bmHeight;
}

void ImageWindow::OnPaint( const HDC& hdc )
{
    HDC bitmapDc = CreateCompatibleDC(hdc);
    
    LOGPEN logPen;
    logPen.lopnStyle = PS_SOLID;
    logPen.lopnWidth.x = 1;
    logPen.lopnWidth.y = 1;
    logPen.lopnColor = RGB (255, 0,0);
    HPEN pen = CreatePenIndirect(&logPen);

    LOGBRUSH logBrush;
    logBrush.lbStyle = PS_SOLID;
    logBrush.lbColor = RGB (0,255,255);
    HBRUSH brush = CreateBrushIndirect(&logBrush);

    HPEN oldPen = (HPEN) SelectObject (hdc, pen);
    HBRUSH oldBrush = (HBRUSH) SelectObject (hdc, brush);
    HBITMAP oldBitmap = (HBITMAP) SelectObject (bitmapDc, _HBitmap);
    
    
    TextOut (hdc, 5,5,L"CCCCC", 5);
    Rectangle (hdc, 0,0,0,0);

    for (int x=0; x<10; ++x)
    {
        for (int y=0; y<10; ++y)
        {
            BitBlt (hdc, x*_BitmapWidth, y*_BitmapHeight, _BitmapWidth, _BitmapHeight, bitmapDc, 0, 0, SRCCOPY);
        }
    }

    SelectObject (hdc, oldPen);
    SelectObject (hdc, oldBrush);

    SelectObject (bitmapDc, oldBitmap);
    

    DeleteObject (pen);
    DeleteObject (brush);
    DeleteDC (bitmapDc);
}
void ImageWindow::OnMousePressed( int x, int y, MouseButton mouseButton )
{
}

void ImageWindow::OnMouseReleased( int x, int y, MouseButton mouseButton )
{
}

void ImageWindow::OnMouseMove( int x, int y )
{
}

void ImageWindow::OnKeyPressed( unsigned int keyCode )
{
    if (keyCode == VK_ESCAPE)
    {
        PostQuitMessage(0);
    }
}