//
// Created by breeze on 2022/5/20.
//

#include "ApiSeatServer.hpp"

oatpp::Object<SeatDto> ApiSeatServer::createSeat(const oatpp::Object<SeatDto> &dto) {
    auto studioDto = m_studioServer.getStudioById(dto->studioId);
    studioDto->seatNum = studioDto->seatNum + (oatpp::Int32) 1;
    m_studioServer.updateStudio(studioDto);
    return m_server.createSeat(dto);
}

oatpp::Object<SeatDto> ApiSeatServer::updateSeat(const oatpp::Object<SeatDto> &dto) {
    return m_server.updateSeat(dto);
}

oatpp::Object<SeatDtoList> ApiSeatServer::getSeatsByStudioId(const oatpp::Int32 &studioId) {
    return m_server.getSeatsByStudioId(studioId);
}

oatpp::Object<MessageDto> ApiSeatServer::deleteSeatById(const oatpp::Int32 &seatId) {
    return m_server.deleteSeatById(seatId);
}