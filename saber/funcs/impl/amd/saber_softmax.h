/* Copyright (c) 2018 Advanced Micro Devices, Inc. All Rights Reserved.
 
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef ANAKIN_SABER_FUNCS_IMPL_AMD_SABER_SOFTMAX_H
#define ANAKIN_SABER_FUNCS_IMPL_AMD_SABER_SOFTMAX_H

#include <vector>
#include "saber/funcs/impl/impl_softmax.h"
#include "saber/funcs/funcs_utils.h"

namespace anakin{

namespace saber{


template <DataType OpDtype ,
        DataType inDtype,
        DataType outDtype,
        typename LayOutType_op,
        typename LayOutType_in,
        typename LayOutType_out>
class SaberSoftmax<AMD, OpDtype, inDtype, outDtype,
        LayOutType_op, LayOutType_in, LayOutType_out> :
        public ImplBase<
             Tensor<AMD, inDtype, LayOutType_in>,
             Tensor<AMD, outDtype, LayOutType_out>,
             Tensor<AMD, OpDtype, LayOutType_op>,
             SoftmaxParam<Tensor<AMD, OpDtype, LayOutType_op> > >

{
public:
    typedef Tensor<AMD, inDtype, LayOutType_in> DataTensor_in;
    typedef Tensor<AMD, outDtype, LayOutType_out> DataTensor_out;
    typedef Tensor<AMD, OpDtype, LayOutType_op> OpTensor;
    typedef AMD targetType_t;

    SaberSoftmax()
    {}

    ~SaberSoftmax() {}

    virtual SaberStatus init(const std::vector<DataTensor_in*>& inputs,
                             std::vector<DataTensor_out*>& outputs,
                             SoftmaxParam<OpTensor> &param,
                             Context<AMD> &ctx) override;

    virtual SaberStatus create(const std::vector<DataTensor_in*>& inputs,
                               std::vector<DataTensor_out*>& outputs,
                               SoftmaxParam<OpTensor> &param,
                               Context<AMD> &ctx) override;

    virtual SaberStatus dispatch(const std::vector<DataTensor_in*>& inputs,
                                 std::vector<DataTensor_out*>& outputs,
                                 SoftmaxParam<OpTensor> &param) override;
 
private:
    cl_kernel _kernel;
    size_t _globalWorkSize[3];
    size_t _localWorkSize[3];

};
template class SaberSoftmax<AMD, AK_FLOAT, AK_FLOAT, AK_FLOAT, NCHW, NCHW, NCHW>;
}

}


#endif //ANAKIN_SABER_FUNCS_IMPL_AMD_SABER_CONV_H
