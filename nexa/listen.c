// Copyright 2025 Vahid Mardani
/*
 * This file is part of nexamine.
 *  nexamine is free software: you can redistribute it and/or modify it under
 *  the terms of the GNU General Public License as published by the Free
 *  Software Foundation, either version 3 of the License, or (at your option)
 *  any later version.
 *
 *  nexamine is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 *  more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with nexamine. If not, see <https://www.gnu.org/licenses/>.
 *
 *  Author: Vahid Mardani <vahid.mardani@gmail.com>
 */
/* standard */
#include <string.h>

/* platform */
/* ... */

/* third party */
#include <caio/caio.h>

/* local */
#include "config.h"
#include "include/nexa.h"
#include "nexa/listen.h"


#undef CAIO_ARG1
#undef CAIO_ARG2
#undef CAIO_ENTITY
#define CAIO_ENTITY listen
#include "caio/generic.h"
#include "caio/generic.c"


static ASYNC
listenA(struct caio_task *self, struct listen_state *state) {
    CAIO_BEGIN(self);
    CAIO_FINALLY(self);
}


int
listen_main(struct listen_opts *opts) {
    int exitstatus = EXIT_SUCCESS;
    static struct listen_state *state;
    static struct caio *caio;

    /* allocate state */
    state = malloc(sizeof(struct listen_state));
    if (state == NULL) {
        exitstatus = EXIT_FAILURE;
        goto terminate;
    }

    /* initialize the state */
    memset(state, 0, sizeof(struct listen_state));
    state->opts = opts;

    /* create a caio instance */
    caio = caio_create(8);
    if (caio == NULL) {
        exitstatus = EXIT_FAILURE;
        goto terminate;
    }

    /* spawn the listen task */
    listen_spawn(caio, listenA, state);

    /* loop until signals */
    if (caio_loop(caio)) {
        exitstatus = EXIT_FAILURE;
    }

    /* cleanup the caio instance */
    if (caio_destroy(caio)) {
        exitstatus = EXIT_FAILURE;
    }

terminate:
    return exitstatus;
}
