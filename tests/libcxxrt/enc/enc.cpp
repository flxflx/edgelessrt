// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

/*
  Since most of the libcxxrt tests are tested based on the
  comparison between log file generated by the enclave with
  log generated by system, one can't add any debug prints
  to this file. If added, the tests will fail because of
  additional prints in enclave log, which won't be there in
  system generated log. For more details please refer
  Readme.md file
*/

#include <openenclave/enclave.h>
#include <openenclave/internal/calls.h>
#include <openenclave/internal/tests.h>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include "../host/args.h"
#include "../host/ocalls.h"

extern "C" int main(int argc, const char* argv[]);

extern "C" void _exit(int status)
{
    OE_OCall(OCALL_EXIT, status, NULL, 0);
    abort();
}

extern "C" void _Exit(int status)
{
    _exit(status);
    abort();
}

extern "C" void exit(int status)
{
    _exit(status);
    abort();
}

typedef void (*Handler)(int signal);

Handler signal(int signal, Handler)
{
    /* Ignore! */
    return NULL;
}

extern "C" int close(int fd)
{
    OE_TEST("close() panic" == NULL);
    return 0;
}

OE_ECALL void Test(Args* args)
{
    extern const char* __TEST__NAME;
    if (args)
    {
        static const char* argv[] = {
            "test", NULL,
        };
        static int argc = sizeof(argv) / sizeof(argv[0]);
        args->ret = main(argc, argv);
        args->test = OE_HostStrdup(__TEST__NAME);
    }
}
