#ifndef __UI_H
#define __UI_H

#include "main.h"
#include "rm_task.h"

typedef enum{
    Frc,
    Rot,
    Aim,
    Heat_Indicator,
    Cross_H,
    Cross_V,
    Aim_Frame,
    Carline_L,
    Carline_R,
    Aim_Point,
	
	DYNAMIC_UI_NUM,
}dynamic_ui_cnt_e;


void My_Ui_Init(void);
void Ui_Info_Update(struct gimbal_cmd_msg gim_cmd,struct chassis_cmd_msg chassis_cmd,struct shoot_cmd_msg shoot_cmd,struct referee_msg referee);
#endif