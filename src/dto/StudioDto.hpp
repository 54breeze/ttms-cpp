//
// Created by breeze on 2022/5/19.
//

#ifndef TTMS_STUDIODTO_HPP
#define TTMS_STUDIODTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

/* Begin DTO code-generation */
#include OATPP_CODEGEN_BEGIN(DTO)

class StudioDto : public oatpp::DTO {
    DTO_INIT(StudioDto, DTO);

    DTO_FIELD(Int32, studioId);

    DTO_FIELD(String, studioName);

    DTO_FIELD(Int32, theaterId);

    DTO_FIELD(Int32, seatNum);

    DTO_FIELD(String, description);

    DTO_FIELD(Int32, studioStatus);
};

class StudioDtoList : public oatpp::DTO {

    DTO_INIT(StudioDtoList, DTO);

    DTO_FIELD(Vector < oatpp::Object<StudioDto>>, items);

};

/* End DTO code-generation */
#include OATPP_CODEGEN_END(DTO)

#endif //TTMS_STUDIODTO_HPP
