//
// Created by breeze on 2022/5/20.
//

#include "ApiLogServer.hpp"

oatpp::Object<LogDto> ApiLogServer::getLogById(const oatpp::Int32 &logId) {
    return m_server.getLogById(logId);
}

oatpp::Object<LogDtoList> ApiLogServer::getAllLogs() {
    return m_server.getAllLogs();
}

oatpp::Object<LogDtoList> ApiLogServer::getLogsByPlayId(const oatpp::Int32 &playId) {
    return m_server.getLogsByPlayId(playId);
}

oatpp::Object<LogDtoList> ApiLogServer::getLogsByUserId(const oatpp::Int32 &userId) {
    return m_server.getLogsByUserId(userId);
}