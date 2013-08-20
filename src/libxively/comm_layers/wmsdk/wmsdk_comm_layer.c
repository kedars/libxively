// Copyright (c) 2003-2013, LogMeIn, Inc. All rights reserved.
// This is part of Xively C library, it is under the BSD 3-Clause license.
#include "comm_layer.h"
#include "wmsdk_comm.h"

/**
 * \file 	wmsdk_comm_layer.c
 * \author 	Olgierd Humenczuk
 * \brief   Implements WMSDK _communication layer_ functions [see comm_layer.h]
 */

 /**
  * \brief   Initialise mbed implementation of the _communication layer_
  */
const comm_layer_t* get_comm_layer()
{
    static comm_layer_t __wmsdk_comm_layer =
    {
          &wmsdk_open_connection
        , &wmsdk_send_data
        , &wmsdk_read_data
        , &wmsdk_close_connection
    };

    return &__wmsdk_comm_layer;
}
