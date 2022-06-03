//
// Created by breeze on 2022/5/20.
//

#ifndef TTMS_APIPLAYSERVER_HPP
#define TTMS_APIPLAYSERVER_HPP

#include "service/BaseService/BasePlayServer.hpp"

class ApiPlayServer {
private:
    BasePlayServer m_server;
public:
    //    添加剧目
    oatpp::Object<PlayDto> createPlay(const oatpp::Object<PlayDto> &dto);

    //    更新剧目信息
    oatpp::Object<PlayDto> updatePlay(const oatpp::Object<PlayDto> &dto);

    //    通过剧目id获取剧目信息
    oatpp::Object<PlayDto> getPlayById(const oatpp::Int32 &playId);

    //    获取全部剧目信息
    oatpp::Object<PlayDtoList> getAllPlays();
};


#endif //TTMS_APIPLAYSERVER_HPP
