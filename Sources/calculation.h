/*! @file
 *
 *  @brief calculation of voltages and currents
 *
 *
 *  @author Lucien Tran
 *  @date 2019-04-16
 */

#include <math.h> // Including math.h to do the square root of some values
#include "types.h"

typedef struct
{
  float voltage[16];
  float voltageSqr[16];
  float totalVoltageSqr;
  float voltageRMS;
  float currentRMS;
}TChannelData;

typedef struct
{
  uint8_t crossing1;
  uint8_t crossing2;
}TCrossing;

#define ADC_RATE            3276.7 // Convert 16 bit high and low to +-10V
#define ANALOG_TO_VOLT(X)   (float) X / (float) ADC_RATE
#define VOLT_TO_ANALOG(X)   (int16_t) (float) X * (float) ADC_RATE
typedef enum
{
  INVERSE,
  VERY_INVERSE,
  EXTREMELY_INVERSE
}TCharacteristic;

TCharacteristic Current_Charac; // Keeping track of the current mode INVERSE, VERY INVERSE, EXTREMELY INVERSE


/*! @brief Keeps the 16 samples of voltages, voltages square and running total of the square
 *
 * @param data - newest sample taken by uC
 * @param channelData - tracking of indepedent voltages for each channel
 */
void Sliding_voltage(float data,TChannelData* channelData);

/*! @brief Returns the voltage RMS, calculated from global variable totalVoltageSqr
 *
 *  @param channelData - tracking of indepedent voltages for each channel
 *
 *  @return float - value of voltage RMS
 */
float Real_RMS(TChannelData* channelData);

/*! @brief Converts voltage RMS to current RMS
 *
 *  @param voltageRMS - voltageRMS to be converted 
 *  @return float - current RMS
 */
float Current_RMS(float voltageRMS);


/*! @brief Calculates the goal to reach before tripping the circuit 
 *
 *  @param currentRMS - current that corresponds to the trip goal to reach
 *  @return uint32_t - goal to reach
 */
uint32_t Calculate_TripGoal(float currentRMS);

/*! @brief Checks for zero crossings
 *
 *
 *  @return bool - TRUE if found zero crossings
 */
bool Zero_Crossings(float sample[], TCrossing* crossing);

/*! @brief Calculates the frequency and set PIT from the crossings
 *
 *
 *  @return bool - TRUE if frequency has been set and is between 47.5 and 52.5Hz
 */
float Calculate_Frequency(TCrossing* crossing);

//
