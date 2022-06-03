//
// Created by breeze on 2022/5/20.
//

#include "ApiTheaterServer.hpp"

oatpp::Object<TheaterDto> ApiTheaterServer::createTheater(const oatpp::Object<TheaterDto> &dto) {
    return m_server.createTheater(dto);
}

oatpp::Object<TheaterDto> ApiTheaterServer::updateTheater(const oatpp::Object<TheaterDto> &dto) {
    return m_server.updateTheater(dto);
}

oatpp::Object<TheaterDto> ApiTheaterServer::getTheaterById(const oatpp::Int32 &theaterId) {
    return m_server.getTheaterById(theaterId);
}

oatpp::Object<TheaterDtoList> ApiTheaterServer::getAllTheaters() {
    return m_server.getAllTheaters();
}

oatpp::Object<MessageDto> ApiTheaterServer::deleteTheaterById(const oatpp::Int32 &theaterId) {
    auto item = m_studioServer.getStudiosByTheaterId(theaterId);
    for (auto & item1 : *item->items) {
        m_seatServer.deleteSeatsByStudioId(item1->studioId);
    }
    m_studioServer.deleteStudiosByTheaterId(theaterId);
    return m_server.deleteTheaterById(theaterId);
}