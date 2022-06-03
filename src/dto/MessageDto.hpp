//
// Created by breeze on 2022/5/5.
//

#ifndef NEW_MESSAGEDTO_HPP
#define NEW_MESSAGEDTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

/* Begin DTO code-generation */
#include OATPP_CODEGEN_BEGIN(DTO)

class MessageDto : public oatpp::DTO {
    DTO_INIT(MessageDto, DTO /* Extends */)

    DTO_FIELD(String, status);

    DTO_FIELD(Int32, code);

    DTO_FIELD(String, message);
};

/* End DTO code-generation */
#include OATPP_CODEGEN_END(DTO)

#endif //NEW_MESSAGEDTO_HPP
