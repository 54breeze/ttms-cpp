//
// Created by breeze on 2022/5/19.
//

#ifndef TTMS_TICKETDTO_HPP
#define TTMS_TICKETDTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

/* Begin DTO code-generation */
#include OATPP_CODEGEN_BEGIN(DTO)

class TicketDto : public oatpp::DTO {

    DTO_INIT(TicketDto, DTO)

    DTO_FIELD(Int32, ticketId);

    DTO_FIELD(Int32, scheduleId);

    DTO_FIELD(Int32, studioId);

    DTO_FIELD(Int32, playId);

    DTO_FIELD(String, playName);

    DTO_FIELD(Int32, startTime);

    DTO_FIELD(Int32, endTime);

    DTO_FIELD(Int32, seatId);

    DTO_FIELD(Int32, seatX);

    DTO_FIELD(Int32, seatY);

    DTO_FIELD(Float32, price);

    DTO_FIELD(Int32, ticketStatus);

    DTO_FIELD(Int32, userId);

    DTO_FIELD(String, userName);

    //    对应输出
    DTO_FIELD(Int32, start_sec);

    DTO_FIELD(Int32, start_min);

    DTO_FIELD(Int32, start_hour);

    DTO_FIELD(Int32, start_mday);

    DTO_FIELD(Int32, start_mon);

    DTO_FIELD(Int32, start_year);

    DTO_FIELD(Int32, end_sec);

    DTO_FIELD(Int32, end_min);

    DTO_FIELD(Int32, end_hour);

    DTO_FIELD(Int32, end_mday);

    DTO_FIELD(Int32, end_mon);

    DTO_FIELD(Int32, end_year);
};

class TicketDtoList : public oatpp::DTO {

    DTO_INIT(TicketDtoList, DTO)

    DTO_FIELD(Vector < oatpp::Object<TicketDto> >, items);
};

/* End DTO code-generation */
#include OATPP_CODEGEN_END(DTO)

#endif //TTMS_TICKETDTO_HPP
