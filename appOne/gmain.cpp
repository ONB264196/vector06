#include"libOne.h"
void gmain(){
    window(1000, 1000);
    float rx = 5, ry = 5;
    float bx = 7, by = 7;
    while (notQuit){
        clear(224, 225, 204);
        bx = mathMouseX;
        by = mathMouseY;
        float vx = bx - rx;
        float vy = by - ry;
        float mag = sqrt(vx * vx + vy * vy);
        float nvx = vx / mag;
        float nvy = vy / mag;
        rx += nvx * 0.005f;
        ry += nvy * 0.005f;
        mathAxis(9.1f);
        strokeWeight(10);
        mathArrow(0, 0, vx, vy);
        stroke(31, 30, 51, 127);
        strokeWeight(5);
        mathLine(0, 0, vx, 0);
        mathLine(vx, 0, vx, vy);


        stroke(187, 30, 94, 127);
        strokeWeight(5);
        mathArrow(0, 0, nvx, nvy);
        mathLine(0, 0, nvx, 0);
        mathLine(nvx, 0, nvx, nvy);

        strokeWeight(20);
        stroke(255, 0, 0);
        mathPoint(rx, ry);
        stroke(0, 0, 255);
        mathPoint(bx, by);

        textSize(50);
        text((let)"vec(" + vx + "," + vy + ")", 0, 50);
        text((let)"mag:" + mag, 0, 100);
        text((let)"nvec(" + nvx + "," + nvy + ")", 0, 150);
        mag = sqrt(nvx * nvx + nvy * nvy);
        text((let)"nmag:" + mag, 0, 200);
    }
}
