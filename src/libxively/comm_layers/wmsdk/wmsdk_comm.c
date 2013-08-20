// Copyright (c) 2003-2013, LogMeIn, Inc. All rights reserved.
// This is part of Xively C library, it is under the BSD 3-Clause license.

/**
 * \file    wmsdk_comm.c
 * \author  Olgierd Humenczuk
 * \brief   Implements POSIX _communication layer_ abstraction interface [see comm_layer.h]
 */
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

#include "wmsdk_comm.h"
#include "comm_layer.h"
#include "xi_helpers.h"
#include "xi_allocator.h"
#include "wmsdk_comm_layer_data_specific.h"
#include "xi_err.h"
#include "xi_macros.h"
#include "xi_globals.h"


connection_t* wmsdk_open_connection( const char* address, int32_t port )
{
    // PRECONDITIONS
    assert( address != 0 );

    // variables
    wmsdk_comm_layer_data_specific_t* wmsdk_comm_data = 0;
    connection_t* conn                              = 0;

    // allocate memory for the wmsdk data specific structure
    wmsdk_comm_data
        = ( wmsdk_comm_layer_data_specific_t* ) xi_alloc(
                sizeof( wmsdk_comm_layer_data_specific_t ) );

    XI_CHECK_MEMORY( wmsdk_comm_data );

    // allocate memory for the connection layer
    conn
        = ( connection_t* ) xi_alloc(
                sizeof( connection_t ) );

    XI_CHECK_MEMORY( conn );

    // make copy of an address
    conn->address = xi_str_dup( address );
    conn->port = port;

    XI_CHECK_MEMORY( conn->address );

    // remember the layer specific part
    conn->layer_specific = ( void* ) wmsdk_comm_data;

    // POSTCONDITIONS
    assert( conn != 0 );
    assert( wmsdk_comm_data->socket_fd != -1 );

    return conn;

err_handling:
    // cleanup the memory
    if( wmsdk_comm_data ) { XI_SAFE_FREE( wmsdk_comm_data ); }
    if( conn ) { XI_SAFE_FREE( conn->address ); }
    XI_SAFE_FREE( conn );

    return 0;
}

int wmsdk_send_data( connection_t* conn, const char* data, size_t size )
{
    // PRECONDITIONS
    assert( conn != 0 );
    assert( conn->layer_specific != 0 );
    assert( data != 0 );
    assert( size != 0 );

    // extract the layer specific data
    /*wmsdk_comm_layer_data_specific_t* wmsdk_comm_data
        = ( wmsdk_comm_layer_data_specific_t* ) conn->layer_specific;*/

    // store the value
    conn->bytes_sent += size;

    return size;
}

int wmsdk_read_data( connection_t* conn, char* buffer, size_t buffer_size )
{
    // PRECONDITIONS
    assert( conn != 0 );
    assert( conn->layer_specific != 0 );
    assert( buffer != 0 );
    assert( buffer_size != 0 );

    // extract the layer specific data
    /*wmsdk_comm_layer_data_specific_t* wmsdk_comm_data
        = ( wmsdk_comm_layer_data_specific_t* ) conn->layer_specific;*/

    memset( buffer, 0, buffer_size );

    // store the value
    conn->bytes_received += 0;

    return 0;
}

void wmsdk_close_connection( connection_t* conn )
{
    // PRECONDITIONS
    assert( conn != 0 );

    // extract the layer specific data
    /*wmsdk_comm_layer_data_specific_t* wmsdk_comm_data
        = ( wmsdk_comm_layer_data_specific_t* ) conn->layer_specific;*/

//err_handling:
    // cleanup the memory
    if( conn ) { XI_SAFE_FREE( conn->layer_specific ); }
    if( conn ) { XI_SAFE_FREE( conn->address ); }
    XI_SAFE_FREE( conn );

    return;
}
