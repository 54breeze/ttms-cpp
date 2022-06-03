//
// Created by breeze on 2022/5/20.
//

#ifndef TTMS_APITHEATERSERVER_HPP
#define TTMS_APITHEATERSERVER_HPP

#include "service/BaseService/BaseTheaterServer.hpp"
#include "service/BaseService/BaseStudioServer.hpp"
#include "service/BaseService/BaseSeatServer.hpp"

class ApiTheaterServer {
private:
    BaseTheaterServer m_server;
    BaseStudioServer m_studioServer;
    BaseSeatServer m_seatServer;
public:
    //    添加剧院
    oatpp::Object<TheaterDto> createTheater(const oatpp::Object<TheaterDto> &dto);

    //    更新剧院信息
    oatpp::Object<TheaterDto> updateTheater(const oatpp::Object<TheaterDto> &dto);

    //    通过剧院id获取剧院信息
    oatpp::Object<TheaterDto> getTheaterById(const oatpp::Int32 &theaterId);

    //    获取全部剧院信息
    oatpp::Object<TheaterDtoList> getAllTheaters();

    //    删除剧院
    oatpp::Object<MessageDto> deleteTheaterById(const oatpp::Int32 &theaterId);
};


#endif //TTMS_APITHEATERSERVER_HPP
