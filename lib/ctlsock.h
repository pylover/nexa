// Copyright 2025 Vahid Mardani
/*
 * This file is part of nexamineo.
 *  nexamineo is free software: you can redistribute it and/or modify it under
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
#ifndef LIB_CTLSOCK_H_
#define LIB_CTLSOCK_H_


// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <arpa/inet.h>


struct ctlsock {
};


struct ctlsock *
ctlsock_connect(struct in_addr dst);


#endif  // LIB_CTLSOCK_H_
