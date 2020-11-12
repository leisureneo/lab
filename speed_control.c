#include "speed_control.h" e
#include <math.h>       /* sin */

/*定义分解速度结构体*/ 
depart de_speed; 

/**************************************************************************
  * @brief      : 一般速度分解 
  * @param      : 
  				speed：所需速度
				angle：下一位置与小车现时位置的夹角 
  * @return     : X，Y轴速度 
***************************************************************************/
static void speed_decomposition(float expected_speed,float angle)
{
	
	de_speed.speed_Vy = expected_speed*(sin((90.0-angle)*PI/180));
    de_speed.speed_Vx = expected_speed*(cos((90.0-angle)*PI/180));
    
}

/**************************************************************************
  * @brief      : 速度限制 
  * @param      : 
  				mode：速度档位选择，请在下面选择相应档位 
				  @arg：1- 0.5M/S
				        2- 0.5M/S 
				        3- 0.5M/S  
				angle：下一位置与小车现时位置的夹角 
  * @return     : X，Y轴速度 
***************************************************************************/
void limited_speed(int mode,float angle)
{
	switch(mode)
	{
		case 1:
			speed_decomposition(0.5,angle);
			break;
		case 2:
			speed_decomposition(0.75,angle);
			break;
		case 3:
			speed_decomposition(1.0,angle);
			break;
	} 

}
