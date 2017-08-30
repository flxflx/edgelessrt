#include <stdio.h>
#include <openenclave.h>
#include <__openenclave/utils.h>

void __OE_HexDump(
    const void* data_,
    size_t size)
{
    size_t i;
    const unsigned char* data = (const unsigned char*)data_;

    if (!data || !size)
        return;

    for (i = 0; i < size; i++)
    {
        printf("%02x", data[i]);

        if ((i + 1) % 16 == 0)
            printf("\n");
        else
            printf(" ");
    }

    printf("\n");
}