

#include "app.h"
char pressureVal_g = 0;
void APP_init()
{
	GPIO_INITIALIZATION();
	Set_Alarm_actuator(1);
}
void APP_start()
{
	while (1)
	{
		pressureVal_g = getPressureVal();
		
		if ( pressureVal_g > 0x14 ) // 20 = 0x14
		{
			Set_Alarm_actuator(0);
			Delay(60);
		}			
		Set_Alarm_actuator(1);
	}
}