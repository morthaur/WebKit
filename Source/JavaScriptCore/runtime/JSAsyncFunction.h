/*
 * Copyright (C) 2016 Caitlin Potter <caitp@igalia.com>.
 * Copyright (C) 2018 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include "JSFunction.h"

namespace JSC {

class JSAsyncFunction final : public JSFunction {
    friend class JIT;
    friend class VM;
public:
    typedef JSFunction Base;

    static constexpr unsigned StructureFlags = Base::StructureFlags;

    DECLARE_EXPORT_INFO;

    static JSAsyncFunction* create(VM&, JSGlobalObject*, FunctionExecutable*, JSScope*);
    static JSAsyncFunction* create(VM&, JSGlobalObject*, FunctionExecutable*, JSScope*, Structure*);
    static JSAsyncFunction* createWithInvalidatedReallocationWatchpoint(VM&, JSGlobalObject*, FunctionExecutable*, JSScope*);
    static JSAsyncFunction* createWithInvalidatedReallocationWatchpoint(VM&, JSGlobalObject*, FunctionExecutable*, JSScope*, Structure*);

    static size_t allocationSize(Checked<size_t> inlineCapacity)
    {
        ASSERT_UNUSED(inlineCapacity, !inlineCapacity);
        return sizeof(JSAsyncFunction);
    }

    inline static Structure* createStructure(VM&, JSGlobalObject*, JSValue);

private:
    JSAsyncFunction(VM&, FunctionExecutable*, JSScope*, Structure*);

    static JSAsyncFunction* createImpl(VM&, FunctionExecutable*, JSScope*, Structure*);
};
static_assert(sizeof(JSAsyncFunction) == sizeof(JSFunction), "Some subclasses of JSFunction should be the same size to share IsoSubspace");

} // namespace JSC
