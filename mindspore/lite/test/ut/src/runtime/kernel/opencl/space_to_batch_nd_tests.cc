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
#include "ut/src/runtime/kernel/opencl/common.h"
#include "nnacl/fp32/space_to_batch_fp32.h"

namespace mindspore::lite::opencl::test {

class TestOpenCL_SpaceToBatch : public CommonTest {};

namespace {
// PrimitiveType_SpaceToBatchND: src/ops/populate/space_to_batch_nd_populate.cc
OpParameter *CreateParameter(const std::vector<int> &block_sizes, const std::vector<int> &paddings) {
  auto *param = test::CreateParameter<SpaceToBatchParameter>(schema::PrimitiveType_SpaceToBatchND);
  EXPECT_LE(block_sizes.size(), 4);
  EXPECT_LE(paddings.size(), 4);
  for (int i = 0; i < block_sizes.size(); ++i) {
    param->block_sizes_[i] = block_sizes[i];
  }
  for (int i = 0; i < paddings.size(); ++i) {
    param->paddings_[i] = paddings[i];
  }
  return reinterpret_cast<OpParameter *>(param);
}

std::vector<int> InferShape(const std::vector<int> &input_shape, const std::vector<int> &block_sizes,
                            const std::vector<int> &paddings) {
  std::vector<int> output_shape = input_shape;
  output_shape[0] = input_shape[0] * block_sizes[0] * block_sizes[1];
  output_shape[1] = (input_shape[1] + paddings[0] + paddings[1]) / block_sizes[0];
  output_shape[2] = (input_shape[2] + +paddings[2] + paddings[3]) / block_sizes[1];
  return output_shape;
}
}  // namespace

TEST_F(TestOpenCL_SpaceToBatch, H2W2Pad2222) {
  std::vector<int> input_shape{1, 6, 6, 4};
  std::vector<int> block_sizes = {2, 2};
  std::vector<int> paddings = {2, 2, 2, 2};
  auto output_shape = InferShape(input_shape, block_sizes, paddings);
  float input_data[] = {172, 47,  117, 192, 67,  251, 195, 103, 9,   211, 21,  242, 36,  87,  70,  216, 88,  140,
                        58,  193, 230, 39,  87,  174, 88,  81,  165, 25,  77,  72,  9,   148, 115, 208, 243, 197,
                        254, 79,  175, 192, 82,  99,  216, 177, 243, 29,  147, 147, 142, 167, 32,  193, 9,   185,
                        127, 32,  31,  202, 244, 151, 163, 254, 203, 114, 183, 28,  34,  128, 128, 164, 53,  133,
                        38,  232, 244, 17,  79,  132, 105, 42,  186, 31,  120, 1,   65,  231, 169, 57,  35,  102,
                        119, 11,  174, 82,  91,  128, 142, 99,  53,  140, 121, 170, 84,  203, 68,  6,   196, 47,
                        127, 244, 131, 204, 100, 180, 232, 78,  143, 148, 227, 186, 23,  207, 141, 117, 85,  48,
                        49,  69,  169, 163, 192, 95,  197, 94,  0,   113, 178, 36,  162, 48,  93,  131, 98,  42};
  float output_data[] = {
    0,   0,   0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   172, 47, 117, 192, 9,   211, 21,  242, 88,  140, 58,  193, 0,   0,   0,   0,   0,   0,   0,   0,   142, 167,
    32,  193, 31, 202, 244, 151, 183, 28,  34,  128, 0,   0,   0,   0,   0,   0,   0,   0,   142, 99,  53,  140, 68,
    6,   196, 47, 100, 180, 232, 78,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,  0,   0,   0,   0,   0,   0,   67,  251, 195, 103, 36,  87,  70,  216, 230, 39,  87,  174, 0,   0,
    0,   0,   0,  0,   0,   0,   9,   185, 127, 32,  163, 254, 203, 114, 128, 164, 53,  133, 0,   0,   0,   0,   0,
    0,   0,   0,  121, 170, 84,  203, 127, 244, 131, 204, 143, 148, 227, 186, 0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   88,  81,  165, 25,  115, 208,
    243, 197, 82, 99,  216, 177, 0,   0,   0,   0,   0,   0,   0,   0,   38,  232, 244, 17,  186, 31,  120, 1,   35,
    102, 119, 11, 0,   0,   0,   0,   0,   0,   0,   0,   23,  207, 141, 117, 169, 163, 192, 95,  178, 36,  162, 48,
    0,   0,   0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   77, 72,  9,   148, 254, 79,  175, 192, 243, 29,  147, 147, 0,   0,   0,   0,   0,   0,   0,   0,   79,
    132, 105, 42, 65,  231, 169, 57,  174, 82,  91,  128, 0,   0,   0,   0,   0,   0,   0,   0,   85,  48,  49,  69,
    197, 94,  0,  113, 93,  131, 98,  42,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,  0,   0,   0,   0,   0,   0};

  for (auto fp16_enable : {false, true}) {
    auto *param = CreateParameter(block_sizes, paddings);
    TestMain({{input_shape, input_data, VAR}}, {output_shape, output_data}, param, fp16_enable);
  }
}
}  // namespace mindspore::lite::opencl::test
