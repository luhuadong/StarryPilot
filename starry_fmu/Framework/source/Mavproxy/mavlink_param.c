/*
 * File      : mavlink_param.c
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-08-16     weety    first version.
 */
 
#include <string.h>
#include "global.h"
#include "param.h"
#include "console.h"
#include "mavlink_param.h"

static mavlink_param_t mavlink_param = {
	MAVLINK_PARAM_DEFINE(SYS_AUTOSTART, 4001),
	MAVLINK_PARAM_DEFINE(SYS_AUTOCONFIG, 0),
	MAVLINK_PARAM_DEFINE(SYS_PARAM_VER, 0.2),
	MAVLINK_PARAM_DEFINE(MAV_SYS_ID, 1),
	MAVLINK_PARAM_DEFINE(MAV_COMP_ID, 1),
	MAVLINK_PARAM_DEFINE(MAV_PROTO_VER, 1),
	MAVLINK_PARAM_DEFINE(MAV_RADIO_ID, 0),
	MAVLINK_PARAM_DEFINE(MAV_TYPE, 2), //MAV_AIRFRAME_TYPE
	MAVLINK_PARAM_DEFINE(MAV_USEHILGPS, 0),
	MAVLINK_PARAM_DEFINE(MAV_FWDEXTSP, 0),
	MAVLINK_PARAM_DEFINE(MAV_BROADCAST, 0),
	MAVLINK_PARAM_DEFINE(CAL_BOARD_ID, 0),
	MAVLINK_PARAM_DEFINE(CAL_GYRO0_ID, 125),
	MAVLINK_PARAM_DEFINE(CAL_GYRO0_XOFF, 0),
	MAVLINK_PARAM_DEFINE(CAL_GYRO0_YOFF, 0),
	MAVLINK_PARAM_DEFINE(CAL_GYRO0_ZOFF, 0),
	MAVLINK_PARAM_DEFINE(CAL_GYRO0_XSCALE, 1),
	MAVLINK_PARAM_DEFINE(CAL_GYRO0_YSCALE, 1),
	MAVLINK_PARAM_DEFINE(CAL_GYRO0_ZSCALE, 1),
	MAVLINK_PARAM_DEFINE(CAL_MAG0_ID, 130),
	MAVLINK_PARAM_DEFINE(CAL_MAG1_ID, 0),
	MAVLINK_PARAM_DEFINE(CAL_MAG2_ID, 0),
	MAVLINK_PARAM_DEFINE(CAL_MAG0_ROT, ROTATION_NONE),
	MAVLINK_PARAM_DEFINE(CAL_MAG1_ROT, ROTATION_NONE),
	MAVLINK_PARAM_DEFINE(CAL_MAG2_ROT, ROTATION_NONE),
	MAVLINK_PARAM_DEFINE(CAL_MAG0_XOFF, 0),
	MAVLINK_PARAM_DEFINE(CAL_MAG0_YOFF, 0),
	MAVLINK_PARAM_DEFINE(CAL_MAG0_ZOFF, 0),
	MAVLINK_PARAM_DEFINE(CAL_MAG0_XSCALE, 1),
	MAVLINK_PARAM_DEFINE(CAL_MAG0_YSCALE, 1),
	MAVLINK_PARAM_DEFINE(CAL_MAG0_ZSCALE, 1),
	MAVLINK_PARAM_DEFINE(CAL_ACC0_ID, 120),
	MAVLINK_PARAM_DEFINE(CAL_ACC0_XOFF, 0),
	MAVLINK_PARAM_DEFINE(CAL_ACC0_YOFF, 0),
	MAVLINK_PARAM_DEFINE(CAL_ACC0_ZOFF, 0),
	MAVLINK_PARAM_DEFINE(CAL_ACC0_XSCALE, 1),
	MAVLINK_PARAM_DEFINE(CAL_ACC0_YSCALE, 1),
	MAVLINK_PARAM_DEFINE(CAL_ACC0_ZSCALE, 1),
	MAVLINK_PARAM_DEFINE(CAL_ACC_PRIME, 125),
	MAVLINK_PARAM_DEFINE(CAL_GYRO_PRIME, 120),
	MAVLINK_PARAM_DEFINE(CAL_MAG_PRIME, 130),
	MAVLINK_PARAM_DEFINE(CAL_MAG_SIDES, 34),
	MAVLINK_PARAM_DEFINE(CAL_BARO_PRIME, 0),
	MAVLINK_PARAM_DEFINE(SENS_DPRES_OFF, 0),
	MAVLINK_PARAM_DEFINE(SENS_DPRES_ANSC, 0),
	MAVLINK_PARAM_DEFINE(SENS_BARO_QNH, 1013.25f),
	MAVLINK_PARAM_DEFINE(SENS_BOARD_ROT, ROTATION_NONE),
	MAVLINK_PARAM_DEFINE(SENS_FLOW_ROT, ROTATION_NONE),
	MAVLINK_PARAM_DEFINE(SENS_BOARD_X_OFF, 0),
	MAVLINK_PARAM_DEFINE(SENS_BOARD_Y_OFF, 0),
	MAVLINK_PARAM_DEFINE(SENS_BOARD_Z_OFF, 0),
	MAVLINK_PARAM_DEFINE(SENS_EXT_MAG_ROT, ROTATION_NONE),
	MAVLINK_PARAM_DEFINE(SENS_EXT_MAG, ROTATION_NONE),
	MAVLINK_PARAM_DEFINE(TRIM_ROLL, 0),
	MAVLINK_PARAM_DEFINE(TRIM_PITCH, 0),
	MAVLINK_PARAM_DEFINE(TRIM_YAW, 0),
	MAVLINK_PARAM_DEFINE(RC1_MIN, 1000),
	MAVLINK_PARAM_DEFINE(RC1_TRIM, 1500),
	MAVLINK_PARAM_DEFINE(RC1_MAX, 2000),
	MAVLINK_PARAM_DEFINE(RC1_REV, 1),
	MAVLINK_PARAM_DEFINE(RC1_DZ, 50),
	MAVLINK_PARAM_DEFINE(RC2_MIN, 1000),
	MAVLINK_PARAM_DEFINE(RC2_TRIM, 1500),
	MAVLINK_PARAM_DEFINE(RC2_MAX, 2000),
	MAVLINK_PARAM_DEFINE(RC2_REV, 1),
	MAVLINK_PARAM_DEFINE(RC2_DZ, 50),
	MAVLINK_PARAM_DEFINE(RC3_MIN, 1000),
	MAVLINK_PARAM_DEFINE(RC3_TRIM, 1500),
	MAVLINK_PARAM_DEFINE(RC3_MAX, 2000),
	MAVLINK_PARAM_DEFINE(RC3_REV, 1),
	MAVLINK_PARAM_DEFINE(RC3_DZ, 50),
	MAVLINK_PARAM_DEFINE(RC4_MIN, 1000),
	MAVLINK_PARAM_DEFINE(RC4_TRIM, 1500),
	MAVLINK_PARAM_DEFINE(RC4_MAX, 2000),
	MAVLINK_PARAM_DEFINE(RC4_REV, 1),
	MAVLINK_PARAM_DEFINE(RC4_DZ, 50),
	MAVLINK_PARAM_DEFINE(RC5_MIN, 1000),
	MAVLINK_PARAM_DEFINE(RC5_TRIM, 1500),
	MAVLINK_PARAM_DEFINE(RC5_MAX, 2000),
	MAVLINK_PARAM_DEFINE(RC5_REV, 1),
	MAVLINK_PARAM_DEFINE(RC5_DZ, 50),
	MAVLINK_PARAM_DEFINE(RC6_MIN, 1000),
	MAVLINK_PARAM_DEFINE(RC6_TRIM, 1500),
	MAVLINK_PARAM_DEFINE(RC6_MAX, 2000),
	MAVLINK_PARAM_DEFINE(RC6_REV, 1),
	MAVLINK_PARAM_DEFINE(RC6_DZ, 50),
	MAVLINK_PARAM_DEFINE(RC7_MIN, 1000),
	MAVLINK_PARAM_DEFINE(RC7_TRIM, 1500),
	MAVLINK_PARAM_DEFINE(RC7_MAX, 2000),
	MAVLINK_PARAM_DEFINE(RC7_REV, 1),
	MAVLINK_PARAM_DEFINE(RC7_DZ, 50),
	MAVLINK_PARAM_DEFINE(RC8_MIN, 1000),
	MAVLINK_PARAM_DEFINE(RC8_TRIM, 1500),
	MAVLINK_PARAM_DEFINE(RC8_MAX, 2000),
	MAVLINK_PARAM_DEFINE(RC8_REV, 1),
	MAVLINK_PARAM_DEFINE(RC8_DZ, 50),
	MAVLINK_PARAM_DEFINE(RC9_MIN, 1000),
	MAVLINK_PARAM_DEFINE(RC9_TRIM, 1500),
	MAVLINK_PARAM_DEFINE(RC9_MAX, 2000),
	MAVLINK_PARAM_DEFINE(RC9_REV, 1),
	MAVLINK_PARAM_DEFINE(RC9_DZ, 50),
	MAVLINK_PARAM_DEFINE(RC10_MIN, 1000),
	MAVLINK_PARAM_DEFINE(RC10_TRIM, 1500),
	MAVLINK_PARAM_DEFINE(RC10_MAX, 2000),
	MAVLINK_PARAM_DEFINE(RC10_REV, 1),
	MAVLINK_PARAM_DEFINE(RC10_DZ, 50),
	MAVLINK_PARAM_DEFINE(RC11_MIN, 1000),
	MAVLINK_PARAM_DEFINE(RC11_TRIM, 1500),
	MAVLINK_PARAM_DEFINE(RC11_MAX, 2000),
	MAVLINK_PARAM_DEFINE(RC11_REV, 1),
	MAVLINK_PARAM_DEFINE(RC11_DZ, 50),
	MAVLINK_PARAM_DEFINE(RC12_MIN, 1000),
	MAVLINK_PARAM_DEFINE(RC12_TRIM, 1500),
	MAVLINK_PARAM_DEFINE(RC12_MAX, 2000),
	MAVLINK_PARAM_DEFINE(RC12_REV, 1),
	MAVLINK_PARAM_DEFINE(RC12_DZ, 50),
	MAVLINK_PARAM_DEFINE(RC13_MIN, 1000),
	MAVLINK_PARAM_DEFINE(RC13_TRIM, 1500),
	MAVLINK_PARAM_DEFINE(RC13_MAX, 2000),
	MAVLINK_PARAM_DEFINE(RC13_REV, 1),
	MAVLINK_PARAM_DEFINE(RC13_DZ, 50),
	MAVLINK_PARAM_DEFINE(RC14_MIN, 1000),
	MAVLINK_PARAM_DEFINE(RC14_TRIM, 1500),
	MAVLINK_PARAM_DEFINE(RC14_MAX, 2000),
	MAVLINK_PARAM_DEFINE(RC14_REV, 1),
	MAVLINK_PARAM_DEFINE(RC14_DZ, 50),
	MAVLINK_PARAM_DEFINE(RC15_MIN, 1000),
	MAVLINK_PARAM_DEFINE(RC15_TRIM, 1500),
	MAVLINK_PARAM_DEFINE(RC15_MAX, 2000),
	MAVLINK_PARAM_DEFINE(RC15_REV, 1),
	MAVLINK_PARAM_DEFINE(RC15_DZ, 50),
	MAVLINK_PARAM_DEFINE(RC16_MIN, 1000),
	MAVLINK_PARAM_DEFINE(RC16_TRIM, 1500),
	MAVLINK_PARAM_DEFINE(RC16_MAX, 2000),
	MAVLINK_PARAM_DEFINE(RC16_REV, 1),
	MAVLINK_PARAM_DEFINE(RC16_DZ, 50),
	MAVLINK_PARAM_DEFINE(RC17_MIN, 1000),
	MAVLINK_PARAM_DEFINE(RC17_TRIM, 1500),
	MAVLINK_PARAM_DEFINE(RC17_MAX, 2000),
	MAVLINK_PARAM_DEFINE(RC17_REV, 1),
	MAVLINK_PARAM_DEFINE(RC17_DZ, 50),
	MAVLINK_PARAM_DEFINE(RC18_MIN, 1000),
	MAVLINK_PARAM_DEFINE(RC18_TRIM, 1500),
	MAVLINK_PARAM_DEFINE(RC18_MAX, 2000),
	MAVLINK_PARAM_DEFINE(RC18_REV, 1),
	MAVLINK_PARAM_DEFINE(RC18_DZ, 50),
	MAVLINK_PARAM_DEFINE(RC_MAP_ROLL, 1),
	MAVLINK_PARAM_DEFINE(RC_MAP_PITCH, 2),
	MAVLINK_PARAM_DEFINE(RC_MAP_YAW, 4),
	MAVLINK_PARAM_DEFINE(RC_MAP_THROTTLE, 3),
	MAVLINK_PARAM_DEFINE(RC_MAP_FAILSAFE, 0),
	MAVLINK_PARAM_DEFINE(RC_MAP_MODE_SW, 5),
	MAVLINK_PARAM_DEFINE(RC_MAP_RETURN_SW, 7),
	MAVLINK_PARAM_DEFINE(RC_MAP_FLAPS, 0),
	MAVLINK_PARAM_DEFINE(RC_MAP_RATT_SW, 0),
	MAVLINK_PARAM_DEFINE(RC_MAP_POSCTL_SW, 0),
	MAVLINK_PARAM_DEFINE(RC_MAP_LOITER_SW, 0),
	MAVLINK_PARAM_DEFINE(RC_MAP_ACRO_SW, 0),
	MAVLINK_PARAM_DEFINE(RC_MAP_OFFB_SW, 0),
	MAVLINK_PARAM_DEFINE(RC_MAP_KILL_SW, 9),
	MAVLINK_PARAM_DEFINE(RC_MAP_AUX1, 5),
	MAVLINK_PARAM_DEFINE(RC_MAP_AUX2, 6),
	MAVLINK_PARAM_DEFINE(RC_MAP_AUX3, 7),
	MAVLINK_PARAM_DEFINE(RC_MAP_AUX4, 8),
	MAVLINK_PARAM_DEFINE(RC_MAP_AUX5, 0),
	MAVLINK_PARAM_DEFINE(RC_MAP_PARAM1, 0),
	MAVLINK_PARAM_DEFINE(RC_MAP_PARAM2, 0),
	MAVLINK_PARAM_DEFINE(RC_MAP_PARAM3, 0),
	MAVLINK_PARAM_DEFINE(RC_MAP_FLTMODE, 0),
	MAVLINK_PARAM_DEFINE(RC_FAILS_THR, 0),
	MAVLINK_PARAM_DEFINE(RC_ASSIST_TH, 0.25),
	MAVLINK_PARAM_DEFINE(RC_AUTO_TH, 0.75),
	MAVLINK_PARAM_DEFINE(RC_RATT_TH, 0.5),
	MAVLINK_PARAM_DEFINE(RC_POSCTL_TH, 0.5),
	MAVLINK_PARAM_DEFINE(RC_RETURN_TH, 0.5),
	MAVLINK_PARAM_DEFINE(RC_LOITER_TH, 0.5),
	MAVLINK_PARAM_DEFINE(RC_ACRO_TH, 0.5),
	MAVLINK_PARAM_DEFINE(RC_OFFB_TH, 0.5),
	MAVLINK_PARAM_DEFINE(RC_KILLSWITCH_TH, 0.7),
	MAVLINK_PARAM_DEFINE(RC_CHAN_CNT, 0),
	MAVLINK_PARAM_DEFINE(RC_TH_USER, 1),
	MAVLINK_PARAM_DEFINE(COM_DL_LOSS_T, 10),
	MAVLINK_PARAM_DEFINE(COM_DL_REG_T, 0),
	MAVLINK_PARAM_DEFINE(COM_EF_THROT, 0.5),
	MAVLINK_PARAM_DEFINE(COM_EF_C2T, 5),
	MAVLINK_PARAM_DEFINE(COM_EF_TIME, 10),
	MAVLINK_PARAM_DEFINE(COM_RC_LOSS_T, 0.5),
	MAVLINK_PARAM_DEFINE(COM_HOME_H_T, 5),
	MAVLINK_PARAM_DEFINE(COM_HOME_V_T, 10),
	MAVLINK_PARAM_DEFINE(COM_AUTOS_PAR, 1),
	MAVLINK_PARAM_DEFINE(COM_RC_IN_MODE, 0),
	MAVLINK_PARAM_DEFINE(COM_RC_ARM_HYST, 1000),
	MAVLINK_PARAM_DEFINE(COM_DISARM_LAND, 2),
	MAVLINK_PARAM_DEFINE(COM_LOW_BAT_ACT, 1),
	MAVLINK_PARAM_DEFINE(BAT_H_CURR, 12),
	MAVLINK_PARAM_DEFINE(BAT_V_CURR, 10),
	MAVLINK_PARAM_DEFINE(BAT_C_SAFE, 700),
	MAVLINK_PARAM_DEFINE(BAT_C_SAFE_UB, 1500),
	MAVLINK_PARAM_DEFINE(BAT_V_SCALE_IO, 100),
	MAVLINK_PARAM_DEFINE(BAT_CNT_V_VOLT, -1),
	MAVLINK_PARAM_DEFINE(BAT_CNT_V_CURR, -1),
	MAVLINK_PARAM_DEFINE(BAT_V_OFFS_CURR, 0),
	MAVLINK_PARAM_DEFINE(BAT_V_DIV, 10.19699955),
	MAVLINK_PARAM_DEFINE(BAT_A_PER_V, -1),
	MAVLINK_PARAM_DEFINE(BAT_V_EMPTY, 3.2),
	MAVLINK_PARAM_DEFINE(BAT_V_CHARGED, 4.2),
	MAVLINK_PARAM_DEFINE(BAT_LOW_THR, 0.2),
	MAVLINK_PARAM_DEFINE(BAT_CRIT_THR, 0.1),
	MAVLINK_PARAM_DEFINE(BAT_EMERGEN_THR, 0.05),
	MAVLINK_PARAM_DEFINE(BAT_V_LOAD_DROP, 0.3),
	MAVLINK_PARAM_DEFINE(BAT_N_CELLS, 4),
	MAVLINK_PARAM_DEFINE(BAT_CAPACITY, -1),
	MAVLINK_PARAM_DEFINE(NAV_DLL_ACT, 0),
	MAVLINK_PARAM_DEFINE(NAV_RCL_ACT, 2),
	MAVLINK_PARAM_DEFINE(RTL_RETURN_ALT, 15),
	MAVLINK_PARAM_DEFINE(RTL_DESCEND_ALT, 30),
	MAVLINK_PARAM_DEFINE(RTL_LAND_DELAY, 3),
	MAVLINK_PARAM_DEFINE(RTL_MIN_DIST, 0.5),
	MAVLINK_PARAM_DEFINE(COM_FLTMODE1, 0),
	MAVLINK_PARAM_DEFINE(COM_FLTMODE2, 1),
	MAVLINK_PARAM_DEFINE(COM_FLTMODE3, 2),
	MAVLINK_PARAM_DEFINE(COM_FLTMODE4, 3),
	MAVLINK_PARAM_DEFINE(COM_FLTMODE5, 4),
	MAVLINK_PARAM_DEFINE(COM_FLTMODE6, 5),
	MAVLINK_PARAM_DEFINE(GF_ACTION, 1),
	MAVLINK_PARAM_DEFINE(GF_ALTMODE, 0),
	MAVLINK_PARAM_DEFINE(GF_SOURCE, 0),
	MAVLINK_PARAM_DEFINE(GF_COUNT, -1),
	MAVLINK_PARAM_DEFINE(GF_MAX_HOR_DIST, -1),
	MAVLINK_PARAM_DEFINE(GF_MAX_VER_DIST, -1),
	MAVLINK_PARAM_DEFINE(GF_FENCE_SW, 1),
	MAVLINK_PARAM_DEFINE(MC_ROLL_TC, 0.0),
	MAVLINK_PARAM_DEFINE(MC_PITCH_TC, 0.0),
	MAVLINK_PARAM_DEFINE(MC_ROLL_P, 0.0),
	MAVLINK_PARAM_DEFINE(MC_ROLLRATE_P, 0.0),
	MAVLINK_PARAM_DEFINE(MC_ROLLRATE_I, 0.0),
	MAVLINK_PARAM_DEFINE(MC_ROLLRATE_D, 0.0),
	MAVLINK_PARAM_DEFINE(MC_PITCH_P, 0.0),
	MAVLINK_PARAM_DEFINE(MC_PITCHRATE_P, 0.0),
	MAVLINK_PARAM_DEFINE(MC_PITCHRATE_I, 0.0),
	MAVLINK_PARAM_DEFINE(MC_PITCHRATE_D, 0.0),
	MAVLINK_PARAM_DEFINE(MC_YAW_P, 0.0),
	MAVLINK_PARAM_DEFINE(MC_YAWRATE_P, 0.0),
	MAVLINK_PARAM_DEFINE(MC_YAWRATE_I, 0.0),
	MAVLINK_PARAM_DEFINE(MC_YAWRATE_D, 0.0),
	MAVLINK_PARAM_DEFINE(MPC_THR_MIN, 0.15),
	MAVLINK_PARAM_DEFINE(MPC_THR_HOVER, 0.5),
	MAVLINK_PARAM_DEFINE(MPC_THR_MAX, 0.9),
	MAVLINK_PARAM_DEFINE(MPC_MANTHR_MIN, 0.15),
	MAVLINK_PARAM_DEFINE(MPC_MANTHR_MAX, 0.9),
	MAVLINK_PARAM_DEFINE(MPC_Z_P, 0.0),
	MAVLINK_PARAM_DEFINE(MPC_Z_VEL_P, 0.0),
	MAVLINK_PARAM_DEFINE(MPC_Z_VEL_I, 0.0),
	MAVLINK_PARAM_DEFINE(MPC_Z_VEL_D, 0.0),
	MAVLINK_PARAM_DEFINE(MPC_XY_P, 0.0),
	MAVLINK_PARAM_DEFINE(MPC_XY_VEL_P, 0.0),
	MAVLINK_PARAM_DEFINE(MPC_XY_VEL_I, 0.0),
	MAVLINK_PARAM_DEFINE(MPC_XY_VEL_D, 0.0),
};

void mavlink_param_init(void)
{
	param_info_t *param;
	param_t *mav_param = &mavlink_param;

	mav_param[CAL_GYRO0_XOFF].param = param_get_by_name("GYR_X_OFFSET");
	mav_param[CAL_GYRO0_YOFF].param = param_get_by_name("GYR_Y_OFFSET");
	mav_param[CAL_GYRO0_ZOFF].param = param_get_by_name("GYR_Z_OFFSET");
	mav_param[CAL_GYRO0_XSCALE].param = param_get_by_name("GYR_X_GAIN");
	mav_param[CAL_GYRO0_YSCALE].param = param_get_by_name("GYR_Y_GAIN");
	mav_param[CAL_GYRO0_ZSCALE].param = param_get_by_name("GYR_Z_GAIN");

	mav_param[CAL_MAG0_XOFF].param = param_get_by_name("MAG_X_OFFSET");
	mav_param[CAL_MAG0_YOFF].param = param_get_by_name("MAG_Y_OFFSET");
	mav_param[CAL_MAG0_ZOFF].param = param_get_by_name("MAG_Z_OFFSET");
	mav_param[CAL_MAG0_XSCALE].param = param_get_by_name("MAG_TRANS_MAT00");
	mav_param[CAL_MAG0_YSCALE].param = param_get_by_name("MAG_TRANS_MAT11");
	mav_param[CAL_MAG0_ZSCALE].param = param_get_by_name("MAG_TRANS_MAT22");

	mav_param[CAL_ACC0_XOFF].param = param_get_by_name("ACC_X_OFFSET");
	mav_param[CAL_ACC0_YOFF].param = param_get_by_name("ACC_Y_OFFSET");
	mav_param[CAL_ACC0_ZOFF].param = param_get_by_name("ACC_Z_OFFSET");
	mav_param[CAL_ACC0_XSCALE].param = param_get_by_name("ACC_TRANS_MAT00");
	mav_param[CAL_ACC0_YSCALE].param = param_get_by_name("ACC_TRANS_MAT11");
	mav_param[CAL_ACC0_ZSCALE].param = param_get_by_name("ACC_TRANS_MAT22");

	mav_param[MC_ROLLRATE_P].param = param_get_by_name("ATT_ROLL_RATE_P");
	mav_param[MC_ROLLRATE_I].param = param_get_by_name("ATT_ROLL_RATE_I");
	mav_param[MC_ROLLRATE_D].param = param_get_by_name("ATT_ROLL_RATE_D");
	mav_param[MC_PITCHRATE_P].param = param_get_by_name("ATT_PITCH_RATE_P");
	mav_param[MC_PITCHRATE_I].param = param_get_by_name("ATT_PITCH_RATE_I");
	mav_param[MC_PITCHRATE_D].param = param_get_by_name("ATT_PITCH_RATE_D");
	mav_param[MC_YAWRATE_P].param = param_get_by_name("ATT_YAW_RATE_P");
	mav_param[MC_YAWRATE_I].param = param_get_by_name("ATT_YAW_RATE_I");
	mav_param[MC_YAWRATE_D].param = param_get_by_name("ATT_YAW_RATE_D");
	mav_param[MC_ROLL_P].param = param_get_by_name("ATT_ROLL_P");
	mav_param[MC_PITCH_P].param = param_get_by_name("ATT_PITCH_P");
	mav_param[MC_YAW_P].param = param_get_by_name("ATT_YAW_P");

	for (int i = 0; i < MAV_PARAM_NUM; i++) {
		if (mav_param[i].param) {
			param_get_by_info(mav_param[i].param, &(mav_param[i].value));
		}
	}

}

param_t *mavlink_param_get_by_name(const char *name)
{
	int i = 0;
	param_t *mav_param = &mavlink_param;
	for(i = 0 ; i < MAV_PARAM_NUM ; i++) {
		if(strncmp(name, mav_param->name, 16) == 0) {
			if (mav_param->param) {
				switch (mav_param->param->type) {
					case PARAM_TYPE_FLOAT:
						mav_param->value = mav_param->param->val.f;
						break;
					case PARAM_TYPE_INT32:
						memcpy(&(mav_param->value), &(mav_param->param->val.i), sizeof(mav_param->param->val.i));
						break;
					case PARAM_TYPE_UINT32:
						memcpy(&(mav_param->value), &(mav_param->param->val.u), sizeof(mav_param->param->val.u));
						break;
					default:
						mav_param->value = mav_param->param->val.f;
						break;
				}
			}
			break;
		}
		mav_param++;
	}

	if (i < MAV_PARAM_NUM) {
		return mav_param;
	} else {
		return NULL;
	}
}

param_t *mavlink_param_get_by_info(param_info_t *param)
{
	int i = 0;
	param_t *mav_param = &mavlink_param;
	for(i = 0 ; i < MAV_PARAM_NUM ; i++) {
		if(mav_param->param == param) {
			if (mav_param->param) {
				switch (mav_param->param->type) {
					case PARAM_TYPE_FLOAT:
						mav_param->value = mav_param->param->val.f;
						break;
					case PARAM_TYPE_INT32:
						memcpy(&(mav_param->value), &(mav_param->param->val.i), sizeof(mav_param->param->val.i));
						break;
					case PARAM_TYPE_UINT32:
						memcpy(&(mav_param->value), &(mav_param->param->val.u), sizeof(mav_param->param->val.u));
						break;
					default:
						mav_param->value = mav_param->param->val.f;
						break;
				}
			}
			break;
		}
		mav_param++;
	}

	if (i < MAV_PARAM_NUM) {
		return mav_param;
	} else {
		return NULL;
	}
}

int mavlink_param_set_value(const char *name, float value)
{
	int i = 0;
	param_info_t* param = NULL;

	param_t *mav_param = &mavlink_param;
	for(i = 0 ; i < MAV_PARAM_NUM ; i++) {
		if(strncmp(name, mav_param->name, 16) == 0) {
			if (mav_param->param) {
				param_set_by_info(mav_param->param, value);
				switch (mav_param->param->type) {
					case PARAM_TYPE_FLOAT:
						mav_param->value = mav_param->param->val.f;
						break;
					case PARAM_TYPE_INT32:
						memcpy(&(mav_param->value), &(mav_param->param->val.i), sizeof(mav_param->param->val.i));
						break;
					case PARAM_TYPE_UINT32:
						memcpy(&(mav_param->value), &(mav_param->param->val.u), sizeof(mav_param->param->val.u));
						break;
					default:
						mav_param->value = mav_param->param->val.f;
						break;
				}
			} else {
				mav_param->value = value;
			}
			break;
		}
		mav_param++;
	}

	if (i < MAV_PARAM_NUM) {
		return 0;
	} else {
		param = param_get_by_name(name);
		if (param) {
			param_set_by_info(param, value);
		}
		return 0;
	}

	return -1;
}

int mavlink_param_set_value_by_index(uint32_t index, float value)
{
	int i = 0;
	param_info_t* param = NULL;
	param_t *mav_param = &mavlink_param;
	if (index >= MAV_PARAM_NUM) {
		return -1;
	}
	mav_param += index;
	if (mav_param->param) {
		param_set_by_info(mav_param->param, value);
		switch (mav_param->param->type) {
			case PARAM_TYPE_FLOAT:
				mav_param->value = mav_param->param->val.f;
				break;
			case PARAM_TYPE_INT32:
				memcpy(&(mav_param->value), &(mav_param->param->val.i), sizeof(mav_param->param->val.i));
				break;
			case PARAM_TYPE_UINT32:
				memcpy(&(mav_param->value), &(mav_param->param->val.u), sizeof(mav_param->param->val.u));
				break;
			default:
				mav_param->value = mav_param->param->val.f;
				break;
		}
	} else {
		mav_param->value = value;
	}

	return 0;
}

uint32_t mavlink_param_get_info_count(void)
{
	return MAV_PARAM_NUM;
}

uint32_t mavlink_param_get_info_index(param_t *param)
{
	param_t *mav_param = &mavlink_param;

	return param - mav_param;
}

param_t * mavlink_param_get_info_by_index(uint32_t index)
{
	param_t *mav_param = &mavlink_param;

	return &mav_param[index];
}

