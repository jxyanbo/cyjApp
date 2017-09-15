#ifndef CANOBJ_H
#define CANOBJ_H
#include <stdio.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <linux/socket.h>
#include <linux/can.h>
#include <linux/can/error.h>
#include <linux/can/raw.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <error.h>
#include <time.h>
#include <QObject>
#include <QMutex>

#ifndef AF_CAN
#define AF_CAN 29
#endif

#ifndef PF_CAN
#define AF_CAN AF_CAN
#endif

#define CAN_SFF_MASK 0x000007FFU
#define CAN_EFF_MASK 0x1FFFFFFFU
#define CAN_ERR_MASK 0x1FFFFFFFU

class CANobj : public QObject
{
    Q_OBJECT
public:
    explicit CANobj(QObject *parent = 0);
     bool initCAN(const int portIndex);
     void getMutex(QMutex *mutex);
signals:
    void sigUpdateData(QString);
public slots:
    void slot_on_receiveFrame();
    void slot_on_sendFrame(const int id,const int length,int *data);
    void  slot_on_timeout();
private:
    void extractFrame();
    void printFrame(struct can_frame* frame);
private:
    QMutex* m_pMutex;
    int m_s;
    struct ifreq m_ifr;
    struct sockaddr_can m_addr;
    struct can_frame m_frameSend;
    struct can_frame m_frameRecv;
    struct can_filter m_filter[2];
    struct timeval m_tv;
    fd_set m_rset;
};

#endif // CANOBJ_H