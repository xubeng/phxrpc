/*
Tencent is pleased to support the open source community by making 
PhxRPC available.
Copyright (C) 2016 THL A29 Limited, a Tencent company. 
All rights reserved.

Licensed under the BSD 3-Clause License (the "License"); you may 
not use this file except in compliance with the License. You may 
obtain a copy of the License at

https://opensource.org/licenses/BSD-3-Clause

Unless required by applicable law or agreed to in writing, software 
distributed under the License is distributed on an "AS IS" basis, 
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or 
implied. See the License for the specific language governing 
permissions and limitations under the License.

See the AUTHORS file for names of contributors.
*/

#pragma once

#include <stdio.h>
#include <map>
#include <string>

namespace phxrpc {

class NameRender;
class SyntaxTree;
class SyntaxFunc;

class ServiceCodeRender {
 public:
    ServiceCodeRender(NameRender & name_render);
    virtual ~ServiceCodeRender();

    virtual void GenerateServiceHpp(SyntaxTree * stree, FILE * write);

    virtual void GenerateServiceCpp(SyntaxTree * stree, FILE * write);

    virtual void GenerateServiceImplHpp(SyntaxTree * stree, FILE * write);

    virtual void GenerateServiceImplCpp(SyntaxTree * stree, FILE * write);

    virtual void GenerateDispatcherHpp(SyntaxTree * stree, FILE * write);

    virtual void GenerateDispatcherCpp(SyntaxTree * stree, FILE * write);

 protected:

    virtual void GetServiceFuncDeclaration(SyntaxTree * stree, SyntaxFunc * func, int is_header, int is_impl,
                                           int need_param_name, std::string * result);

    virtual void GenerateDispatcherFunc(SyntaxTree * stree, SyntaxFunc * func, FILE * write);

    virtual void GenerateURIFuncMap(SyntaxTree * stree, FILE * write);

 protected:
    NameRender & name_render_;
};

}
