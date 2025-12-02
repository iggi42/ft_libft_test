#include "theft.h"

#include "../include/ftt.h"
#include "theft_types.h"

#include <stdio.h>

static enum theft_trial_res encode_as_sprintf(struct theft *t, void *arg1) {
    (void) t;
    (void) arg1;

    // return THEFT_TRIAL_PASS, FAIL, SKIP, or ERROR
    return THEFT_TRIAL_PASS;
}

enum theft_alloc_res ftt_alloc_long(struct theft *t, void *env, void **output)
{
  *output = theft_random_bits_buk(t, bit_count, buffer);
  return THEFT_ALLOC_OK;
}

static struct theft_type_info random_buffer_info = {
    /* allocate a buffer based on random bitstream */
    .alloc = ftt_alloc_long
};
