#ifndef B1PLUGIN_HH
#define B1PLUGIN_HH

#include "SingleComponentPlugin.hh"
#include "util/ThreadLocal.hh"

#include "B1EventAction.hh"

class B1Plugin : public g4::SingleComponentPlugin
{
public:
    virtual void BuildGeometry(G4LogicalVolume *logVolume) override;

    virtual G4UserRunAction* CreateRunAction() override;

    virtual G4UserEventAction* CreateEventAction() override;

    virtual G4VUserPrimaryGeneratorAction* CreatePrimaryGeneratorAction() override;

private:
    B1EventAction* GetEventAction();

    g4::util::ThreadLocal<B1EventAction> _eventAction;
};

#endif
