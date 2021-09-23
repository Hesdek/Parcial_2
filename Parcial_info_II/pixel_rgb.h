#ifndef PIXEL_RGB_H
#define PIXEL_RGB_H


class Pixel_RGB
{
private:
   int red, green, blue;

public:
    Pixel_RGB();
    Pixel_RGB(int r, int g, int b);
    int getRed() const;
    void setRed(int value);
    int getGreen() const;
    void setGreen(int value);
    int getBlue() const;
    void setBlue(int value);

    void setColor(int r, int g, int b);
    void setColor( Pixel_RGB color);
};
#endif // PIXEL_RGB_H
