//
// Created by breeze on 2022/5/20.
//

#ifndef TTMS_APILOGSERVER_HPP
#define TTMS_APILOGSERVER_HPP

#include "service/BaseService/BaseLogServer.hpp"

class ApiLogServer {
private:
    BaseLogServer m_server;
public:
    //    通过id获取记录
    oatpp::Object<LogDto> getLogById(const oatpp::Int32 &logId);

    //    获取全部记录
    oatpp::Object<LogDtoList> getAllLogs();

    //    通过剧目id获取记录
    oatpp::Object<LogDtoList> getLogsByPlayId(const oatpp::Int32 &playId);

    //    通过用户id获取记录
    oatpp::Object<LogDtoList> getLogsByUserId(const oatpp::Int32 &userId);
};


#endif //TTMS_APILOGSERVER_HPP
