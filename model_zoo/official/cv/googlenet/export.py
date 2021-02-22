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
##############export checkpoint file into air, onnx, mindir models#################
python export.py
"""
import argparse
import numpy as np

import mindspore as ms
from mindspore import Tensor, load_checkpoint, load_param_into_net, export, context

from src.config import cifar_cfg, imagenet_cfg
from src.googlenet import GoogleNet

parser = argparse.ArgumentParser(description='Classification')
parser.add_argument("--device_id", type=int, default=0, help="Device id")
parser.add_argument("--batch_size", type=int, default=1, help="batch size")
parser.add_argument("--ckpt_file", type=str, required=True, help="Checkpoint file path.")
parser.add_argument("--file_name", type=str, default="googlenet", help="output file name.")
parser.add_argument('--file_format', type=str, choices=["AIR", "ONNX", "MINDIR"], default='AIR', help='file format')
parser.add_argument("--device_target", type=str, choices=["Ascend", "GPU", "CPU"], default="Ascend",
                    help="device target")
parser.add_argument('--dataset_name', type=str, default='cifar10', choices=['imagenet', 'cifar10'],
                    help='dataset name.')
args = parser.parse_args()

context.set_context(mode=context.GRAPH_MODE, device_target=args.device_target)
if args.device_target == "Ascend":
    context.set_context(device_id=args.device_id)

if __name__ == '__main__':
    if args.dataset_name == 'cifar10':
        cfg = cifar_cfg
    elif args.dataset_name == 'imagenet':
        cfg = imagenet_cfg
    else:
        raise ValueError("dataset is not support.")

    net = GoogleNet(num_classes=cfg.num_classes)

    assert cfg.checkpoint_path is not None, "cfg.checkpoint_path is None."
    param_dict = load_checkpoint(args.ckpt_file)
    load_param_into_net(net, param_dict)

    input_arr = Tensor(np.ones([args.batch_size, 3, cfg.image_height, cfg.image_width]), ms.float32)
    export(net, input_arr, file_name=args.file_name, file_format=args.file_format)
