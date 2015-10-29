#include "propellersession.h"

#include <QDebug>

#include "propellerdevice.h"

class PropellerManager;

PropellerSession::PropellerSession(
        const QString & portname, 
        PropellerManager * manager,
        QObject * parent)
    : QObject(parent)
{
    setPortName(portname);
    this->manager = manager;
}

PropellerSession::~PropellerSession()
{

}

const QString & PropellerSession::portName()
{
    return port;
}

void PropellerSession::setPortName(const QString & portname)
{
    port = portname;
}

bool PropellerSession::open()
{
    return manager->open(this, port);
}

void PropellerSession::close()
{
    manager->close(this, port);
}

bool PropellerSession::isOpen()
{
    return manager->isOpen(this, port);
}

bool PropellerSession::clear()
{
    return manager->clear(this, port);
}

bool PropellerSession::setBaudRate(quint32 baudRate)
{
    return manager->setBaudRate(this, port, baudRate);
}

qint64 PropellerSession::bytesToWrite()
{
    return manager->bytesToWrite(this, port);
}

qint64 PropellerSession::bytesAvailable()
{
    return manager->bytesAvailable(this, port);
}

QByteArray PropellerSession::read(qint64 maxSize)
{
    return manager->read(this, port, maxSize);
}

QByteArray PropellerSession::readAll()
{
    return manager->readAll(this, port);
}

bool PropellerSession::putChar(char c)
{
    return manager->putChar(this, port, c);
}

qint64 PropellerSession::write(const QByteArray & byteArray)
{
    return manager->write(this, port, byteArray);
}

quint32 PropellerSession::minimumTimeout()
{
    return manager->minimumTimeout(this, port);
}

void PropellerSession::setMinimumTimeout(quint32 milliseconds)
{
    manager->setMinimumTimeout(this, port, milliseconds);
}

quint32 PropellerSession::calculateTimeout(quint32 bytes)
{
    return manager->calculateTimeout(this, port, bytes);
}

void PropellerSession::useReset(const QString & name, int pin)
{
    manager->useReset(this, port, name, pin);
}

void PropellerSession::useDefaultReset()
{
    manager->useDefaultReset(this, port);
}

bool PropellerSession::reset()
{
    return manager->reset(this, port);
}

int PropellerSession::error()
{
    return manager->error(this, port);
}

QString PropellerSession::errorString()
{
    return manager->errorString(this, port);
}

void PropellerSession::timeOver()
{
    emit timeover();
}

void PropellerSession::writeBufferEmpty()
{
    emit _write_buffer_empty();
}
