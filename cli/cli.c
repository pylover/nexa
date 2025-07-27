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
#include <stdio.h>
#include <stdlib.h>

/* platform */
/* ... */

/* third party */
#include <clog.h>
#include <yacap.h>
#include <caio/caio.h>

/* local */
#include "include/nexa.h"
#include "cli/listen.h"
#include "config.h"
#include "cli.h"


static int
_main(const struct yacap *c, const struct yacap_command *cmd) {
    yacap_help_print(c);
    // yacap_commandchain_print(STDERR_FILENO, c);
    // dprintf(STDERR_FILENO, ": Invalid command\n");
    // yacap_try_help(c);
    return 0;
}


static struct yacap
_cli = {
    .commands = (struct yacap_command *const[]) {
        &cli_listen,
        NULL
    },
    .entrypoint = _main,
};


int
cli_main(int argc, const char **argv) {
    int ret = EXIT_FAILURE;
    const struct yacap_command *cmd;
    enum yacap_status status = yacap_parse(&_cli, argc, argv, &cmd);

    if (status == YACAP_OK_EXIT) {
        ret = EXIT_SUCCESS;
        goto terminate;
    }

    if ((status == YACAP_OK) && cmd) {
        if (cmd->entrypoint == NULL) {
            goto terminate;
        }
        ret = cmd->entrypoint(&_cli, cmd);
    }

terminate:
    yacap_dispose(&_cli);
    return ret;
}
