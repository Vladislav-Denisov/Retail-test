#ifndef _TRANSPORT_H_
#define _TRANSPORT_H_

#include <string>
#include <memory>
#include <sstream>

enum class TransportType {
	Unknown = -1,
	Bike,
	Scooter,
	Car,
	Bus
};

static std::string type2str(const TransportType type) {
	switch (type) {
	case TransportType::Bike:
		return "Bike";
	case TransportType::Scooter:
		return "Scooter";
	case TransportType::Car:
		return "Car";
	case TransportType::Bus:
		return "Bus";
	default:
		throw std::exception("Incorrect type!");
	}
}

class Transport {
public:
	Transport(const Transport&) = delete;
	Transport(const Transport&&) = delete;
	Transport& operator=(const Transport&) = delete;

	virtual std::string getInfo() {
		std::stringstream ss;
		ss << "Transport name: " << getType() << std::endl <<
			  "Wheels count: " << getWheelsCount() << std::endl <<
			  "Max speed: " << getMaxSpeed() << std::endl;
		return ss.str();
	}

	std::string getType() const { return type2str(type); }
	size_t getMaxSpeed() const { return maxSpeed; }
	size_t getWheelsCount() const { return wheelsCount; }

protected:
	Transport() {};

	TransportType type;
	size_t wheelsCount;
	size_t maxSpeed;
};

class TransportBike : public Transport {
public:
	TransportBike() {
		type = TransportType::Bike;
		wheelsCount = 2;
		maxSpeed = 200;
	}
};

class TransportScooter : public Transport {
public:
	TransportScooter() {
		type = TransportType::Scooter;
		wheelsCount = 2;
		maxSpeed = 15;
	}
};

class TransportCar : public Transport {
public:
	TransportCar() {
		type = TransportType::Car;
		wheelsCount = 4;
		maxSpeed = 180;
	}
};

class TransportBus : public Transport {
public:
	TransportBus() {
		type = TransportType::Bus;
		wheelsCount = 4;
		maxSpeed = 100;
	}
};

class TransportUnknown : public Transport {
public:
	TransportUnknown() {
		type = TransportType::Unknown;
		wheelsCount = 0;
		maxSpeed = 0;
	}

	std::string getInfo() override {
		return std::string("UNKNOWN TYPE\n");
	}
};


#endif _TRANSPORT_H_
