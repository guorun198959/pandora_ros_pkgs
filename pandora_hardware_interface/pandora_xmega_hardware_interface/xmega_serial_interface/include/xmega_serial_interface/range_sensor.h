/*********************************************************************
*
* Software License Agreement (BSD License)
*
*  Copyright (c) 2014, P.A.N.D.O.R.A. Team.
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*   * Neither the name of the P.A.N.D.O.R.A. Team nor the names of its
*     contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
*  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*
*********************************************************************/

/** @file range_sensor.h
 *  @brief Sonar range sensors header file.
 *
 *  This file contains class and methods used for sonar range measurements.
 *
 *  @author Michael Niarchos
 *  @author Chris Zalidis
 *  @author Konstantinos Panayiotou
 *  @bug No known bug.
 */



#ifndef XMEGA_SERIAL_INTERFACE_RANGE_SENSOR_H
#define XMEGA_SERIAL_INTERFACE_RANGE_SENSOR_H

#include <map>
#include <xmega_serial_interface/sensor_base.h>

namespace pandora_hardware_interface
{
namespace xmega
{
struct RangeData
{
  RangeData() :
    sonarRange(0),
    irRange(0)
  { }
  int sonarRange;
  int irRange;
};

typedef std::map<int, RangeData> RangeMap;

/*!
 *  @class RangeSensor
 *  @brief Sonar Range Sensor class.
 */
class RangeSensor : virtual public SensorBase
{
 public:
  /*! < Default constructor */
  RangeSensor();

  /*! < Default destructor */
  ~RangeSensor();

  /*!
   * @fn virtual void handleData()
   * @brief Handles received sonar data and stores sonar range values.
   */
  virtual void handleData();

 public:
  /*! < Range sensors Map */
  RangeMap sensors;
};

}  // namespace xmega
}  // namespace pandora_hardware_interface

#endif  // XMEGA_SERIAL_INTERFACE_RANGE_SENSOR_H
