//
// Created by breeze on 2022/5/20.
//

#ifndef TTMS_BASESEATSERVER_HPP
#define TTMS_BASESEATSERVER_HPP

#include "dto/SeatDto.hpp"
#include "dto/MessageDto.hpp"
#include "db/TTMSDb.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class BaseSeatServer {
private:
    typedef oatpp::web::protocol::http::Status Status;
private:
    OATPP_COMPONENT(std::shared_ptr<TTMSDb>, m_database); // Inject database component
public:
    //    添加座位
    oatpp::Object<SeatDto> createSeat(const oatpp::Object<SeatDto> &dto);

    //    更新座位信息
    oatpp::Object<SeatDto> updateSeat(const oatpp::Object<SeatDto> &dto);

    //    通过座位id获取座位信息
    oatpp::Object<SeatDto> getSeatById(const oatpp::Int32 &seatId,
                                       const oatpp::provider::ResourceHandle<oatpp::orm::Connection> &connection = nullptr);

    //    获取全部座位信息
    oatpp::Object<SeatDtoList> getAllSeats();

    //    获取id演出厅全部座位信息
    oatpp::Object<SeatDtoList> getSeatsByStudioId(const oatpp::Int32 &studioId);

    //    删除座位
    oatpp::Object<MessageDto> deleteSeatById(const oatpp::Int32 &seatId);

    //    通过演出厅id删除座位
    oatpp::Object<MessageDto> deleteSeatsByStudioId(const oatpp::Int32 &studioId);
};


#endif //TTMS_BASESEATSERVER_HPP
