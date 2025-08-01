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
#ifndef INCLUDE_NEXA_H_
#define INCLUDE_NEXA_H_


#include <sys/socket.h>
#include <netinet/in.h>


struct transport {
    struct sockaddr_storage addr;
};


struct listen_opts {
    const char *bind;
    int foo;
};


int
listen_main(struct listen_opts *opts);


#endif  // INCLUDE_NEXA_H_
