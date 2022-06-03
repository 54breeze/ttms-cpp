//
// Created by breeze on 2022/5/20.
//

#include "BaseSeatServer.hpp"

oatpp::Object<SeatDto> BaseSeatServer::createSeat(const oatpp::Object<SeatDto> &dto) {
    auto dbResult = m_database->createSeat(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto id = oatpp::sqlite::Utils::getLastInsertRowId(dbResult->getConnection());
    return getSeatById((v_int32) id);
}

oatpp::Object<SeatDto> BaseSeatServer::updateSeat(const oatpp::Object<SeatDto> &dto) {
    auto dbResult = m_database->updateSeat(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    return getSeatById(dto->seatId);
}

oatpp::Object<SeatDto> BaseSeatServer::getSeatById(const oatpp::Int32 &seatId,
                                               const oatpp::provider::ResourceHandle<oatpp::orm::Connection> &connection) {
    auto dbResult = m_database->getSeatById(seatId, connection);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Seat not found");
    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<SeatDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
    return result[0];
}

oatpp::Object<SeatDtoList> BaseSeatServer::getAllSeats() {
    auto dbResult = m_database->getAllSeats();
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<SeatDto>>>();
    auto list = SeatDtoList::createShared();
    list->items = items;
    return list;
}

oatpp::Object<SeatDtoList> BaseSeatServer::getSeatsByStudioId(const oatpp::Int32 &studioId) {
    auto dbResult = m_database->getSeatsByStudioId(studioId);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<SeatDto>>>();
    auto list = SeatDtoList::createShared();
    list->items = items;
    return list;
}

oatpp::Object<MessageDto> BaseSeatServer::deleteSeatById(const oatpp::Int32 &seatId) {
    auto dbResult = m_database->deleteSeatById(seatId);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto status = MessageDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = "Seat was successfully deleted";
    return status;
}

oatpp::Object<MessageDto> BaseSeatServer::deleteSeatsByStudioId(const oatpp::Int32 &studioId) {
    auto dbResult = m_database->deleteSeatsByStudioId(studioId);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto status = MessageDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = "Seats was successfully deleted";
    return status;
}