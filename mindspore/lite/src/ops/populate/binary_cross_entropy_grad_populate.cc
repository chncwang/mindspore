/**
 * Copyright 2019-2020 Huawei Technologies Co., Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "src/ops/binary_cross_entropy_grad.h"
#include "src/ops/primitive_c.h"
#include "src/ops/populate/populate_register.h"
#include "nnacl/fp32_grad/binary_cross_entropy_grad.h"

namespace mindspore {
namespace lite {
OpParameter *PopulateBinaryCrossEntropyGradParameter(const mindspore::lite::PrimitiveC *primitive) {
  BinaryCrossEntropyGradParameter *bce_param =
    reinterpret_cast<BinaryCrossEntropyGradParameter *>(malloc(sizeof(BinaryCrossEntropyGradParameter)));
  if (bce_param == nullptr) {
    MS_LOG(ERROR) << "malloc BinaryCrossEntropyGrad Parameter failed.";
    return nullptr;
  }
  memset(bce_param, 0, sizeof(BinaryCrossEntropyGradParameter));
  bce_param->op_parameter_.type_ = primitive->Type();
  auto param =
    reinterpret_cast<mindspore::lite::BinaryCrossEntropyGrad *>(const_cast<mindspore::lite::PrimitiveC *>(primitive));
  bce_param->reduction = param->GetReduction();
  return reinterpret_cast<OpParameter *>(bce_param);
}

Registry BinaryCrossEntropyGradParameterRegistry(schema::PrimitiveType_BinaryCrossEntropyGrad,
                                                 PopulateBinaryCrossEntropyGradParameter);
}  // namespace lite
}  // namespace mindspore
