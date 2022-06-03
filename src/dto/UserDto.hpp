//
// Created by breeze on 2022/5/19.
//

#ifndef TTMS_USERDTTO_HPP
#define TTMS_USERDTTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

/* Begin DTO code-generation */
#include OATPP_CODEGEN_BEGIN(DTO)

class UserDto : public oatpp::DTO {

    DTO_INIT(UserDto, DTO);

    DTO_FIELD(Int32, userId);

    DTO_FIELD(String, phone);

    DTO_FIELD(String, userPassword);

    DTO_FIELD(String, userName);

    DTO_FIELD(Int32, userIdentity);

    DTO_FIELD(Int32, sex);

    DTO_FIELD(String, country);

    DTO_FIELD(String, province);

    DTO_FIELD(String, city);

    DTO_FIELD(String, district);

    DTO_FIELD(String, description);

    DTO_FIELD(Int32, createTime);

    DTO_FIELD(Int32, updateTime);

    //    对应输出
    DTO_FIELD(Int32, create_sec);

    DTO_FIELD(Int32, create_min);

    DTO_FIELD(Int32, create_hour);

    DTO_FIELD(Int32, create_mday);

    DTO_FIELD(Int32, create_mon);

    DTO_FIELD(Int32, create_year);

    DTO_FIELD(Int32, update_sec);

    DTO_FIELD(Int32, update_min);

    DTO_FIELD(Int32, update_hour);

    DTO_FIELD(Int32, update_mday);

    DTO_FIELD(Int32, update_mon);

    DTO_FIELD(Int32, update_year);

};

class UserDtoList : public oatpp::DTO {

    DTO_INIT(UserDtoList, DTO);

    DTO_FIELD(Vector<oatpp::Object<UserDto>>, items);

};

/* End DTO code-generation */
#include OATPP_CODEGEN_END(DTO)

#endif //TTMS_USERDTTO_HPP
