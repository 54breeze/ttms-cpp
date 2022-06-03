//
// Created by breeze on 2022/5/20.
//

#ifndef TTMS_APISTUDIOSERVER_HPP
#define TTMS_APISTUDIOSERVER_HPP

#include "service/BaseService/BaseStudioServer.hpp"
#include "service/BaseService/BaseTheaterServer.hpp"
#include "service/BaseService/BaseSeatServer.hpp"

class ApiStudioServer {
private:
    BaseStudioServer m_server;
    BaseTheaterServer m_theaterServer;
    BaseSeatServer m_seatServer;
public:
    //    添加演出厅
    oatpp::Object<StudioDto> createStudio(const oatpp::Object<StudioDto> &dto);

    //    更新演出厅信息
    oatpp::Object<StudioDto> updateStudio(const oatpp::Object<StudioDto> &dto);

    //    通过演出厅id获取演出厅信息
    oatpp::Object<StudioDto> getStudioById(const oatpp::Int32 &studioId);

    //    通过剧院id获取演出厅信息
    oatpp::Object<StudioDtoList> getStudiosByTheaterId(const oatpp::Int32 &theaterId);

    //    通过id删除演出厅
    oatpp::Object<MessageDto> deleteStudioById(const oatpp::Int32 &studioId);
};


#endif //TTMS_APISTUDIOSERVER_HPP
