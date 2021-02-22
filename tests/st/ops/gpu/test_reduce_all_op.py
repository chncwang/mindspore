# Copyright 2020 Huawei Technologies Co., Ltd
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ============================================================================

import numpy as np
import pytest

import mindspore.context as context
import mindspore.nn as nn
from mindspore import Tensor
from mindspore.common.api import ms_function
from mindspore.ops import operations as P
from mindspore.ops.operations import _inner_ops as inner

x0 = np.array([[True, True], [True, False], [False, False]])
axis0 = 0
keep_dims0 = True

x1 = np.array([[True, True], [True, False], [False, False]])
axis1 = 0
keep_dims1 = False

x2 = np.array([[True, True], [True, False], [False, False]])
axis2 = 1
keep_dims2 = True

x3 = np.array([[True, True], [True, False], [False, False]])
axis3 = 1
keep_dims3 = False

context.set_context(device_target='GPU')


class ReduceAll(nn.Cell):
    def __init__(self):
        super(ReduceAll, self).__init__()

        self.x0 = Tensor(x0)
        self.axis0 = axis0
        self.keep_dims0 = keep_dims0

        self.x1 = Tensor(x1)
        self.axis1 = axis1
        self.keep_dims1 = keep_dims1

        self.x2 = Tensor(x2)
        self.axis2 = axis2
        self.keep_dims2 = keep_dims2

        self.x3 = Tensor(x3)
        self.axis3 = axis3
        self.keep_dims3 = keep_dims3


    @ms_function
    def construct(self):
        return (P.ReduceAll(self.keep_dims0)(self.x0, self.axis0),
                P.ReduceAll(self.keep_dims1)(self.x1, self.axis1),
                P.ReduceAll(self.keep_dims2)(self.x2, self.axis2),
                P.ReduceAll(self.keep_dims3)(self.x3, self.axis3))


@pytest.mark.level0
@pytest.mark.platform_x86_gpu_training
@pytest.mark.env_onecard
def test_ReduceAll():
    reduce_all = ReduceAll()
    output = reduce_all()

    expect0 = np.all(x0, axis=axis0, keepdims=keep_dims0)
    assert np.allclose(output[0].asnumpy(), expect0)
    assert output[0].shape == expect0.shape

    expect1 = np.all(x1, axis=axis1, keepdims=keep_dims1)
    assert np.allclose(output[1].asnumpy(), expect1)
    assert output[1].shape == expect1.shape

    expect2 = np.all(x2, axis=axis2, keepdims=keep_dims2)
    assert np.allclose(output[2].asnumpy(), expect2)
    assert output[2].shape == expect2.shape

    expect3 = np.all(x3, axis=axis3, keepdims=keep_dims3)
    assert np.allclose(output[3].asnumpy(), expect3)
    assert output[3].shape == expect3.shape


class ReduceAllDynamic(nn.Cell):
    def __init__(self):
        super(ReduceAllDynamic, self).__init__()
        self.reduceall = P.ReduceAll(False)
        self.test_dynamic = inner.GpuConvertToDynamicShape()

    def construct(self, x, axis):
        x = self.test_dynamic(x)
        return self.reduceall(x, axis)


@pytest.mark.level0
@pytest.mark.platform_x86_gpu_training
@pytest.mark.env_onecard
def test_reduce_all_dynamic():
    context.set_context(mode=context.GRAPH_MODE, device_target="GPU")
    net = ReduceAllDynamic()

    x_1 = np.array([[True, True], [True, False], [False, False]])
    axis_1 = 0
    expect_1 = np.all(x_1, axis=axis_1, keepdims=False)

    x_2 = np.array([[True, True], [True, True], [True, False], [False, False]])
    axis_2 = 0
    expect_2 = np.all(x_2, axis=axis_2, keepdims=False)

    output_1 = net(Tensor(x_1), axis_1)
    output_2 = net(Tensor(x_2), axis_2)

    np.testing.assert_almost_equal(output_1.asnumpy(), expect_1)
    np.testing.assert_almost_equal(output_2.asnumpy(), expect_2)
