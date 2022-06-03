//
// Created by breeze on 2022/5/20.
//

#include "ApiPlayServer.hpp"

oatpp::Object<PlayDto> ApiPlayServer::createPlay(const oatpp::Object<PlayDto> &dto) {
    return m_server.createPlay(dto);
}

oatpp::Object<PlayDto> ApiPlayServer::updatePlay(const oatpp::Object<PlayDto> &dto) {
    return m_server.updatePlay(dto);
}

oatpp::Object<PlayDto> ApiPlayServer::getPlayById(const oatpp::Int32 &playId) {
    return m_server.getPlayById(playId);
}

oatpp::Object<PlayDtoList> ApiPlayServer::getAllPlays() {
    return m_server.getAllPlays();
}