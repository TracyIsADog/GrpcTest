/*
 *
 * Copyright 2016, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef GRPC_CORE_LIB_CHANNEL_HANDSHAKER_FACTORY_H
#define GRPC_CORE_LIB_CHANNEL_HANDSHAKER_FACTORY_H

#include <grpc/impl/codegen/grpc_types.h>

#include "src/core/lib/channel/handshaker.h"
#include "src/core/lib/iomgr/exec_ctx.h"

// A handshaker factory is used to create handshakers.

typedef struct grpc_handshaker_factory grpc_handshaker_factory;

typedef struct {
  void (*add_handshakers)(grpc_exec_ctx *exec_ctx,
                          grpc_handshaker_factory *handshaker_factory,
                          const grpc_channel_args *args,
                          grpc_handshake_manager *handshake_mgr);
  void (*destroy)(grpc_exec_ctx *exec_ctx,
                  grpc_handshaker_factory *handshaker_factory);
} grpc_handshaker_factory_vtable;

struct grpc_handshaker_factory {
  const grpc_handshaker_factory_vtable *vtable;
};

void grpc_handshaker_factory_add_handshakers(
    grpc_exec_ctx *exec_ctx, grpc_handshaker_factory *handshaker_factory,
    const grpc_channel_args *args, grpc_handshake_manager *handshake_mgr);

void grpc_handshaker_factory_destroy(
    grpc_exec_ctx *exec_ctx, grpc_handshaker_factory *handshaker_factory);

#endif /* GRPC_CORE_LIB_CHANNEL_HANDSHAKER_FACTORY_H */
