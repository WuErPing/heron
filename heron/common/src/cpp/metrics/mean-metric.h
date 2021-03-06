/*
 * Copyright 2015 Twitter, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//////////////////////////////////////////////////////////////////////////////
//
// mean-metric.h
//
// Duplication of MeanReducer.java
//////////////////////////////////////////////////////////////////////////////
#ifndef __MEAN_METRIC_H_
#define __MEAN_METRIC_H_

#include "metrics/imetric.h"
#include "proto/messages.h"
#include "basics/basics.h"

namespace heron {
namespace common {

class MeanMetric : public IMetric {
 public:
  MeanMetric();
  virtual ~MeanMetric();
  void record(sp_double64 _value);
  virtual void GetAndReset(const sp_string& _prefix,
                           proto::system::MetricPublisherPublishMessage* _message);

 private:
  sp_double64 numerator_;
  sp_int64 denominator_;
};
}  // namespace common
}  // namespace heron

#endif
