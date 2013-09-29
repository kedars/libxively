#ifndef __HTTP_LAYER_H__
#define __HTTP_LAYER_H__

// local
#include "layer.h"

/**
 * \file   http_layer.h
 * \author Olgierd Humenczuk
 * \brief  File that containes the declaration of the http layer functions
 */

/**
 * \brief   see the layer_interface for details
 */
layer_state_t http_layer_on_demand(
      layer_connectivity_t* context
    , char* buffer
    , size_t size );

/**
 * \brief  see the layer_interface for details
 */
layer_state_t http_layer_on_data_ready(
      layer_connectivity_t* context
    , const char* buffer
    , size_t size );

/**
 * \brief  see the layer_interface for details
 */
layer_state_t http_layer_close(
    layer_connectivity_t* context );

/**
 * \brief  see the layer_interface for details
 */
layer_state_t http_layer_on_close(
    layer_connectivity_t* context );


/**
 * \brief connect_to_endpoint
 * \param layer
 * \return
 */
layer_t* init_http_layer(
      layer_t* layer );


#endif // __HTTP_LAYER_H__
