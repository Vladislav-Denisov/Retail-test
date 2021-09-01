#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "transport.h"

class Factory {
public:
	static Transport* createTransport(const TransportType type) {
		Transport* transport;
		switch (type) {
		case TransportType::Bike:
			transport = new TransportBike();
			break;
		case TransportType::Scooter:
			transport = new TransportScooter();
			break;
		case TransportType::Car:
			transport = new TransportCar();
			break;
		case TransportType::Bus:
			transport = new TransportBus();
			break;
		default:
			transport = new TransportUnknown();
		}

		return transport;
	}
};

#endif _FACTORY_H_