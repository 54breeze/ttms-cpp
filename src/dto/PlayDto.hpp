//
// Created by breeze on 2022/5/19.
//

#ifndef TTMS_PLAYDTO_HPP
#define TTMS_PLAYDTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

/* Begin DTO code-generation */
#include OATPP_CODEGEN_BEGIN(DTO)

class PlayDto : public oatpp::DTO {
    DTO_INIT(PlayDto, DTO)

    DTO_FIELD(Int32, playId);

    DTO_FIELD(String, playName);

    DTO_FIELD(Int32, playHour);

    DTO_FIELD(Int32, playMin);

    DTO_FIELD(Int32, playSec);

    DTO_FIELD(String, description);

};

class PlayDtoList : public oatpp::DTO {

    DTO_INIT(PlayDtoList, DTO)

    DTO_FIELD(Vector < oatpp::Object<PlayDto> >, items);

};

/* End DTO code-generation */
#include OATPP_CODEGEN_END(DTO)

#endif //TTMS_PLAYDTO_HPP
