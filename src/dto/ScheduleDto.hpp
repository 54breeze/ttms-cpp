//
// Created by breeze on 2022/5/19.
//

#ifndef TTMS_SCHEDULEDTO_HPP
#define TTMS_SCHEDULEDTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

/* Begin DTO code-generation */
#include OATPP_CODEGEN_BEGIN(DTO)

class ScheduleDto : public oatpp::DTO {

    DTO_INIT(ScheduleDto, DTO)

    DTO_FIELD(Int32, scheduleId);

    DTO_FIELD(Int32, theaterId);

    DTO_FIELD(Int32, studioId);

    DTO_FIELD(Int32, playId);

    DTO_FIELD(Int32, startTime);

    DTO_FIELD(Int32, endTime);

    DTO_FIELD(Float32, price);

    //    对应输出
    DTO_FIELD(Int32, start_year);

    DTO_FIELD(Int32, start_mon);

    DTO_FIELD(Int32, start_mday);

    DTO_FIELD(Int32, start_hour);

    DTO_FIELD(Int32, start_min);

    DTO_FIELD(Int32, start_sec);

    DTO_FIELD(Int32, end_year);

    DTO_FIELD(Int32, end_mon);

    DTO_FIELD(Int32, end_mday);

    DTO_FIELD(Int32, end_hour);

    DTO_FIELD(Int32, end_min);

    DTO_FIELD(Int32, end_sec);

};

class ScheduleDtoList : public oatpp::DTO {

    DTO_INIT(ScheduleDtoList, DTO)

    DTO_FIELD(Vector < oatpp::Object<ScheduleDto> >, items);
};

/* End DTO code-generation */
#include OATPP_CODEGEN_END(DTO)

#endif //TTMS_SCHEDULEDTO_HPP
