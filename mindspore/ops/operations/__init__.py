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

"""
Primitive operator classes.

A collection of operators to build nerual networks or computing functions.
"""

from .image_ops import (CropAndResize)
from .array_ops import (Argmax, Argmin, Cast, Concat, Pack, Unpack,
                        Diag, DiagPart, DType, ExpandDims, Eye,
                        Fill, GatherNd, GatherV2, SparseGatherV2, InvertPermutation,
                        IsInstance, IsSubClass, ArgMaxWithValue, OnesLike, ZerosLike,
                        Rank, Reshape, ResizeNearestNeighbor, ArgMinWithValue,
                        SameTypeShape, ScatterAdd, ScatterMax, ScatterUpdate,
                        ScalarToArray, ScalarToTensor, ScatterNd, ScatterNdUpdate, Select,
                        Shape, Size, Slice, Split, EmbeddingLookup,
                        Squeeze, StridedSlice, Tile, TensorScatterUpdate,
                        Transpose, TruncatedNormal, TupleToArray, UnsortedSegmentMin,
                        UnsortedSegmentSum, SpaceToDepth, DepthToSpace, SpaceToBatch, BatchToSpace,
                        SpaceToBatchND, BatchToSpaceND, BroadcastTo, InplaceUpdate, ReverseSequence)
from .comm_ops import (AllGather, AllReduce, _AlltoAll, ReduceScatter, Broadcast,
                       _MirrorOperator, ReduceOp, _VirtualDataset,
                       _VirtualDiv, _GetTensorSlice,
                       HostAllGather, HostReduceScatter)
from .debug_ops import (ImageSummary, InsertGradientOf, HookBackward, ScalarSummary,
                        TensorSummary, HistogramSummary, Print)
from .control_ops import ControlDepend, GeSwitch, Merge
from .inner_ops import ScalarCast

from .math_ops import (Abs, ACos, Asin, Asinh, AddN, AccumulateNV2, AssignAdd, AssignSub, Atan2, BatchMatMul, BitwiseAnd, BitwiseOr,
                       BitwiseXor, Inv, Invert, ApproximateEqual, InplaceAdd, InplaceSub,
                       ReduceMax, ReduceMin, ReduceMean, ReduceSum, ReduceAll, ReduceProd, CumProd,
                       Cos, Div, DivNoNan, Equal, EqualCount, Exp, Expm1, Erf, Erfc, Floor, FloorDiv, FloorMod, Ceil,
                       Acosh, Greater, GreaterEqual, Less, LessEqual, Log, Log1p, LogicalAnd,
                       LogicalNot, LogicalOr, MatMul, Maximum,
                       Minimum, Mul, Neg, NMSWithMask, NotEqual,
                       NPUAllocFloatStatus, NPUClearFloatStatus,
                       NPUGetFloatStatus, Pow, RealDiv, IsNan, IsInf, IsFinite, FloatStatus,
                       Reciprocal, CumSum, HistogramFixedWidth,
                       Sin, Sqrt, Rsqrt, BesselI0e, BesselI1e,
                       Square, Sub, TensorAdd, Sign, Round, SquareSumAll, Atan, Atanh, Cosh, Sinh, Eps)

from .random_ops import (RandomChoiceWithMask, Normal, RandomCategorical)
from .nn_ops import (LSTM, SGD, Adam, SparseApplyAdam, SparseApplyLazyAdam, ApplyMomentum, BatchNorm,
                     BiasAdd, Conv2D,
                     DepthwiseConv2dNative,
                     DropoutDoMask, DropoutGrad, Dropout,
                     DropoutGenMask, Flatten, FusedBatchNorm, BNTrainingReduce, BNTrainingUpdate,
                     Gelu, Elu,
                     GetNext, L2Normalize, LayerNorm, L2Loss, CTCLoss,
                     LogSoftmax,
                     MaxPool, DataFormatDimMap,
                     AvgPool, Conv2DBackpropInput, ConfusionMulGrad,
                     MaxPoolWithArgmax, OneHot, Pad, MirrorPad, PReLU, ReLU, ReLU6, ReLUV2, HSwish, HSigmoid,
                     ResizeBilinear, Sigmoid,
                     SigmoidCrossEntropyWithLogits,
                     SmoothL1Loss, Softmax, Softplus,
                     RNNTLoss,
                     SoftmaxCrossEntropyWithLogits, ROIAlign,
                     SparseSoftmaxCrossEntropyWithLogits, Tanh,
                     TopK, BinaryCrossEntropy, SparseApplyAdagrad, LARSUpdate, ApplyFtrl, SparseApplyFtrl,
                     ApplyProximalAdagrad, SparseApplyProximalAdagrad,
                     ApplyAdaMax, ApplyAdadelta, ApplyAdagrad, ApplyAdagradV2,
                     ApplyRMSProp, ApplyCenteredRMSProp, BasicLSTMCell, InTopK)
from .other_ops import (Assign, IOU, BoundingBoxDecode, BoundingBoxEncode,
                        CheckValid, MakeRefKey, Partial, Depend, CheckBprop)
from . import _quant_ops
from ._quant_ops import *
from .thor_ops import *

__all__ = [
    'ReverseSequence',
    'CropAndResize',
    'TensorAdd',
    'Argmax',
    'Argmin',
    'ArgMaxWithValue',
    'ArgMinWithValue',
    'AddN',
    'AccumulateNV2',
    'Sub',
    'CumSum',
    'MatMul',
    'BatchMatMul',
    'Mul',
    'Pow',
    'Exp',
    'Expm1',
    'Rsqrt',
    'Sqrt',
    'Square',
    'Conv2D',
    'Flatten',
    'MaxPoolWithArgmax',
    'FusedBatchNorm',
    'BNTrainingReduce',
    'BNTrainingUpdate',
    'BatchNorm',
    'MaxPool',
    'TopK',
    'Adam',
    'SparseApplyAdam',
    'SparseApplyLazyAdam',
    'Softplus',
    'Softmax',
    'LogSoftmax',
    'SoftmaxCrossEntropyWithLogits',
    'ROIAlign',
    'ConfusionMulGrad',
    'SparseSoftmaxCrossEntropyWithLogits',
    'SGD',
    'ApplyMomentum',
    'ExpandDims',
    'Cast',
    'IsSubClass',
    'IsInstance',
    'Reshape',
    'Squeeze',
    'Transpose',
    'OneHot',
    'GatherV2',
    'SparseGatherV2',
    'EmbeddingLookup',
    'Concat',
    'Pack',
    'Unpack',
    'Tile',
    'BiasAdd',
    'Gelu',
    'Minimum',
    'Maximum',
    'StridedSlice',
    'ReduceSum',
    'ReduceMean',
    'LayerNorm',
    'Rank',
    'Less',
    'LessEqual',
    'RealDiv',
    'Div',
    'DivNoNan',
    'Inv',
    'Invert',
    'TruncatedNormal',
    'Fill',
    'OnesLike',
    'ZerosLike',
    'Select',
    'Split',
    'ReLU',
    'ReLU6',
    'Elu',
    'Erf',
    'Erfc',
    'Sigmoid',
    'HSwish',
    'HSigmoid',
    'Tanh',
    'RandomChoiceWithMask',
    'Normal',
    'RandomCategorical',
    'ResizeBilinear',
    'ScalarSummary',
    'ImageSummary',
    'TensorSummary',
    'HistogramSummary',
    "Print",
    'InsertGradientOf',
    'HookBackward',
    'InvertPermutation',
    'Shape',
    'DropoutDoMask',
    'DropoutGenMask',
    'DropoutGrad',
    'Dropout',
    'Neg',
    'InplaceAdd',
    'InplaceSub',
    'Slice',
    'DType',
    'NPUAllocFloatStatus',
    'NPUGetFloatStatus',
    'NPUClearFloatStatus',
    'IsNan',
    'IsFinite',
    'IsInf',
    'FloatStatus',
    'Reciprocal',
    'SmoothL1Loss',
    'L2Loss',
    'CTCLoss',
    'RNNTLoss',
    'ReduceAll',
    'ScalarToArray',
    'ScalarToTensor',
    'TupleToArray',
    'ControlDepend',
    'GeSwitch',
    'Merge',
    'SameTypeShape',
    'CheckBprop',
    'CheckValid',
    'BoundingBoxEncode',
    'BoundingBoxDecode',
    'L2Normalize',
    'ScatterAdd',
    'ScatterNd',
    'ScatterMax',
    'ResizeNearestNeighbor',
    'HistogramFixedWidth',
    'Pad',
    'MirrorPad',
    'GatherNd',
    'TensorScatterUpdate',
    'ScatterUpdate',
    'ScatterNdUpdate',
    'Floor',
    'NMSWithMask',
    'IOU',
    'MakeRefKey',
    'Partial',
    'Depend',
    'AvgPool',
    # Back Primitive
    'Equal',
    'EqualCount',
    'NotEqual',
    'Greater',
    'GreaterEqual',
    'LogicalNot',
    'LogicalAnd',
    'LogicalOr',
    'Size',
    'DepthwiseConv2dNative',
    'UnsortedSegmentSum',
    'UnsortedSegmentMin',
    "AllGather",
    "HostAllGather",
    "AllReduce",
    "ReduceScatter",
    "HostReduceScatter",
    "Broadcast",
    "ReduceOp",
    'ScalarCast',
    'GetNext',
    'ReduceMax',
    'ReduceMin',
    'ReduceProd',
    'CumProd',
    'Log',
    'Log1p',
    'SigmoidCrossEntropyWithLogits',
    'FloorDiv',
    'FloorMod',
    'Ceil',
    'Acosh',
    'Asinh',
    "PReLU",
    "Cos",
    "Cosh",
    "ACos",
    "Diag",
    "DiagPart",
    'Eye',
    'Assign',
    'AssignAdd',
    'AssignSub',
    "Sin",
    "Sinh",
    "Asin",
    "LSTM",
    "Abs",
    "BinaryCrossEntropy",
    "SparseApplyAdagrad",
    "SpaceToDepth",
    "DepthToSpace",
    "Conv2DBackpropInput",
    "Sign",
    "LARSUpdate",
    "Round",
    "Eps",
    "ApplyFtrl",
    "SpaceToBatch",
    "SparseApplyFtrl",
    "ApplyProximalAdagrad",
    "SparseApplyProximalAdagrad",
    "ApplyAdaMax",
    "ApplyAdadelta",
    "ApplyAdagrad",
    "ApplyAdagradV2",
    "BatchToSpace",
    "Atan2",
    "ApplyRMSProp",
    "ApplyCenteredRMSProp",
    "SpaceToBatchND",
    "BatchToSpaceND",
    "ReverseSequence",
    "SquareSumAll",
    "BitwiseAnd",
    "BitwiseOr",
    "BitwiseXor",
    "BesselI0e",
    "BesselI1e",
    "Atan",
    "Atanh",
    "BasicLSTMCell",
    "BroadcastTo",
    "DataFormatDimMap",
    "ApproximateEqual",
    "InplaceUpdate",
    "InTopK",
    "CropAndResize"
]

__all__.sort()
