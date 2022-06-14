/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Bernhard Mayer <bernard@generationmake.de>, Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef ARDUINO_UAVCAN_TYPES_UAVCAN_PRIMITIVE_SCALAR_REAL32_1_0_HPP_
#define ARDUINO_UAVCAN_TYPES_UAVCAN_PRIMITIVE_SCALAR_REAL32_1_0_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include <types/uavcan/primitive/scalar/Real32_1_0.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace uavcan {
namespace primitive {
namespace scalar {

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID>
class Real32_1_0
{

public:

  uavcan_primitive_scalar_Real32_1_0 data;

  static constexpr CanardPortID       PORT_ID          = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_primitive_scalar_Real32_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND    = CanardTransferKindMessage;

  Real32_1_0()
  {
    uavcan_primitive_scalar_Real32_1_0_initialize_(&data);
  }

  Real32_1_0(Real32_1_0 const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static Real32_1_0 deserialize(CanardTransfer const & transfer)
  {
    Real32_1_0<ID> b;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    uavcan_primitive_scalar_Real32_1_0_deserialize_(&b.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return b;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = Real32_1_0::MAX_PAYLOAD_SIZE;
    return (uavcan_primitive_scalar_Real32_1_0_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* uavcan */
} /* primitive */
} /* scalar */

#endif /* ARDUINO_UAVCAN_TYPES_UAVCAN_PRIMITIVE_SCALAR_REAL32_1_0_HPP_ */
