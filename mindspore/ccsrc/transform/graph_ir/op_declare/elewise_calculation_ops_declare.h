/**
 * Copyright 2019 Huawei Technologies Co., Ltd
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

#ifndef MINDSPORE_CCSRC_TRANSFORM_GRAPH_IR_OP_DECLARE_ELEWISE_CALCULATION_OPS_DECLARE_H_
#define MINDSPORE_CCSRC_TRANSFORM_GRAPH_IR_OP_DECLARE_ELEWISE_CALCULATION_OPS_DECLARE_H_

#include <string>
#include <unordered_map>
#include "transform/graph_ir/op_declare/op_declare_macro.h"
#include "ops/elewise_calculation_ops.h"

namespace mindspore::transform {
DECLARE_OP_ADAPTER(GreaterEqual)
DECLARE_OP_USE_OUTPUT(GreaterEqual)

DECLARE_OP_ADAPTER(AssignAdd)
DECLARE_OP_USE_OUTPUT(AssignAdd)

DECLARE_OP_ADAPTER(AssignSub)
DECLARE_OP_USE_OUTPUT(AssignSub)

DECLARE_OP_ADAPTER(ZerosLike)
DECLARE_OP_USE_OUTPUT(ZerosLike)

DECLARE_OP_ADAPTER(OnesLike)
DECLARE_OP_USE_OUTPUT(OnesLike)

DECLARE_OP_ADAPTER(ArgMaxD)
DECLARE_OP_USE_OUTPUT(ArgMaxD)

DECLARE_OP_ADAPTER(ArgMinD)
DECLARE_OP_USE_OUTPUT(ArgMinD)

DECLARE_OP_ADAPTER(ArgMaxWithValue)
DECLARE_OP_USE_OUTPUT(ArgMaxWithValue)

DECLARE_OP_ADAPTER(ArgMinWithValue)
DECLARE_OP_USE_OUTPUT(ArgMinWithValue)

DECLARE_OP_ADAPTER(Mul)
DECLARE_OP_USE_OUTPUT(Mul)

DECLARE_OP_ADAPTER(AddN)
DECLARE_OP_USE_DYN_INPUT(AddN)
DECLARE_OP_USE_OUTPUT(AddN)

DECLARE_OP_ADAPTER(Less)
DECLARE_OP_USE_OUTPUT(Less)

DECLARE_OP_ADAPTER(Rsqrt)
DECLARE_OP_USE_OUTPUT(Rsqrt)

DECLARE_OP_ADAPTER(Sqrt)
DECLARE_OP_USE_OUTPUT(Sqrt)

DECLARE_OP_ADAPTER(Square)
DECLARE_OP_USE_OUTPUT(Square)

DECLARE_OP_ADAPTER(SquareSumAll)
DECLARE_OP_USE_OUTPUT(SquareSumAll)

DECLARE_OP_ADAPTER(Maximum)
DECLARE_OP_USE_OUTPUT(Maximum)

DECLARE_OP_ADAPTER(Minimum)
DECLARE_OP_USE_OUTPUT(Minimum)

DECLARE_OP_ADAPTER(MaximumGrad)
DECLARE_OP_USE_OUTPUT(MaximumGrad)

DECLARE_OP_ADAPTER(MinimumGrad)
DECLARE_OP_USE_OUTPUT(MinimumGrad)

DECLARE_OP_ADAPTER(RealDiv)
DECLARE_OP_USE_OUTPUT(RealDiv)

DECLARE_OP_ADAPTER(BitwiseAnd)
DECLARE_OP_USE_OUTPUT(BitwiseAnd)

DECLARE_OP_ADAPTER(BitwiseOr)
DECLARE_OP_USE_OUTPUT(BitwiseOr)

DECLARE_OP_ADAPTER(BitwiseXor)
DECLARE_OP_USE_OUTPUT(BitwiseXor)

DECLARE_OP_ADAPTER(Ceil)
DECLARE_OP_USE_OUTPUT(Ceil)

DECLARE_OP_ADAPTER(CosineEmbeddingLoss)
DECLARE_OP_USE_OUTPUT(CosineEmbeddingLoss)

DECLARE_OP_ADAPTER(Xdivy)
DECLARE_OP_USE_OUTPUT(Xdivy)

DECLARE_OP_ADAPTER(Cast)
DECLARE_OP_USE_INPUT_ATTR(Cast)
DECLARE_OP_USE_OUTPUT(Cast)

DECLARE_OP_ADAPTER(Reciprocal)
DECLARE_OP_USE_OUTPUT(Reciprocal)

DECLARE_OP_ADAPTER(Neg)
DECLARE_OP_USE_OUTPUT(Neg)

DECLARE_OP_ADAPTER(Sub)
DECLARE_OP_USE_OUTPUT(Sub)

DECLARE_OP_ADAPTER(Pow)
DECLARE_OP_USE_OUTPUT(Pow)

DECLARE_OP_ADAPTER(Equal)
DECLARE_OP_USE_OUTPUT(Equal)

DECLARE_OP_ADAPTER(ApproximateEqual)
DECLARE_OP_USE_OUTPUT(ApproximateEqual)

DECLARE_OP_ADAPTER(NotEqual)
DECLARE_OP_USE_OUTPUT(NotEqual)

DECLARE_OP_ADAPTER(Log)
DECLARE_OP_USE_OUTPUT(Log)

DECLARE_OP_ADAPTER(LogicalAnd)
DECLARE_OP_USE_OUTPUT(LogicalAnd)

DECLARE_OP_ADAPTER(LogicalOr)
DECLARE_OP_USE_OUTPUT(LogicalOr)

DECLARE_OP_ADAPTER(LogicalNot)
DECLARE_OP_USE_OUTPUT(LogicalNot)

DECLARE_OP_ADAPTER(LessEqual)
DECLARE_OP_USE_OUTPUT(LessEqual)

DECLARE_OP_ADAPTER(Assign)
DECLARE_OP_USE_OUTPUT(Assign)

DECLARE_OP_ADAPTER(Add)
DECLARE_OP_USE_OUTPUT(Add)

DECLARE_OP_ADAPTER(Cos)
DECLARE_OP_USE_OUTPUT(Cos)

DECLARE_OP_ADAPTER(Cosh)
DECLARE_OP_USE_OUTPUT(Cosh)

DECLARE_OP_ADAPTER(Acos)
DECLARE_OP_USE_OUTPUT(Acos)

DECLARE_OP_ADAPTER(AcosGrad)
DECLARE_OP_USE_OUTPUT(AcosGrad)

DECLARE_OP_ADAPTER(Acosh)
DECLARE_OP_USE_OUTPUT(Acosh)

DECLARE_OP_ADAPTER(AcoshGrad)
DECLARE_OP_USE_OUTPUT(AcoshGrad)

DECLARE_OP_ADAPTER(Div)
DECLARE_OP_USE_OUTPUT(Div)

DECLARE_OP_ADAPTER(Floor)
DECLARE_OP_USE_OUTPUT(Floor)

DECLARE_OP_ADAPTER(FloorDiv)
DECLARE_OP_USE_OUTPUT(FloorDiv)

DECLARE_OP_ADAPTER(FloorMod)
DECLARE_OP_USE_OUTPUT(FloorMod)

DECLARE_OP_ADAPTER(Sin)
DECLARE_OP_USE_OUTPUT(Sin)

DECLARE_OP_ADAPTER(Sinh)
DECLARE_OP_USE_OUTPUT(Sinh)

DECLARE_OP_ADAPTER(Asin)
DECLARE_OP_USE_OUTPUT(Asin)

DECLARE_OP_ADAPTER(AsinGrad)
DECLARE_OP_USE_OUTPUT(AsinGrad)

DECLARE_OP_ADAPTER(Asinh)
DECLARE_OP_USE_OUTPUT(Asinh)

DECLARE_OP_ADAPTER(AsinhGrad)
DECLARE_OP_USE_OUTPUT(AsinhGrad)

DECLARE_OP_ADAPTER(Exp)
DECLARE_OP_USE_OUTPUT(Exp)

DECLARE_OP_ADAPTER(BiasAdd)
DECLARE_OP_USE_OUTPUT(BiasAdd)

DECLARE_OP_ADAPTER(Greater)
DECLARE_OP_USE_OUTPUT(Greater)

DECLARE_OP_ADAPTER(SqrtGrad)
DECLARE_OP_USE_OUTPUT(SqrtGrad)

DECLARE_OP_ADAPTER(ReciprocalGrad)
DECLARE_OP_USE_OUTPUT(ReciprocalGrad)

DECLARE_OP_ADAPTER(RsqrtGrad)
DECLARE_OP_USE_OUTPUT(RsqrtGrad)

DECLARE_OP_ADAPTER(Abs)
DECLARE_OP_USE_OUTPUT(Abs)

DECLARE_OP_ADAPTER(AbsGrad)
DECLARE_OP_USE_OUTPUT(AbsGrad)

DECLARE_OP_ADAPTER(Sign)
DECLARE_OP_USE_OUTPUT(Sign)

DECLARE_OP_ADAPTER(Round)
DECLARE_OP_USE_OUTPUT(Round)

DECLARE_OP_ADAPTER(Tan)
DECLARE_OP_USE_OUTPUT(Tan)

DECLARE_OP_ADAPTER(Atan)
DECLARE_OP_USE_OUTPUT(Atan)

DECLARE_OP_ADAPTER(AtanGrad)
DECLARE_OP_USE_OUTPUT(AtanGrad)

DECLARE_OP_ADAPTER(Atanh)
DECLARE_OP_USE_OUTPUT(Atanh)

DECLARE_OP_ADAPTER(Atan2)
DECLARE_OP_USE_OUTPUT(Atan2)

DECLARE_OP_ADAPTER(LambApplyOptimizerAssign)
DECLARE_OP_USE_OUTPUT(LambApplyOptimizerAssign)

DECLARE_OP_ADAPTER(LambApplyWeightAssign)
DECLARE_OP_USE_OUTPUT(LambApplyWeightAssign)
}  // namespace mindspore::transform
#endif  // MINDSPORE_CCSRC_TRANSFORM_GRAPH_IR_OP_DECLARE_ELEWISE_CALCULATION_OPS_DECLARE_H_
