//
// Created by breeze on 2022/5/19.
//

#ifndef TTMS_BASETHEATERSERVER_HPP
#define TTMS_BASETHEATERSERVER_HPP

#include "dto/TheaterDto.hpp"
#include "dto/MessageDto.hpp"
#include "db/TTMSDb.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class BaseTheaterServer {
private:
    typedef oatpp::web::protocol::http::Status Status;
private:
    OATPP_COMPONENT(std::shared_ptr<TTMSDb>, m_database); // Inject database component
public:
    //    添加剧院
    oatpp::Object<TheaterDto> createTheater(const oatpp::Object<TheaterDto> &dto);

    //    更新剧院信息
    oatpp::Object<TheaterDto> updateTheater(const oatpp::Object<TheaterDto> &dto);

    //    通过剧院id获取剧院信息
    oatpp::Object<TheaterDto> getTheaterById(const oatpp::Int32 &theaterId,
                                             const oatpp::provider::ResourceHandle<oatpp::orm::Connection> &connection = nullptr);

    //    获取全部剧院信息
    oatpp::Object<TheaterDtoList> getAllTheaters();

    //    删除剧院
    oatpp::Object<MessageDto> deleteTheaterById(const oatpp::Int32 &theaterId);
};


#endif //TTMS_BASETHEATERSERVER_HPP
