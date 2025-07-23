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
#include <stdlib.h>

/* platform */

/* third party */
#include <clog.h>
#include <yacap.h>

/* local */
#include "include/nexa.h"
#include "cli/listen.h"
#include "config.h"


static int
_init(struct yacap_command *cmd) {
    struct listen_opts *opts = malloc(sizeof(struct listen_opts));
    if (opts == NULL) {
        return -1;
    }

    cmd->userptr = opts;
    return 0;
}


static enum yacap_eatstatus
_eat(const struct yacap_option *o, const char *v, struct listen_opts *opts) {
    printf("%s\n", v);
    // TODO: implement
    return YACAP_EAT_OK;
}


static int
_listen_main(const struct yacap *c, const struct yacap_command *cmd) {
    /* greeting */
    INFO("%s v%s -- listen", PROJECT_NAME, PROJECT_VERSION);

    return listen_main((struct listen_opts*)cmd->userptr);
}


struct yacap_command
cli_listen = {
    .init = (yacap_commandhook_t)_init,
    .eat = (yacap_eater_t)_eat,
    .name = "listen",
    .entrypoint = _listen_main,
};
