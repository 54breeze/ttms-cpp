//
// Created by breeze on 2022/5/19.
//

#ifndef TTMS_SEATDTO_HPP
#define TTMS_SEATDTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

/* Begin DTO code-generation */
#include OATPP_CODEGEN_BEGIN(DTO)

class SeatDto : public oatpp::DTO {
    DTO_INIT(SeatDto, DTO);

    DTO_FIELD(Int32, seatId);

    DTO_FIELD(Int32, seatX);

    DTO_FIELD(Int32, seatY);

    DTO_FIELD(Int32, studioId);

    DTO_FIELD(Int32, seatStatus);
};

class SeatDtoList : public oatpp::DTO {

    DTO_INIT(SeatDtoList, DTO);

    DTO_FIELD(Vector < oatpp::Object<SeatDto> >, items);

};

/* End DTO code-generation */
#include OATPP_CODEGEN_END(DTO)

#endif //TTMS_SEATDTO_HPP
