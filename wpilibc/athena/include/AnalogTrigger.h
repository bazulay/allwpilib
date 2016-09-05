/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008-2016. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <memory>

#include "AnalogTriggerOutput.h"
#include "HAL/Types.h"
#include "SensorBase.h"

class AnalogInput;

class AnalogTrigger : public SensorBase {
  friend class AnalogTriggerOutput;

 public:
  explicit AnalogTrigger(int32_t channel);
  explicit AnalogTrigger(AnalogInput* channel);
  virtual ~AnalogTrigger();

  void SetLimitsVoltage(float lower, float upper);
  void SetLimitsRaw(int32_t lower, int32_t upper);
  void SetAveraged(bool useAveragedValue);
  void SetFiltered(bool useFilteredValue);
  int32_t GetIndex() const;
  bool GetInWindow();
  bool GetTriggerState();
  std::shared_ptr<AnalogTriggerOutput> CreateOutput(
      AnalogTriggerType type) const;

 private:
  uint8_t m_index;
  HAL_AnalogTriggerHandle m_trigger;
  AnalogInput* m_analogInput = nullptr;
  bool m_ownsAnalog = false;
};
