//
// Created by breeze on 2022/5/6.
//

#ifndef NEW_TTMSDB_HPP
#define NEW_TTMSDB_HPP

#include "dto/DTO.hpp"
#include "oatpp-sqlite/orm.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient) //<- Begin Codegen

/**
 * UserDb client definitions.
 */

class TTMSDb : public oatpp::orm::DbClient {
public:
    TTMSDb(const std::shared_ptr<oatpp::orm::Executor> &executor) : oatpp::orm::DbClient(executor) {
        oatpp::orm::SchemaMigration migration(executor);
        migration.addFile(1 /* start from version 1 */, DATABASE_MIGRATIONS "/ttms.sql");
        // TODO - Add more migrations here.
        migration.migrate(); // <-- run migrations. This guy will throw on error.
        auto version = executor->getSchemaVersion();
        OATPP_LOGD("TTMSDb", "Migration - OK. Version=%lld.", version);
    }

//    users
    QUERY(createUser,
          "INSERT INTO users "
          "(phone,userPassword,userName,userIdentity,sex,country,province,city,district,description,createTime,updateTime) VALUES "
          "(:users.phone,:users.userPassword,:users.userName,:users.userIdentity,:users.sex,:users.country,:users.province,:users.city,:users.district,:users.description,:users.createTime,:users.updateTime);",
          PARAM(oatpp::Object<UserDto>, users
          ));

    QUERY(updateUser,
          "UPDATE users "
          "SET "
          "phone=:users.phone,"
          "userPassword=:users.userPassword,"
          "userName=:users.userName,"
          "userIdentity=:users.userIdentity,"
          "sex=:users.sex,"
          "country=:users.country,"
          "province=:users.province,"
          "city=:users.city,"
          "district=:users.district,"
          "description=:users.description,"
          "updateTime=:users.updateTime"
          " WHERE "
          "userId=:users.userId;",
          PARAM(oatpp::Object<UserDto>, users
          ));

    QUERY(getUserById,
          "SELECT * FROM users WHERE userId=:userId;",
          PARAM(oatpp::Int32, userId
          ));

    QUERY(getAllUsers,
          "SELECT * FROM users;");

    QUERY(deleteUserById,
          "DELETE FROM User WHERE userId=:userId;",
          PARAM(oatpp::Int32, userId
          ));

//    theater
    QUERY(createTheater,
          "INSERT INTO theater "
          "(theaterName,description,country,province,city,district,address) VALUES"
          "(:theater.theaterName,:theater.description,:theater.country,:theater.province,:theater.city,:theater.district,:theater.address);",
          PARAM(oatpp::Object<TheaterDto>, theater
          ));

    QUERY(updateTheater,
          "UPDATE theater "
          "SET "
          "theaterName=:theater.theaterName,"
          "description=:theater.description,"
          "theaterStatus=:theater.theaterStatus,"
          "country=:theater.country,"
          "province=:theater.province,"
          "city=:theater.city,"
          "district=:theater.district,"
          "address=:theater.address"
          " WHERE "
          "theaterId=:theater.theaterId;",
          PARAM(oatpp::Object<TheaterDto>, theater
          ));

    QUERY(getTheaterById,
          "SELECT * FROM theater WHERE theaterId=:theaterId;",
          PARAM(oatpp::Int32, theaterId
          ));

    QUERY(getAllTheaters,
          "SELECT * FROM theater;");

    QUERY(deleteTheaterById,
          "DELETE FROM theater WHERE theaterId=:theaterId;",
          PARAM(oatpp::Int32, theaterId
          ));

//    studio
    QUERY(createStudio,
          "INSERT INTO studio "
          "(studioName,theaterId,description) VALUES"
          "(:studio.studioName,:studio.theaterId,:studio.description);",
          PARAM(oatpp::Object<StudioDto>, studio
          ));

    QUERY(updateStudio,
          "UPDATE studio "
          "SET "
          "studioName=:studio.studioName,"
          "theaterId=:studio.theaterId,"
          "description=:studio.description,"
          "studioStatus=:studio.studioStatus"
          " WHERE "
          "studioId=:studio.studioId;",
          PARAM(oatpp::Object<StudioDto>, studio
          ));

    QUERY(getStudioById,
          "SELECT * FROM studio WHERE studioId=:studioId;",
          PARAM(oatpp::Int32, studioId
          ));

    QUERY(getAllStudios,
          "SELECT * FROM studio;");

    QUERY(getStudiosByTheaterId,
          "SELECT * FROM studio WHERE theaterId=:theaterId;",
          PARAM(oatpp::Int32, theaterId
          ));

    QUERY(deleteStudioById,
          "DELETE FROM studio WHERE studioId=:studioId;",
          PARAM(oatpp::Int32, studioId
          ));

    QUERY(deleteStudiosByTheaterId,
          "DELETE FROM studio WHERE theaterId=:theaterId;",
          PARAM(oatpp::Int32, theaterId));

//    seat
    QUERY(createSeat,
          "INSERT INTO seat "
          "(seatX,seatY,studioId) VALUES"
          "(:seat.seatX,:seat.seatY,:seat.studioId);",
          PARAM(oatpp::Object<SeatDto>, seat
          ));

    QUERY(updateSeat,
          "UPDATE seat "
          "SET "
          "seatX=:seat.seatX,"
          "seatY=:seat.seatY,"
          "studioId=:seat.studioId,"
          "seatStatus=:seat.seatStatus"
          " WHERE "
          "seatId=:seat.seatId;",
          PARAM(oatpp::Object<SeatDto>, seat
          ));

    QUERY(getSeatById,
          "SELECT * FROM seat WHERE seatId=:seatId;",
          PARAM(oatpp::Int32, seatId
          ));

    QUERY(getAllSeats,
          "SELECT * FROM seat;");

    QUERY(getSeatsByStudioId,
          "SELECT * FROM seat WHERE studioId=:studioId;",
          PARAM(oatpp::Int32, studioId
          ));

    QUERY(deleteSeatById,
          "DELETE FROM seat WHERE seatId=:seatId;",
          PARAM(oatpp::Int32, seatId
          ));

    QUERY(deleteSeatsByStudioId,
          "DELETE FROM seat WHERE studioId=:studioId;",
          PARAM(oatpp::Int32, studioId
          ));

//    play
    QUERY(createPlay,
          "INSERT INTO play "
          "(playName,playHour,playMin,playSec,description) VALUES"
          "(:play.playName,:play.playHour,:play.playMin,:play.playSec,:play.description);",
          PARAM(oatpp::Object<PlayDto>, play
          ));

    QUERY(updatePlay,
          "UPDATE play "
          "SET "
          "playName=:play.playName,"
          "playHour=:play.playHour,"
          "playMin=:play.playMin,"
          "playSec=:play.playSec,"
          "description=:play.description"
          " WHERE "
          "playId=:play.playId;",
          PARAM(oatpp::Object<PlayDto>, play
          ));

    QUERY(getPlayById,
          "SELECT * FROM play WHERE playId=:playId;",
          PARAM(oatpp::Int32, playId
          ));

    QUERY(getAllPlays,
          "SELECT * FROM play;");

    QUERY(deletePlayById,
          "DELETE FROM play WHERE playId=:playId;",
          PARAM(oatpp::Int32, playId
          ));

//    schedule
    QUERY(createSchedule,
          "INSERT INTO schedule "
          "(theaterId,studioId,playId,startTime,endTime,price) VALUES"
          "(:schedule.theaterId,:schedule.studioId,:schedule.playId,:schedule.startTime,:schedule.endTime,:schedule.price);",
          PARAM(oatpp::Object<ScheduleDto>, schedule
          ));

    QUERY(updateSchedule,
          "UPDATE schedule "
          "SET "
          "theaterId=:schedule.theaterId,"
          "studioId=:schedule.studioId,"
          "playId=:schedule.playId,"
          "startTime=:schedule.startTime,"
          "endTime=:schedule.endTime"
          "price=:schedule.price"
          " WHERE "
          "scheduleId=:schedule.scheduleId;",
          PARAM(oatpp::Object<ScheduleDto>, schedule
          ));

    QUERY(getScheduleById,
          "SELECT * FROM schedule WHERE scheduleId=:scheduleId;",
          PARAM(oatpp::Int32, scheduleId
          ));

    QUERY(getAllSchedules,
          "SELECT * FROM schedule;");

    QUERY(getSchedulesByTheaterId,
          "SELECT * FROM schedule WHERE theaterId=:theaterId;",
          PARAM(oatpp::Int32, theaterId
          ));

    QUERY(getSchedulesByStudioId,
          "SELECT * FROM schedule WHERE studioId=:studioId;",
          PARAM(oatpp::Int32, studioId
          ));

    QUERY(deleteScheduleById,
          "DELETE FROM schedule WHERE scheduleId=:scheduleId;",
          PARAM(oatpp::Int32, scheduleId
          ));

//    ticket
    QUERY(createTicket,
          "INSERT INTO ticket "
          "(scheduleId,studioId,playId,playName,startTime,endTime,seatId,seatX,seatY,price) VALUES"
          "(:ticket.scheduleId,:ticket.studioId,:ticket.playId,:ticket.playName,:ticket.startTime,:ticket.endTime,:ticket.seatId,:ticket.seatX,:ticket.seatY,:ticket.price);",
          PARAM(oatpp::Object<TicketDto>, ticket
          ));

    QUERY(updateTicket,
          "UPDATE ticket "
          "SET "
          "ticketStatus=:ticket.ticketStatus,"
          "userId=:ticket.userId,"
          "userName=:ticket.userName"
          " WHERE "
          "ticketId=:ticket.ticketId;",
          PARAM(oatpp::Object<TicketDto>, ticket
          ));

    QUERY(getTicketById,
          "SELECT * FROM ticket WHERE ticketId=:ticketId;",
          PARAM(oatpp::Int32, ticketId
          ));

    QUERY(getAllTickets,
          "SELECT * FROM ticket;");

    QUERY(getTicketsByStudioId,
          "SELECT * FROM ticket WHERE studioId=:studioId;",
          PARAM(oatpp::Int32, studioId
          ));

    QUERY(getTicketsByUserId,
          "SELECT * FROM ticket WHERE userId=:userId;",
          PARAM(oatpp::Int32, userId
          ));

    QUERY(getTicketsByPlayId,
          "SELECT * FROM ticket WHERE playId=:playId;",
          PARAM(oatpp::Int32, playId
          ));

    QUERY(deleteTicketById,
          "DELETE FROM ticket WHERE ticketId=:ticketId;",
          PARAM(oatpp::Int32, ticketId
          ));

    QUERY(deleteTicketsByScheduleId,
          "DELETE FROM ticket WHERE scheduleId=:scheduleId;",
          PARAM(oatpp::Int32, scheduleId
          ));

//    log
    QUERY(createLog,
          "INSERT INTO log "
          "(ticketId,scheduleId,userId,playId,playName,price) VALUES"
          "(:log.ticketId,:log.scheduleId,:log.userId,:log.playId,:log.playName,:log.price);",
          PARAM(oatpp::Object<LogDto>, log
          ));

    QUERY(updateLog,
          "UPDATE log "
          "SET "
          "ticketId=:log.ticketId,"
          "scheduleId=:log.scheduleId,"
          "userId=:log.userId,"
          "playId=:log.playId,"
          "playName=:log.playName,"
          "price=:log.price"
          " WHERE "
          "logId=:log.logId;",
          PARAM(oatpp::Object<LogDto>, log
          ));

    QUERY(getLogById,
          "SELECT * FROM log WHERE logId=:logId;",
          PARAM(oatpp::Int32, logId
          ));

    QUERY(getAllLogs,
          "SELECT * FROM log;");

    QUERY(getLogsByPlayId,
          "SELECT * FROM log WHERE playId=:playId;",
          PARAM(oatpp::Int32, playId
          ));

    QUERY(getLogsByUserId,
          "SELECT * FROM log WHERE userId=:userId;",
          PARAM(oatpp::Int32, userId
          ));

    QUERY(deleteLogById,
          "DELETE FROM log WHERE logId=:logId;",
          PARAM(oatpp::Int32, logId
          ));

};

#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif //NEW_TTMSDB_HPP
