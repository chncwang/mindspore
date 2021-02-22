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

#include "backend/kernel_compiler/gpu/cuda_impl/scatter_update_impl.cuh"

template <typename T>
__global__ void ScatterUpdate(const size_t inner_size, const size_t updates_size, const int *indices, const T *updates,
                              T *input) {
  for (size_t pos = blockIdx.x * blockDim.x + threadIdx.x; pos < updates_size; pos += blockDim.x * gridDim.x) {
    const size_t index = pos / inner_size;
    const size_t offset = pos % inner_size;
    const size_t current_pos = indices[index] * inner_size + offset;
    input[current_pos] = updates[pos];
  }
}

template <typename T>
void CalScatterUpdate(const size_t &inner_size, const size_t &indices_size, const int *indices, const T *updates,
                      T *input, cudaStream_t cuda_stream) {
  const size_t updates_size = inner_size * indices_size;
  ScatterUpdate<<<GET_BLOCKS(updates_size), GET_THREADS, 0, cuda_stream>>>(inner_size, updates_size, indices, updates,
                                                                           input);
}

template void CalScatterUpdate<float>(const size_t &inner_size, const size_t &indices_size, const int *indices,
                                      const float *updates, float *input, cudaStream_t cuda_stream);
template void CalScatterUpdate<half>(const size_t &inner_size, const size_t &indices_size, const int *indices,
                                     const half *updates, half *input, cudaStream_t cuda_stream);
template void CalScatterUpdate<int>(const size_t &inner_size, const size_t &indices_size, const int *indices,
                                    const int *updates, int *input, cudaStream_t cuda_stream);
template void CalScatterUpdate<unsigned char>(const size_t &inner_size, const size_t &indices_size, const int *indices,
                                              const unsigned char *updates, unsigned char *input,
                                              cudaStream_t cuda_stream);
template void CalScatterUpdate<int8_t>(const size_t &inner_size, const size_t &indices_size, const int *indices,
                                       const int8_t *updates, int8_t *input, cudaStream_t cuda_stream);
