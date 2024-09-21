#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    float *xr = (float *)malloc(n * sizeof(float)); // xr => the x_ith co-ordinate of red point.
    float *yr = (float *)malloc(n * sizeof(float));
    float *xb = (float *)malloc(n * sizeof(float));
    float *yb = (float *)malloc(n * sizeof(float));
    int xr_size, xb_size = 0;
    for (int i = 0; i < n; i++)
    {
        float x, y;
        char clr; // color
        scanf("%f", x);
        scanf("%f", y);
        scanf("%c", clr);
        if (clr == 'R')
        {
            xr[i] = x;
            yr[i] = y;
            xr_size++;
        }
        else if (clr == 'B')
        {
            xb[i] = x;
            yb[i] = y;
            xb_size++;
        }
    }
    int mat[xr_size][xb_size];
    int min = INFINITY;
    int x1, x2, y1, y2 = 0;
    for (int i = 0; i < xr_size; i++)
    {
        for (int j = 0; j < xb_size; j++)
        {
            mat[i][j] = sqrt(pow((xr[i] - xb[i]), 2) + pow((yr[i] - yb[i]), 2));
            if (mat[i][j] < min)
            {
                x1 = xr[i];
                x2 = xb[j];
                y1 = yr[i];
                y2 = yb[j];
            }
        }
    }
    int ver_flag, hor_flag = 1;
    // vertical:
    int left, right = 0; // B = 0, R = 1
    float equn = (y1 + y2) / 2;
    if (yr[0] < equn)
    {
        left = 1; // red is on left side
        right = 0;
    }
    else
    {
        left = 0;
        right = 1;
    }
    for (int i = 0; i < xr_size; i++)
    {
        if (yr[i] < equn && right == 1)
        {
            ver_flag = 0;
            break;
        }
        else if (yr[i] > equn && left == 1)
        {
            ver_flag = 0;
            break;
        }
    }
    if (ver_flag != 0)
    {
        for (int i = 0; i < xb_size; i++)
        {
            if (yb[i] < equn && right == 0)
            {
                ver_flag = 0;
                break;
            }
            else if (yb[i] > equn && left == 0)
            {
                ver_flag = 0;
                break;
            }
        }
    }
    // horizontal:
    int left, right = 0; // B = 0, R = 1
    float equn = (y1 + y2) / 2;
    if (yr[0] < equn)
    {
        left = 1; // red is on left side
        right = 0;
    }
    else
    {
        left = 0;
        right = 1;
    }
    for (int i = 0; i < xr_size; i++)
    {
        if (yr[i] < equn && right == 1)
        {
            ver_flag = 0;
            break;
        }
        else if (yr[i] > equn && left == 1)
        {
            ver_flag = 0;
            break;
        }
    }
    if (ver_flag != 0)
    {
        for (int i = 0; i < xb_size; i++)
        {
            if (yb[i] < equn && right == 0)
            {
                ver_flag = 0;
                break;
            }
            else if (yb[i] > equn && left == 0)
            {
                ver_flag = 0;
                break;
            }
        }
    }
    return 0;
}