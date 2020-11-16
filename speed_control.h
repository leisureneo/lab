#ifndef __SPEED_CONTROL_H__
#define __SPEED_CONTROL_H__

typedef struct
{
  speed_Vx;
  speed_Vy;
}depart;

void limited_speed(int mode,float angle);
#endif
