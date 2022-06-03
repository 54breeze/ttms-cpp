//
// Created by breeze on 2022/5/19.
//

#ifndef TTMS_THEATERDTO_HPP
#define TTMS_THEATERDTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

/* Begin DTO code-generation */
#include OATPP_CODEGEN_BEGIN(DTO)

class TheaterDto : public oatpp::DTO {
    DTO_INIT(TheaterDto, DTO)

    DTO_FIELD(Int32, theaterId);

    DTO_FIELD(String, theaterName);

    DTO_FIELD(Int32, studioNum);

    DTO_FIELD(String, description);

    DTO_FIELD(Int32, theaterStatus);

    DTO_FIELD(String, country);

    DTO_FIELD(String, province);

    DTO_FIELD(String, city);

    DTO_FIELD(String, district);

    DTO_FIELD(String, address);
};

class TheaterDtoList : public oatpp::DTO {

    DTO_INIT(TheaterDtoList, DTO);

    DTO_FIELD(Vector<oatpp::Object<TheaterDto>>, items);

};

/* End DTO code-generation */
#include OATPP_CODEGEN_END(DTO)

#endif //TTMS_THEATERDTO_HPP
