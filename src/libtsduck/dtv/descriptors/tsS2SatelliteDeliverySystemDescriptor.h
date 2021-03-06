//----------------------------------------------------------------------------
//
// TSDuck - The MPEG Transport Stream Toolkit
// Copyright (c) 2005-2020, Thierry Lelegard
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.
//
//----------------------------------------------------------------------------
//!
//!  @file
//!  Representation of an S2_satellite_delivery_system_descriptor.
//!
//----------------------------------------------------------------------------

#pragma once
#include "tsAbstractDeliverySystemDescriptor.h"

namespace ts {
    //!
    //! Representation of an S2_satellite_delivery_system_descriptor.
    //!
    //! @see ETSI 300 468, 6.2.13.3.
    //! @ingroup descriptor
    //!
    class TSDUCKDLL S2SatelliteDeliverySystemDescriptor : public AbstractDeliverySystemDescriptor
    {
    public:
        // Public members:
        bool     scrambling_sequence_selector;        //!< See ETSI 300 468, 6.2.13.3.
        bool     multiple_input_stream_flag;          //!< See ETSI 300 468, 6.2.13.3.
        bool     backwards_compatibility_indicator;   //!< See ETSI 300 468, 6.2.13.3.
        uint32_t scrambling_sequence_index;           //!< See ETSI 300 468, 6.2.13.3, 18-bit value.
        uint8_t  input_stream_identifier;             //!< See ETSI 300 468, 6.2.13.3.

        //!
        //! Default constructor.
        //!
        S2SatelliteDeliverySystemDescriptor();

        //!
        //! Constructor from a binary descriptor
        //! @param [in,out] duck TSDuck execution context.
        //! @param [in] bin A binary descriptor to deserialize.
        //!
        S2SatelliteDeliverySystemDescriptor(DuckContext& duck, const Descriptor& bin);

        // Inherited methods
        virtual void serialize(DuckContext&, Descriptor&) const override;
        virtual void deserialize(DuckContext&, const Descriptor&) override;
        DeclareLegacyDisplayDescriptor();

    protected:
        // Inherited methods
        virtual void clearContent() override;
        virtual void buildXML(DuckContext&, xml::Element*) const override;
        virtual bool analyzeXML(DuckContext&, const xml::Element*) override;
    };
}
