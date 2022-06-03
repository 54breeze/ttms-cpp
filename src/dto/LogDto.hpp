//
// Created by breeze on 2022/5/19.
//

#ifndef TTMS_LOGDTO_HPP
#define TTMS_LOGDTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

/* Begin DTO code-generation */
#include OATPP_CODEGEN_BEGIN(DTO)

class LogDto : public oatpp::DTO {
    DTO_INIT(LogDto, DTO)

    DTO_FIELD(Int32, logId);

    DTO_FIELD(Int32, ticketId);

    DTO_FIELD(Int32, scheduleId);

    DTO_FIELD(Int32, userId);

    DTO_FIELD(Int32, playId);

    DTO_FIELD(String, playName);

    DTO_FIELD(Float32, price);
};

class LogDtoList : public oatpp::DTO {

    DTO_INIT(LogDtoList, DTO)

    DTO_FIELD(Vector < oatpp::Object<LogDto> >, items);
};

/* End DTO code-generation */
#include OATPP_CODEGEN_END(DTO)

#endif //TTMS_LOGDTO_HPP
