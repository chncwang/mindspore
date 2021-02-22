/**
 * Copyright 2020 Huawei Technologies Co., Ltd
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
#ifndef MINDSPORE_LITE_SRC_RUNTIME_KERNEL_ARM_FP16_ARITHMETIC_SELF_FP16_H_
#define MINDSPORE_LITE_SRC_RUNTIME_KERNEL_ARM_FP16_ARITHMETIC_SELF_FP16_H_

#include <vector>
#include "src/runtime/kernel/arm/fp32/arithmetic_self_fp32.h"

namespace mindspore::kernel {
typedef int (*ArithmeticSelfFp16Func)(float16_t *input, float16_t *output, int element_size);
class ArithmeticSelfFp16CPUKernel : public ArithmeticSelfCPUKernel {
 public:
  explicit ArithmeticSelfFp16CPUKernel(OpParameter *parameter, const std::vector<lite::Tensor *> &inputs,
                                       const std::vector<lite::Tensor *> &outputs, const lite::InnerContext *ctx,
                                       const mindspore::lite::PrimitiveC *primitive)
      : ArithmeticSelfCPUKernel(parameter, inputs, outputs, ctx, primitive) {
    fp16_func_ = GetArithmeticSelfFp16Fun(parameter->type_);
  }
  ~ArithmeticSelfFp16CPUKernel() override = default;

  int Run() override;
  int DoExecute(int task_id) override;

 private:
  ArithmeticSelfFp16Func GetArithmeticSelfFp16Fun(int primitive_type);
  ArithmeticSelfFp16Func fp16_func_ = nullptr;
  float16_t *input_fp16_ptr_ = nullptr;
  float16_t *output_fp16_ptr_ = nullptr;
};
}  // namespace mindspore::kernel

#endif  // MINDSPORE_LITE_SRC_RUNTIME_KERNEL_ARM_FP16_ARITHMETIC_SELF_FP16_H_
