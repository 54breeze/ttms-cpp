//
// Created by breeze on 2022/5/20.
//

#include "ApiStudioServer.hpp"

oatpp::Object<StudioDto> ApiStudioServer::createStudio(const oatpp::Object<StudioDto> &dto) {
    auto theaterDto = m_theaterServer.getTheaterById(dto->theaterId);
    theaterDto->studioNum = theaterDto->studioNum + (oatpp::Int32) 1;
    m_theaterServer.updateTheater(theaterDto);
    return m_server.createStudio(dto);
}

oatpp::Object<StudioDto> ApiStudioServer::updateStudio(const oatpp::Object<StudioDto> &dto) {
    return m_server.updateStudio(dto);
}

oatpp::Object<StudioDto> ApiStudioServer::getStudioById(const oatpp::Int32 &studioId) {
    return m_server.getStudioById(studioId);
}

oatpp::Object<StudioDtoList> ApiStudioServer::getStudiosByTheaterId(const oatpp::Int32 &theaterId) {
    return m_server.getStudiosByTheaterId(theaterId);
}

oatpp::Object<MessageDto> ApiStudioServer::deleteStudioById(const oatpp::Int32 &studioId) {
    m_seatServer.deleteSeatsByStudioId(studioId);
    return m_server.deleteStudioById(studioId);
}