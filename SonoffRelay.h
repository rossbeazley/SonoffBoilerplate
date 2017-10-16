class RelayObserver
{
  public:
    virtual void state(int state) = 0;
};


class SonoffRelay
{
  public:
    SonoffRelay(int gpiopin);
    void relayInit(int channel = 0);
    void turnOn(int channel = 0);
    void turnOff(int channel = 0);
    void toggle(int channel = 0);
    int currentState(int channel = 0);
    void attachObserver(RelayObserver *observer);
  private:
    void pokeRelay(int state, int channel = 0);
    const int SONOFF_RELAY_PINS[4] =    {12, 12, 12, 12};
    int _gpiopin;
    //std::vector < class Observer * > views;
    RelayObserver * obs;
    void announce(int state);
};


