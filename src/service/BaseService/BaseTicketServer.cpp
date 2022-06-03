//
// Created by breeze on 2022/5/20.
//

#include "BaseTicketServer.hpp"

oatpp::Object<TicketDto> BaseTicketServer::createTicket(const oatpp::Object<TicketDto> &dto) {
    auto dbResult = m_database->createTicket(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto id = oatpp::sqlite::Utils::getLastInsertRowId(dbResult->getConnection());
    return getTicketById((v_int32) id);
}

oatpp::Object<TicketDto> BaseTicketServer::updateTicket(const oatpp::Object<TicketDto> &dto) {
    auto dbResult = m_database->updateTicket(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    return getTicketById(dto->ticketId);
}

oatpp::Object<TicketDto> BaseTicketServer::getTicketById(const oatpp::Int32 &ticketId,
                                                   const oatpp::provider::ResourceHandle<oatpp::orm::Connection> &connection) {
    auto dbResult = m_database->getTicketById(ticketId, connection);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Ticket not found");
    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<TicketDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
    return result[0];
}

oatpp::Object<TicketDtoList> BaseTicketServer::getAllTickets() {
    auto dbResult = m_database->getAllTickets();
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<TicketDto>>>();
    auto list = TicketDtoList::createShared();
    list->items = items;
    return list;
}

oatpp::Object<TicketDtoList> BaseTicketServer::getTicketsByStudioId(const oatpp::Int32 &studioId) {
    auto dbResult = m_database->getTicketsByStudioId(studioId);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<TicketDto>>>();
    auto list = TicketDtoList::createShared();
    list->items = items;
    return list;
}

oatpp::Object<TicketDtoList> BaseTicketServer::getTicketsByUserId(const oatpp::Int32 &userId) {
    auto dbResult = m_database->getTicketsByUserId(userId);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<TicketDto>>>();
    auto list = TicketDtoList::createShared();
    list->items = items;
    return list;
}

oatpp::Object<TicketDtoList> BaseTicketServer::getTicketsByPlayId(const oatpp::Int32 &playId) {
    auto dbResult = m_database->getTicketsByPlayId(playId);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<TicketDto>>>();
    auto list = TicketDtoList::createShared();
    list->items = items;
    return list;
}

oatpp::Object<MessageDto> BaseTicketServer::deleteTicketById(const oatpp::Int32 &ticketId) {
    auto dbResult = m_database->deleteTicketById(ticketId);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto status = MessageDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = "Ticket was successfully deleted";
    return status;
}

oatpp::Object<MessageDto> BaseTicketServer::deleteTicketsByScheduleId(const oatpp::Int32 &scheduleId) {
    auto dbResult = m_database->deleteTicketsByScheduleId(scheduleId);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto status = MessageDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = "Tickets was successfully deleted";
    return status;
}