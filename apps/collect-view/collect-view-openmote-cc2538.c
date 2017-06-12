#include "collect-view.h"
#include "dev/button-sensor.h"
#include "dev/adxl346.h"
#include "dev/sht21.h"
#include "dev/max44009.h"

#include "collect-view-openmote-cc2538.h"

/*---------------------------------------------------------------------------*/
void
collect_view_arch_read_sensors(struct collect_view_data_msg *msg)
{
  SENSORS_ACTIVATE(sht21);
  SENSORS_ACTIVATE(max44009);
  SENSORS_ACTIVATE(adxl346);

  msg->sensors[TEMP_SENSOR] = (int16_t)sht21.value(SHT21_READ_TEMP);
  msg->sensors[HUMIDITY_SENSOR] = (int16_t)sht21.value(SHT21_READ_RHUM);
  msg->sensors[LIGHT_SENSOR] = (int16_t)max44009.value(MAX44009_READ_LIGHT);
  msg->sensors[ACCELEROMETER_X_SENSOR] = (int16_t)adxl346.value(ADXL346_READ_X_mG);
  msg->sensors[ACCELEROMETER_Y_SENSOR] = (int16_t)adxl346.value(ADXL346_READ_Y_mG);
  msg->sensors[ACCELEROMETER_Z_SENSOR] = (int16_t)adxl346.value(ADXL346_READ_Z_mG);

//  SENSORS_DEACTIVATE(temp_sensor);
//  SENSORS_DEACTIVATE(humidity_sensor);
//  SENSORS_DEACTIVATE(light_sensor);
//  SENSORS_DEACTIVATE(acceleration_sensor);
}
/*---------------------------------------------------------------------------*/
