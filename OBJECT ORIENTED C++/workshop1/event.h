#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

extern unsigned int g_sysClock;

namespace sdds {

	class Event {
		char* description;
		unsigned int time;
	public:
		Event();
		Event(const Event&);
		~Event();
		void display() const;
		void setDescription(const char*);
		Event& operator=(const Event&);
	};
}
#endif // !SDDS_EVENT_H