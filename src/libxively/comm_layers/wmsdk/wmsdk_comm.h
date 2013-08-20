// Copyright (c) 2003-2013, LogMeIn, Inc. All rights reserved.
// This is part of Xively C library, it is under the BSD 3-Clause license.

/**
 * \file 	wmsdk_comm.h
 * \author 	Olgierd Humenczuk
 * \brief   Implements WMSDK _communication layer_ functions [see comm_layer.h and wmsdk_comm.c]
 */

#ifndef __WMSDK_COMM_H__
#define __WMSDK_COMM_H__

#include "connection.h"

connection_t* wmsdk_open_connection( const char* address, int32_t port );

int wmsdk_send_data( connection_t* conn, const char* data, size_t size );

int wmsdk_read_data( connection_t* conn, char* buffer, size_t buffer_size );

void wmsdk_close_connection( connection_t* conn );

#endif // __WMSDK_COMM_H__
