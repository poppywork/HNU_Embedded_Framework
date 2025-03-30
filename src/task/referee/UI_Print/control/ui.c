#include "ui.h"
#include "priority_ui.h"

#define AIM_X  956
#define AIM_Y  395
void rotate(uint16_t *x, uint16_t *y, float mid_x, float mid_y, float angle);
void rotate_arc(ui_config_t *config, float mid_x, float mid_y, float angle);
void Spin_Rp_Ui(void);

ui_info_t dynamic_ui_info [DYNAMIC_UI_NUM] =
        {
        [Frc] = {
                /*��������*/
                .ui_config.priority = HIGH_PRIORITY, // UI���ȼ�(����̬UI��Ҫ����)
                .ui_config.ui_type = CHAR, // UI��������
                /*�ɱ�����*/
                .ui_config.operate_type = MODIFY, // ��������
                .ui_config.layer = 0, // ͼ������0~9
                .ui_config.color = FUCHSIA, // ��ɫ
                .ui_config.size = 35, // �����С
                .ui_config.width = 3, // �������
                .ui_config.start_x = 430, // ��� x ����
                .ui_config.start_y = 850, // ��� y ����
                .ui_config.text = "Frc",
        },
        [Rot] = {
                /*��������*/
                .ui_config.priority = HIGH_PRIORITY, // UI���ȼ�(����̬UI��Ҫ����)
                .ui_config.ui_type = CHAR, // UI��������
                /*�ɱ�����*/
                .ui_config.operate_type = MODIFY, // ��������
                .ui_config.layer = 0, // ͼ������0~9
                .ui_config.color = FUCHSIA, // ��ɫ
                .ui_config.size = 35, // �����С
                .ui_config.width = 3, // �������
                .ui_config.start_x = 430, // ��� x ����
                .ui_config.start_y = 775, // ��� y ����
                .ui_config.text = "Rot",
        },
        [Aim] = {
                /*��������*/
                .ui_config.priority = HIGH_PRIORITY, // UI���ȼ�(����̬UI��Ҫ����)
                .ui_config.ui_type = CHAR, // UI��������
                /*�ɱ�����*/
                .ui_config.operate_type = MODIFY, // ��������
                .ui_config.layer = 0, // ͼ������0~9
                .ui_config.color = FUCHSIA, // ��ɫ
                .ui_config.size = 35, // �����С
                .ui_config.width = 3, // �������
                .ui_config.start_x = 430, // ��� x ����
                .ui_config.start_y = 700, // ��� y ����
                .ui_config.text = "Aim",
        },
        [Aim_Frame] = {
                /*��������*/
                .ui_config.priority = LOW_PRIORITY, // UI���ȼ�(����̬UI��Ҫ����)
                .ui_config.ui_type = CIRCLE, // UI��������
                /*�ɱ�����*/
                .ui_config.operate_type = MODIFY, // ��������
                .ui_config.layer = 1, // ͼ������0~9
                .ui_config.color = RED_BLUE, // ��ɫ
                .ui_config.width = 5, // �������
                .ui_config.start_x = 960, // ��� x ����
                .ui_config.start_y = 540, // ��� y ����
                .ui_config.radius = 250,
        },
        [Carline_L] = {
                /*��������*/
                .ui_config.priority = LOW_PRIORITY, // UI���ȼ�(����̬UI��Ҫ����)
                .ui_config.ui_type = LINE, // UI��������
                /*�ɱ�����*/
                .ui_config.operate_type = MODIFY, // ��������
                .ui_config.layer = 1, // ͼ������0~9
                .ui_config.color = ORANGE, // ��ɫ
                .ui_config.width = 5, // �������
                .ui_config.start_x = 529, // ��� x ����
                .ui_config.start_y = 102, // ��� y ����
                .ui_config.end_x = 783,
                .ui_config.end_y = 445,
        },
        [Carline_R] = {
                /*��������*/
                .ui_config.priority = LOW_PRIORITY, // UI���ȼ�(����̬UI��Ҫ����)
                .ui_config.ui_type = LINE, // UI��������
                /*�ɱ�����*/
                .ui_config.operate_type = MODIFY, // ��������
                .ui_config.layer = 1, // ͼ������0~9
                .ui_config.color = ORANGE, // ��ɫ
                .ui_config.width = 5, // �������
                .ui_config.start_x = 1391, // ��� x ����
                .ui_config.start_y = 102, // ��� y ����
                .ui_config.end_x = 1137,
                .ui_config.end_y = 445,
        },
        [Cross_H] = {
                /*��������*/
                .ui_config.priority = LOW_PRIORITY, // UI���ȼ�(����̬UI��Ҫ����)
                .ui_config.ui_type = LINE, // UI��������
                /*�ɱ�����*/
                .ui_config.operate_type = MODIFY, // ��������
                .ui_config.layer = 1, // ͼ������0~9
                .ui_config.color = CYAN_BLUE, // ��ɫ
                .ui_config.width = 2, // �������
                .ui_config.start_x = 935, // ��� x ����
                .ui_config.start_y = 540, // ��� y ����
                .ui_config.end_x = 985,
                .ui_config.end_y = 540,
        },
        [Cross_V] = {
                /*��������*/
                .ui_config.priority = LOW_PRIORITY, // UI���ȼ�(����̬UI��Ҫ����)
                .ui_config.ui_type = LINE, // UI��������
                /*�ɱ�����*/
                .ui_config.operate_type = MODIFY, // ��������
                .ui_config.layer = 1, // ͼ������0~9
                .ui_config.color = CYAN_BLUE, // ��ɫ
                .ui_config.width = 2, // �������
                .ui_config.start_x = 960, // ��� x ����
                .ui_config.start_y = 570, // ��� y ����
                .ui_config.end_x = 960,
                .ui_config.end_y = 180,
        },
        [Heat_Indicator] = {
                /*��������*/
                .ui_config.priority = HIGH_PRIORITY, // UI���ȼ�(����̬UI��Ҫ����)
                .ui_config.ui_type = CHAR, // UI��������
                /*�ɱ�����*/
                .ui_config.operate_type = MODIFY, // ��������
                .ui_config.layer = 0, // ͼ������0~9
                .ui_config.color = GREEN, // ��ɫ
                .ui_config.size = 30, // �����С
                .ui_config.width = 3, // �������
                .ui_config.start_x = 1320, // ��� x ����
                .ui_config.start_y = 720, // ��� y ����
                .ui_config.text = "HEAT",
        },
        [Aim_Point] = {
                /*��������*/
                .ui_config.priority = LOW_PRIORITY, // UI���ȼ�(����̬UI��Ҫ����)
                .ui_config.ui_type = CIRCLE, // UI��������
                /*�ɱ�����*/
                .ui_config.operate_type = MODIFY, // ��������
                .ui_config.layer = 3, // ͼ������0~9
                .ui_config.color = ORANGE, // ��ɫ
                .ui_config.width = 2, // �������
                .ui_config.start_x = 960, // ��� x ����
                .ui_config.start_y = 510, // ��� y ����
                .ui_config.radius = 5,
        },



        };

ui_info_t const_ui_info [0] =
        {

        };


/**
  @brief: ��ʼ��UI���� main.c�е���
 */
void My_Ui_Init(void)
{
    Init_Ui_List(dynamic_ui_info, sizeof(dynamic_ui_info)/sizeof(ui_info_t),const_ui_info, sizeof(const_ui_info)/sizeof(ui_info_t));
}

extern uint8_t send_test;

extern uint8_t send_test;
static char s[5] = "Heat:";
static char t[1] = "/";

void Ui_Info_Update(struct gimbal_cmd_msg gim_cmd,struct chassis_cmd_msg chassis_cmd,struct shoot_cmd_msg shoot_cmd,struct referee_msg referee)
{
    if (send_test != 0)
    {
        return;
    }

    if (shoot_cmd.friction_status == 1)
    {
        dynamic_ui_info[Frc].ui_config.color = GREEN;
        Enqueue_Ui_For_Sending(&dynamic_ui_info[Frc]);
    }
    else
    {
        dynamic_ui_info[Frc].ui_config.color = FUCHSIA;
        Enqueue_Ui_For_Sending(&dynamic_ui_info[Frc]);
    }

    if (chassis_cmd.ctrl_mode == CHASSIS_SPIN)
    {
        dynamic_ui_info[Rot].ui_config.color = GREEN;
        Enqueue_Ui_For_Sending(&dynamic_ui_info[Rot]);
    }
    else
    {
        dynamic_ui_info[Rot].ui_config.color = FUCHSIA;
        Enqueue_Ui_For_Sending(&dynamic_ui_info[Rot]);
    }

    if (gim_cmd.ctrl_mode == 3)//GIM_AUTO
    {
        dynamic_ui_info[Aim].ui_config.color = GREEN;
        Enqueue_Ui_For_Sending(&dynamic_ui_info[Aim]);
    }
    else
    {
        dynamic_ui_info[Aim].ui_config.color = FUCHSIA;
        Enqueue_Ui_For_Sending(&dynamic_ui_info[Aim]);
    }

    uint16_t last_heat = 0;

    if (last_heat != referee.power_heat_data.shooter_17mm_1_barrel_heat)
    {
        static char r[12];
        char *p = r;
        for(int i=0; i<5 && s[i]; i++) *p++ = s[i];
        for(int i=100; i>=1; i/=10) *p++ = '0' + referee.power_heat_data.shooter_17mm_1_barrel_heat/i%10;
        for(int i=0; i<1 && t[i]; i++) *p++ = t[i];
        for(int i=100; i>=1; i/=10) *p++ = '0' + referee.robot_status.shooter_barrel_heat_limit/i%10;
        *p = 0;
        memcpy(dynamic_ui_info[Heat_Indicator].ui_config.text, r, sizeof(r));
        Enqueue_Ui_For_Sending(&dynamic_ui_info[Heat_Indicator]);
        last_heat = referee.power_heat_data.shooter_17mm_1_barrel_heat;
    }
}


