//
// Created by breeze on 2022/5/20.
//

#ifndef TTMS_BASEPLAYSERVER_HPP
#define TTMS_BASEPLAYSERVER_HPP

#include "dto/PlayDto.hpp"
#include "dto/MessageDto.hpp"
#include "db/TTMSDb.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class BasePlayServer {
private:
    typedef oatpp::web::protocol::http::Status Status;
private:
    OATPP_COMPONENT(std::shared_ptr<TTMSDb>, m_database); // Inject database component
public:
    //    添加剧目
    oatpp::Object<PlayDto> createPlay(const oatpp::Object<PlayDto> &dto);

    //    更新剧目信息
    oatpp::Object<PlayDto> updatePlay(const oatpp::Object<PlayDto> &dto);

    //    通过剧目id获取剧目信息
    oatpp::Object<PlayDto> getPlayById(const oatpp::Int32 &playId,
                                       const oatpp::provider::ResourceHandle<oatpp::orm::Connection> &connection = nullptr);

    //    获取全部剧目信息
    oatpp::Object<PlayDtoList> getAllPlays();

    //    删除剧目
    oatpp::Object<MessageDto> deletePlayById(const oatpp::Int32 &playId);
};


#endif //TTMS_BASEPLAYSERVER_HPP
