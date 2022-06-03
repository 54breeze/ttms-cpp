CREATE TABLE users
(
    userId       INTEGER NOT NULL,  --COMMENT '用户编号'
    phone        TEXT    NOT NULL,  --COMMENT '手机号'
    userPassword TEXT    NOT NULL,  --COMMENT '密码'
    userName     TEXT    NOT NULL,  --COMMENT '昵称'
    userIdentity INTEGER DEFAULT 4, --COMMENT '用户身份 0管理员ADMIN 1运营经理MANAGER 2售票员CONDUCTOR 3财务经理ACCOUNT 4顾客CUSTOMER'
    sex          INTEGER DEFAULT 0, --COMMENT '性别 0未知UNKNOWN 1男BOY 2女GIRL'
    country      TEXT,              --COMMENT '国家'
    province     TEXT,              --COMMENT '省份'
    city         TEXT,              --COMMENT '城市'
    district     TEXT,              --COMMENT '区县'
    description  TEXT,              --COMMENT '简介'
    createTime   INTEGER NOT NULL,  --COMMENT '创建时间'
    updateTime   INTEGER NOT NULL,  --COMMENT '更新时间'
    PRIMARY KEY (userId)
); --COMMENT = '用户'
CREATE TABLE theater
(
    theaterId     INTEGER NOT NULL,  --COMMENT '剧院编号'
    theaterName   TEXT    NOT NULL,  --COMMENT '剧院名称'
    studioNum     INTEGER DEFAULT 0, --COMMENT '演出厅总数'
    description   TEXT,              --COMMENT '剧院简介'
    theaterStatus INTEGER DEFAULT 0, --COMMENT '剧院状态 0正常GOOD 1不正常DAMAGE'
    country       TEXT    NOT NULL,  --COMMENT '国家'
    province      TEXT    NOT NULL,  --COMMENT '省份'
    city          TEXT    NOT NULL,  --COMMENT '城市'
    district      TEXT    NOT NULL,  --COMMENT '区县'
    address       TEXT    NOT NULL,  --COMMENT '详细地址'
    PRIMARY KEY (theaterId)
); --COMMENT = '剧院'
CREATE TABLE studio
(
    studioId     INTEGER NOT NULL,  --COMMENT '演出厅编号',
    studioName   TEXT    NOT NULL,  --COMMENT '演出厅名称',
    theaterId    INTEGER NOT NULL,  --COMMENT '所属剧院编号',
    seatNum      INTEGER DEFAULT 0, --COMMENT '座位总数',
    description  TEXT,              --COMMENT '演出厅简介',
    studioStatus INTEGER DEFAULT 0, --COMMENT '演出厅状态 0正常GOOD 1不正常DAMAGE',
    PRIMARY KEY (studioId)
); --COMMENT = '演出厅';
CREATE TABLE seat
(
    seatId     INTEGER NOT NULL,  --COMMENT '座位编号',
    seatX      INTEGER NOT NULL,  --COMMENT '座位X坐标',
    seatY      INTEGER NOT NULL,  --COMMENT '座位Y坐标',
    studioId   INTEGER NOT NULL,  --COMMENT '所属演出厅编号',
    seatStatus INTEGER DEFAULT 0, --COMMENT '座位状态 0正常GOOD 1不正常DAMAGE',
    PRIMARY KEY (seatId)
); --COMMENT = '座位';
CREATE TABLE play
(
    playId      INTEGER NOT NULL, --COMMENT '节目编号',
    playName    TEXT    NOT NULL, --COMMENT '节目名称',
    playHour    INTEGER NOT NULL, --COMMENT '节目时长hour',
    playMin     INTEGER NOT NULL, --COMMENT '节目时长min',
    playSec     INTEGER NOT NULL, --COMMENT '节目时长sec',
    description TEXT,             --COMMENT '节目简介',
    PRIMARY KEY (playId)
); --COMMENT = '节目';
CREATE TABLE schedule
(
    scheduleId INTEGER NOT NULL, --COMMENT '计划编号',
    theaterId  INTEGER NOT NULL, --COMMENT '剧院编号',
    studioId   INTEGER NOT NULL, --COMMENT '演出厅编号',
    playId     INTEGER NOT NULL, --COMMENT '节目编号',
    startTime  INTEGER NOT NULL, --COMMENT '开始时间',
    endTime    INTEGER NOT NULL, --COMMENT '结束时间',
    price      REAL    NOT NULL, --COMMENT '价格',
    PRIMARY KEY (scheduleId)
); --COMMENT = '演出计划';
CREATE TABLE ticket
(
    ticketId     INTEGER NOT NULL,  --COMMENT '票编号',
    scheduleId   INTEGER NOT NULL,  --COMMENT '计划编号',
    studioId     INTEGER NOT NULL,  --COMMENT '演出厅编号',
    playId       INTEGER NOT NULL,  --COMMENT '节目编号',
    playName     TEXT    NOT NULL,  --COMMENT '节目名称',
    startTime    INTEGER NOT NULL,  --COMMENT '开始时间',
    endTime      INTEGER NOT NULL,  --COMMENT '结束时间',
    seatId       INTEGER NOT NULL,  --COMMENT '座位编号',
    seatX        INTEGER NOT NULL,  --COMMENT '座位X坐标',
    seatY        INTEGER NOT NULL,  --COMMENT '座位Y坐标',
    price        REAL    NOT NULL,  --COMMENT '价格',
    ticketStatus INTEGER DEFAULT 1, --COMMENT '票状态 0已卖出 1未卖出',
    userId       INTEGER,           --COMMENT '用户编号',
    userName     TEXT,              --COMMENT '用户姓名'
    PRIMARY KEY (ticketId)
); --COMMENT = '票';
CREATE TABLE log
(
    logId      INTEGER NOT NULL, --COMMENT '记录编号',
    ticketId   INTEGER NOT NULL, --COMMENT '票编号',
    scheduleId INTEGER NOT NULL, --COMMENT '计划编号',
    userId     INTEGER NOT NULL, --COMMENT '用户编号'
    playId     INTEGER NOT NULL, --COMMENT '节目编号'
    playName   TEXT    NOT NULL, --COMMENT '节目名称',
    price      REAL    NOT NULL, --COMMENT '价格',
    PRIMARY KEY (logId)
); --COMMENT = '销售记录';