//
// Created by breeze on 2022/5/20.
//

#ifndef TTMS_APISEATSERVER_HPP
#define TTMS_APISEATSERVER_HPP

#include "service/BaseService/BaseSeatServer.hpp"
#include "service/BaseService/BaseStudioServer.hpp"

class ApiSeatServer {
private:
    BaseSeatServer m_server;
    BaseStudioServer m_studioServer;
public:
    //    添加座位
    oatpp::Object<SeatDto> createSeat(const oatpp::Object<SeatDto> &dto);

    //    更新座位信息
    oatpp::Object<SeatDto> updateSeat(const oatpp::Object<SeatDto> &dto);

    //    通过演出厅id获取座位信息
    oatpp::Object<SeatDtoList> getSeatsByStudioId(const oatpp::Int32 &studioId);

    //    通过id删除座位
    oatpp::Object<MessageDto> deleteSeatById(const oatpp::Int32 &seatId);
};


#endif //TTMS_APISEATSERVER_HPP
